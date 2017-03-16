#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include <fstream>

#define MAXN 151
#define MAXL 41

using namespace std;

int T, N;

long long gcd(long long a, long long b);

int main()
{
	string filename = "A-large";
	ifstream fin(filename + ".in");
	FILE *fout = fopen((filename + ".out").c_str(), "w");

	fin >> T;
	for(int t = 1; t <= T; t++)
	{
		long long num, den;
		char slash;
		fin >> num >> slash >> den;

		long long gcdV;
		while((gcdV = gcd(num, den)) > 1)
		{
			num /= gcdV;
			den /= gcdV;
		}

		long long mNum = 1LL << 40;
		long long tDen = den, tNum = num;
		for(int i = 0; i < 40; i++) {
			if(tDen % 2 == 0) {
				tDen /= 2;
			}
			else {
				tNum *= 2;
				if(tNum > mNum) {
					break;
				}
			}
		}

		if((tDen != 1) || (tNum > mNum)) {
			fprintf(fout, "Case #%d: %s\n", t, "impossible");
		}
		else {
			int p = 0;
			do
			{
				p++;
				if(den % 2 == 0) {
					den /= 2;
				}
				else {
					num *= 2;
				}
			}
			while((num * 1.0 / den) < 1.0);

			fprintf(fout, "Case #%d: %d\n", t, p);
		}
		// printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	}

	fin.close();
	fclose(fout);
 	return 0;
}

long long gcd(long long a, long long b)
{
	while(b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}