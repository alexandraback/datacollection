#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll getAns(ll n)
{
	bool u[10] = {};
	int count = 0;
	int d = n;
	while (count < 10)
	{
		if (n > 1e12)
			throw 1;
		ll n1 = n;
		while (n1 > 0)
		{
			int a = n1 % 10;
			if (!u[a])
				count++;
			u[a] = true;
			n1 /= 10;
		}
		n += d;
	}
	return n - d;
}

ifstream fin("in.in");
ofstream fout("out.txt");

int main(int argc, char *argv[])
{
	int t;
	fin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		fin >> n;
		fout << "Case #" << i + 1 << ": ";
		if (n == 0)
			fout << "INSOMNIA";
		else
			fout << getAns(n);
		fout << "\n";
	}
	return 0;
}
