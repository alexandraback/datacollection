// Round_1A_1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <deque>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int t;
	
	ifstream ifile;
	
	ofstream ofile;
	ofile.open("ans.txt");
	ifile.open("A-small-attempt0.in");
	//cin >> t;
	ifile >> t;

	for (int n = 1; n <= t; n++)
	{
		string str;
		//cin >> str;
		ifile >> str;
		deque<char> q;

		for (int i = 0; i < str.size(); i++)
		{
			if (q.empty())
				q.push_back(str[i]);
			else
			{
				if (str[i] >= q.front())
					q.push_front(str[i]);
				else
					q.push_back(str[i]);
			}
		}

		ofile << "Case #" << n << ": ";
		for (char c : q)
			ofile << c;
		ofile << endl;
	}
	



    return 0;
}

