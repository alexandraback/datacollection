#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("D-large.in");
	if (fin.is_open())
	{
		ofstream fout;
		fout.open("D-large.out");
		int T;
		fin >> T;
		for (int i = 0; i < T; i++)
		{
			int K, C,S;
			fin >> K;
			fin >> C;
			fin >> S;
			cout << "Case #" << i + 1 << ":";
			fout << "Case #" << i + 1 << ":";
			if (S*C < K)
			{
				cout << " IMPOSSIBLE" << endl;
				fout << " IMPOSSIBLE" << endl;
			}
			else
			{
				for (int j = 0; j < K; j += C)
				{
					unsigned long long n = 1;
					unsigned long long  k = 1;
					for (int l = j + C - 1; l >= j; l--)
					{
						if (l < K) n += k*l;
						k *= K;
					}
					cout << " " << n;
					fout << " " << n;
				}
				cout << endl;
				fout << endl;
			}
		}
		fin.close();
		fout.close();
	}
	return 0;
}