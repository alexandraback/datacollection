#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair
#define cin(x)    scanf("%d",&x)
#define MOD		1000000007
#define EPS		1E-10

ifstream fin("C-sample.in");
ofstream fout("C.out");

int main()
{
	int t;
	fin >> t;
	for(int i = 1; i <= t; i++)
	{
		fout << "Case #" << i << ":\n";
		int n,j;
		fin >> n >> j;
		int b = (n - 4) / 2;

		for(int mask = 0; j > 0 && mask < (1 << b); mask++)
		{
			j -= 1;
			string f = "11";
			for(int j = 0; j < b; j++)
			{
				if(mask & (1 << j))
					f += "11";
				else
					f += "00";
			}
			f += "11";
			fout << f;
			for(int base = 2; base <= 10; base++)
				fout << " " << (base + 1);
			fout << "\n";
		}
	}
	return 0;
}