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

string say[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char det[] = "ZOWHUVXSGE";
int order[] = {0,2,6,8,3,4,7,5,1,9};

void solve()
{
	string s;
	fin >> s;
	int cnt[10] = {0};
	int abc[26] = {0};
	for(int i = 0; i < sz(s); i++)
		abc[ s[i] - 'A' ] += 1;

	for(int i = 0; i < 10; i++)
	{
		int toRemove = order[i];
		cnt[toRemove] = abc[det[toRemove] - 'A'];
		for(int j = 0; j < sz(say[toRemove]); j++)
			abc[ say[toRemove][j] - 'A'] -= cnt[toRemove];
	}


	for(int i = 0; i < 10; i++)
		for(int j = 0; j < cnt[i]; j++)
			fout << i;
	fout << "\n";
}

int main()
{
	int t;
	fin >> t;
	for(int i = 1; i <= t; i++)
	{
		fout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}