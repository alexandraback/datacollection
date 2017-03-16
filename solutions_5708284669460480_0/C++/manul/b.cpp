#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
#include<map>

#define forn(i, n)	for(int i = 0; i < n; i++)
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>a
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int md = 1000000007;
const int maxn = 101010;
const int maxn4 = 4 * maxn;
const ll inf = 2020202020202020202LL;

int prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi[n - 1];
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
int t;
cin>>t;
forn(it, t)
{
	int k, l, s;
	cin>>k>>l>>s;
	int num[26];
	double p[26];
	forn(i, 26)
		p[i] = num[i] = 0;
	string key, pay;
	cin>>key>>pay;
	forn(i, key.size())
		num[key[i] - 'A']++;
	forn(i, 26)
	{
		double d = num[i];
		double e = key.size();
		p[i] = d / e;
	}
	vector<vector<int> > mpp(pay.size() + 1);
	forn(i, mpp.size())
	{
		mpp[i].resize(26);
		forn(j, 26)
			{
				string g;
				forn(k, i)
					g.push_back(pay[k]);
				g.push_back('A' + j);
				string u = pay + '#' + g;
				mpp[i][j] = prefix_function(u);
			}
	}
	vector < vector < double > > dp(s + 1);
	vector < vector < double > > v(s + 1);
	forn(i, s + 1)
	{
		dp[i].resize(mpp.size());
		v[i].resize(mpp.size());
	}
	v[0][0] = 1;
	for (int i = 1; i <= s; i++)
	{
		forn(j, mpp.size())
		{
			forn(k, 26)
			{
				v[i][mpp[j][k]] += v[i-1][j] * p[k];
				dp[i][mpp[j][k]] += dp[i - 1][j] * p[k];
			}
		}
		dp[i][pay.size()] = dp[i][pay.size()] +v[i][pay.size()];
	}
	double exp = 0;
	forn(j, mpp.size())
		exp = exp + dp[s][j];
	int z = l - prefix_function(pay);
	int h = s / z;
	int f = l / z;
	int red = h - f + 1;
	double r = red;
	r = r - exp;
	cout.precision(8);
	int uu=1;
	forn(i, pay.size())
		if (p[pay[i] - 'A'] == 0)
			uu = 0;
	if (!uu)
		r = 0;
	cout<<"Case #"<<it + 1<<": "<<fixed<<r<<endl;
}
	return 0;
}
