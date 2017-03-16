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

ifstream fin("A.in");
ofstream fout("A.out");

void solve(int i)
{
	set<int> chars;
	LL curr = 0;
	while(sz(chars) < 10)
	{
		curr += i;
		int temp = curr;
		while(temp)
		{
			chars.insert(temp % 10);
			temp /= 10;
		}
	}
	fout << curr << "\n";
}

int main()
{
	int t;
	fin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n;
		fin >> n;
		fout << "Case #" << i << ": ";
		if(n == 0)
			fout << "INSOMNIA\n";
		else
			solve(n);
	}
	return 0;
}