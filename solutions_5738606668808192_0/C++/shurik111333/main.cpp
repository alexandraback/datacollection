#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ofstream fout("out.txt");

string s[] = {"0000", "1001", "1111"};
int d[] = {3, 2, 5, 2, 7, 2, 3, 2, 11};
int ans[4] = {};
int J = 50;
int n = 16;

void printAns()
{
	for (int i = 0; i < 4; i++)
		fout << s[ans[i]];
}

void printd()
{
	for (int i = 0; i < 9; i++)
		fout << d[i] << " ";
}

void print()
{
	printAns();
	fout << " ";
	printd();
	fout << "\n";
}

int main()
{
	fout << "Case #1:\n";
	int count = 0;
	for (int j = 0; j < 4; j++)
	{
		ans[0] = (j % 2) + 1;
		ans[3] = (j / 2) + 1;
		for (int i = 0; i < 9; i++)
		{
			int i1 = i;
			for (int q = 1; q < (n / 4 - 1); q++)
			{
				ans[q] = i1 % 3;
				i1 /= 3;
			}
			print();
			count++;
			if (count == J)
				return 0;
		}
		for (int i = 1; i < (n - 12); i++)
		{
			for (int k = 1; k < 3; k++)
			{
				fout << s[ans[0]];
				for (int q = 0; q < i; q++)
					fout << "0";
				fout << s[k];
				for (int q = 0; q < n / 4 - i; q++)
					fout << "0";
				fout << s[ans[3]] << " ";
				printd();
				fout << "\n";
				count++;
				if (count == j)
					return 0;
			}
		}
	}
	return 0;
}
