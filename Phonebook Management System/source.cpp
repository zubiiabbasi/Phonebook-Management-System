#include <iostream>
#include <fstream>
using namespace std;
void add_employe(ifstream& fin);
void search_empolye_by_id(ifstream& fin);
void search_empolye_by_first_name(ifstream& fin);
void delete_employe(ifstream& fin);
int main()
{
	ifstream fin;
	char repeat = 'y';
	do
	{
		int choice = -1;
		cout << "1. Add Empolye record in the file" << endl;
		cout << "2. Search Empolye record by ID" << endl;
		cout << "3. Search Empolye record by First name" << endl;
		cout << "4. Delete Empolye record by ID" << endl;
		cout << endl;
		cout << "Input your desire option: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			add_employe(fin);
			break;
		}
		case 2:
		{
			search_empolye_by_id(fin);
			break;
		}
		case 3:
		{
			search_empolye_by_first_name(fin);
			break;
		}
		case 4:
		{
			delete_employe(fin);
			break;
		}
		default:
		{
			cout << "You have enter invalid option" << endl;
		}
		}
		cout << "Do you want to run again (y/n): ";
		cin >> repeat;
		cout << endl;
	} while (repeat == 'y');
	cout << "you have exited the program" << endl;
	return 0;
}
void add_employe(ifstream& fin)
{
	fin.open("data.txt");
	if (fin.is_open())
	{
		int id = 0;
		char f_name[10], l_name[10], header[1000];
		fin.getline(header, 1000);
		long long number = 0;
		ofstream fout;
		fout.open("edited.txt");
		fout << header << endl;
		while (!fin.eof())
		{
			fin >> id >> f_name >> l_name >> number;
			fout << id << "		    " << f_name << "		  " << l_name << "		   " << 0 << number << endl;
		}
		cout << "Enter Empolye 4 digit ID: ";
		cin >> id;
		cout << "Enter Empolye First Name: ";
		cin >> f_name;
		cout << "Enter Empolye Last Name: ";
		cin >> l_name;
		cout << "Enter Empolye 11 digit Contact Number: ";
		cin >> number;
		fout << id << "		    " << f_name << "		  " << l_name << "		   " << 0 << number;
		cout << "Empolye record is inserted " << endl;
		fin.close();
		fout.close();
		remove("data.txt");
		rename("edited.txt", "data.txt");
	}
	else
	{
		cout << "Error" << endl;
	}
	return;
}
void search_empolye_by_id(ifstream& fin)
{
	fin.open("data.txt");
	if (fin.is_open())
	{
		int id = 0, search = 0;
		char f_name[10], l_name[10], header[1000];
		fin.getline(header, 1000);
		long long number = 0;
		bool notfound = 0;
		cout << "Enter Empolye ID to search record: ";
		cin >> search;
		cout << endl;
		cout << header << endl;
		while (!fin.eof())
		{
			fin >> id >> f_name >> l_name >> number;
			if (search == id)
			{
				cout << id << "		    " << f_name << "		  " << l_name << "		   " << 0 << number << endl;
				notfound = 1;
				break;
			}
		}
		if (notfound == 0)
		{
			cout << "Empolyee Id is not found " << endl;
		}
		fin.close();
	}
	else
	{
		cout << "Error" << endl;
	}
	return;
}
void search_empolye_by_first_name(ifstream& fin)
{
	fin.open("data.txt");
	if (fin.is_open())
	{
		int id = 0;
		char f_name[10], l_name[10], header[1000], search[10];
		fin.getline(header, 1000);
		long long number = 0;
		bool found = 0;
		cout << "Enter First Name of Empolye to search record: ";
		cin >> search;
		cout << endl;
		cout << header << endl;
		while (!fin.eof())
		{
			fin >> id >> f_name >> l_name >> number;
			for (int i = 0; search[i] != '\0'; i++)
			{
				if (search[i] == f_name[i])
				{
					found = 1;
					break;
				}

			}
		}
		if (found == 1)
		{
			cout << id << "		    " << f_name << "		  " << l_name << "		   " << 0 << number << endl;
		}
		else
		{
			cout << "Empolye not found" << endl;
		}
		fin.close();
	}
	else
	{
		cout << "Error" << endl;
	}
	return;
}
void delete_employe(ifstream& fin)
{
	fin.open("data.txt");
	if (fin.is_open())
	{
		int id = 0, search = 0;
		char f_name[10], l_name[10], header[1000];
		fin.getline(header, 1000);
		long long number = 0;
		cout << "Enter Empolye ID to delete record: ";
		cin >> search;
		ofstream fout;
		fout.open("edited.txt");
		fout << header << endl;
		while (!fin.eof())
		{
			fin >> id >> f_name >> l_name >> number;
			if (search == id)
			{
				cout << "Emoplee data has been removed" << endl;
				continue;
			}
			fout << id << "		    " << f_name << "		  " << l_name << "		   " << 0 << number << endl;
		}
		fin.close();
		fout.close();
		remove("data.txt");
		rename("edited.txt", "data.txt");
	}
	else
	{
		cout << "Error" << endl;
	}
	return;
}