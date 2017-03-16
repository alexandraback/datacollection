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
const int maxn = 30;
const int maxn4 = 4 * maxn;
const ll inf = 2020202020202020202LL;

int dp[23][23];
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
int t;
cin>>t;
forn(i, 23)
	forn(j, 23)
{
	if (j == 0)
		dp[i][j] = 0;
	if (i < j)
		dp[i][j] = -1;
	if (i == j)
		dp[i][i] = i;
}
for(int i = 1; i < 23; i++)
	for(int j = 1; j < 23; j++)
{
	if (j == 1)
	{
		dp[i][j] = i;
		continue;
	}
	if (i >= j)
	{
		dp[i][j] = max(dp[i - j][j], dp[min(2 * j - 2, i - 1)][j - 1]) + 1;
	}
}
forn(it, t)
{
	int r, c, w;
	cin>>r>>c>>w;
	cout<<"Case #"<<it + 1<<": "<<dp[c][w]<<endl;
}
	return 0;
}
