// 1Aa.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

unsigned long int solve(char* name, int n);

//#define TESTING
#define L 1000001

int main()
{
	int T;
	char strBuff[50];
	char name[L];
	int n;
	


	ifstream fin;
	fstream fout;
#ifdef TESTING
	fin.open("example.txt", ifstream::in);
#else
	fin.open("A.txt", ifstream::in);
#endif

	fout.open("Output.txt", fstream::out);

	fin.getline(strBuff, 10);

	sscanf(strBuff, "%d", &T);

	for (int i = 0; i < T; i++)
	{
		fout << "Case #" << (i+1) << ": ";

		fin.getline(name, L, ' ');
		fin.getline(strBuff, 10);

		sscanf(strBuff, " %d", &n);

		fout << solve(name, n) << "\n";

	}
	fout.close();

#ifdef TESTING
	fout.open("Output.txt", fstream::in);
	char cmpStrBuff[50];

	fin.seekg(1, ios_base::cur);//go past the tab
	fout.flush();
	fout.seekg(ios_base::beg);

	for (int i = 0; i < T; i++)
	{
		fin.getline(strBuff, 50);
		fout.getline(cmpStrBuff, 50);
		if (strcmp(strBuff, cmpStrBuff))
		{
			printf("Test failed:\n%s\n%s\n", strBuff, cmpStrBuff);
		}
	}

	printf("All tests completed\n");
	cin.get();

#endif


	fout.close();
	
	fin.close();
}

unsigned long int solve (char* name, int n)
{
	unsigned long int val = 0;
	int l = strlen(name);
	int cons = 0;
	int lastSubs = -1;

	for (int i = 0; i < l; i++)
	{
		if (name[i] != 'a' && name[i] != 'e' && name[i] != 'i' && name[i] != 'o' && name[i] != 'u')
		{
			cons++;
			if (cons >= n)
			{
				//figure out how many substr
				int before = i - lastSubs - n + 1;
				int after = l - i;
				val += (before * after);
				lastSubs = i - n + 1;
			}
		}
		else
		{
			cons = 0;
		}
	}

	return val;
}