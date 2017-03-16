#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 1000000007
#define LL long long
using namespace std;

LL pot[101];
LL f[26];

LL find(LL x) 
{
	if(f[x] != x)f[x] = find(f[x]);
	return f[x];
}

void __union(LL x, LL y)
{
	f[find(f[y])] = find(f[x]);
}

void solve()
{
	string s[101];
	vector<string> vs[26];
	LL bef[26] = {-1}, wyn[26] = {0}, gwyn[26], inslets[26];
	LL n;
	cin >> n;
	for(LL i = 0; i < n; i++)
	{
		cin >> s[i];
		vs[s[i][0]-'a'].push_back(s[i]);
		
	}
	for(int i = 0; i < 26; i++)inslets[i] = 0;
	for(int j = 0; j < 101; j++)
	{
		string x = s[j];
		if((int)x.size() > 2)for(int i = 1; i < (int)x.size()-1; i++)
		{
			if((x[i] != x[i-1] && x[i] != x[x.size()-1])) inslets[x[i]-'a']++; 
			else if (x[i] != x[0] && x[i] != x[i+1]) inslets[x[i]-'a']++; 
		}
	}
	for(int i = 0; i < 26; i++)
	{
		if(inslets[i] && vs[i].size())
		{
			cout << '0' << endl;
			return;
		}
	}
	for(LL i = 0; i < 26; i++)
	{
		bef[i] = -1;
		f[i] = i;
		gwyn[i] = 1;
		for(string &x : vs[i])
		{
			if(x[x.size()-1] != x[0])
			{
				if(bef[i] == -1)bef[i] = x[x.size()-1]-'a';
				else
				{
					cout << 0 << endl;
					return;
				}
			}
		}	
	}
	for(LL i = 0; i < 26; i++)
	{
		if(bef[i] != -1 && bef[bef[i]] == i)
		{
			cout << '0' << endl;
			return;
		}
	}
	
	for(LL i = 0; i < 26; i++)
	{
		if(bef[i] != -1)
		{
			if(vs[i].size() <= 2)wyn[i] = 1;
			else wyn[i] = pot[(vs[i].size() - 2)];
			__union(i, bef[i]);
		}
		else if(vs[i].size() >= 2)wyn[i] = pot[vs[i].size()] % MOD;
		else if(vs[i].size() != 0)wyn[i] = 1;
	}

	for(LL i = 0; i < 26; i++)
	{
		find(i);
		gwyn[f[i]] = (gwyn[f[i]]*wyn[i])%MOD;
	}
	LL x = 0, wyns = 1;
	for(LL i = 0; i < 26; i++)
	{
//		if(vs[i].size())cout << i << ' ' << f[i] << ' ' << wyn[i] << ' ' << gwyn[i] << endl;
		if(gwyn[f[i]])
		{
			wyns = (wyns*gwyn[f[i]])%MOD;
			gwyn[f[i]] = 0;
			x++;
		}
	}
	wyns = (wyns*pot[x])%MOD;
	cout << wyns << endl;
}

int main()
{
	pot[1] = 1;
	for(int i = 2; i <= 100; i++)pot[i] = pot[i-1]*i;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)cout << "Case #" << i << ": ", solve();
}
