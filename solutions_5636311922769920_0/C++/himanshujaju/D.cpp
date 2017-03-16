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

ifstream fin("D-small.in");
ofstream fout("D.out");

int main()
{
	int t;
	fin >> t;
	for(int i = 1; i <= t; i++)
	{
		fout << "Case #" << i << ": ";
		int k,c,s;
		fin >> k >> c >> s;
		if(k == s)
		{
			for(int i = 1; i <= s; i++)
				fout << i << " ";
			fout << "\n";
		}
	}
	return 0;
}