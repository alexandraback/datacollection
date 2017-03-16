#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = numeric_limits<int>::max();
const ll M = 1000000007;

const int nmax = 105;
string s[nmax];
int interior[256];
char in[256], out[256];
bool cinner[256], cleft[256], cright[256], cexists[256];
ll fact[nmax];
bool vis[256];


int n;

bool valid(const string& x)
{
	bool seen[256];
	memset(seen, false, sizeof(seen));
	for(int i=0;i<x.size();i++)
	{
		if(seen[x[i]] && x[i-1] != x[i])
			return false;
		seen[x[i]] = true;
	}
	return true;
}

int go()
{
	memset(interior, 0, sizeof(interior));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	memset(cinner, false, sizeof(cinner));
	memset(cleft, false, sizeof(cleft));
	memset(cright, false, sizeof(cright));
	memset(cexists, false, sizeof(cexists));
		
	for(int i=0;i<n;i++)
	{
		if(!valid(s[i]))
			return 0;
		for(char ch : s[i])
			if(cinner[ch])
				return 0;
			
		char a = s[i][0];
		char b = s[i][s[i].size()-1];
		if(a == b)
		{
			interior[a]++;
		}
		else
		{
			if(cleft[a])
				return 0;
			cleft[a] = true;
			if(cright[b])
				return 0;
			cright[b] = true;
			for(char ch : s[i])
				if(ch != a && ch != b)
				{
					if(cexists[ch])
						return 0;
					cinner[ch] = true;
				}

			assert(!in[b]);
			assert(!out[a]);
			in[b] = a;
			out[a] = b;
		}

		for(char ch : s[i])
			cexists[ch] = true;
	}

	ll ans = 1;
	for(char ch = 'a'; ch <= 'z'; ch++)
		ans = (ans * fact[interior[ch]]) % M;

	int chains = 0;
	memset(vis, false, sizeof(vis));
	for(char ch = 'a'; ch <= 'z'; ch++)
		if(in[ch] == 0 && out[ch] != 0)
		{
			chains++;
			for(char i = ch; ; i = out[i])
			{
				assert(!vis[i]);
				vis[i] = true;
				if(out[i] == 0)
					break;
			}
		}
		else if(in[ch] == 0 && out[ch] == 0 && interior[ch] > 0)
		{
			chains++;
			vis[ch] = true;
		}
	for(char ch = 'a'; ch <= 'z'; ch++)
		if(in[ch] != 0 || out[ch] != 0)
			if(!vis[ch])
			{
				return 0;
			}

	ans = (ans * fact[chains]) % M;
	return ans;
}

int main(int argc,char* argv[])
{
	fact[0] = 1;
	for(int i=1;i<nmax;i++)
		fact[i] = (fact[i-1] * i) % M;
	
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> s[i];

		printf("Case #%d: %d\n", test_case, go());
	}
	return 0;
}
