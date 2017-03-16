#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
string solve( char a[1100])
{
	string b,c;
	for (int i = 0; i < strlen(a);i++)
	if (i == 0)
		 b.push_back(a[i]);
	else
	{
		if (a[i]>=b[0])
		{
			c.clear();
			c.push_back(a[i]);
			c = c.append(b);
			b = c;
		}
		else
			b.push_back(a[i]);
	}
	return b;
}

int main()
{
	ofstream fout("out.txt");
	ifstream fin("in.txt");

	//	ofstream fout1("in.txt");
	//	fout1 << 1000000 << endl;
	//	for (int i = 0; i < 1000000; i++)
	//		fout1 << i << endl;
	int test_cases;
	fin >> test_cases;
	int num123 = 1;
	while (test_cases--)
	{
		int abc;
		fin >> abc;
		int a[2600];
		for (int i = 0; i < 2600; i++)
			a[i] = 0;

		
		int d;

		for (int i = 0; i < abc*(2 * abc - 1); i++)
		{
			fin >> d;
			a[d]++;
		}
		fout << "Case #" << num123 << ": ";
		for (int i = 0; i < 2600;i++)
		if (a[i] != 0 && a[i] % 2 == 1)
			fout << i << " ";
		fout << endl;
		int out123 = 0;
		num123++;
	}
	return 0;
}