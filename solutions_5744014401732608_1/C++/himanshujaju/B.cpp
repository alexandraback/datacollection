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

LL val[50];

ifstream fin("B.in");
ofstream fout("out.txt");

int main()
{
	val[0] = 0;
	val[1] = 1;
	for(int i = 2; i <= 50; i++)
		for(int j = 0; j < i; j++)
			val[i] += val[j];
	int t;
	fin >> t;
	for(int ii = 1; ii <= t; ii++)
	{
		LL n,m;
		fin >> n >> m;
		fout << "Case #" << ii << ": ";
		if(val[n] >= m)
		{
			fout << "POSSIBLE\n";
			vector<string> arr(n);
			for(int i = 0; i < n; i++)
				arr[i] = string(n,'0');
			n--;
			for(int i = 0; i < n; i++)
				for(int j = i + 1; j < n; j++)
					arr[i][j] = '1';
			n += 1;
			for(int i = n - 1; i > 0; i--)
			{
				if(m >= val[i])
				{
					m -= val[i];
					arr[i - 1][n - 1] = '1';
				}
			}
			for(int i = 0; i < n; i++)
				fout << arr[i] << "\n";
		}
		else
		{
			fout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}