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
		char a[1100] = { 0 };
		fin >> a;
		string b;
		b = solve(a);
		fout << "Case #" << num123 << ": " << b;

		fout << endl;
		int out123 = 0;
		num123++;
	}
	return 0;
}