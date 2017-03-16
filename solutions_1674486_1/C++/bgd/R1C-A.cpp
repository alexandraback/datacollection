#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

#define FOR(i, a, b) for(int i(a); i<b; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
#define CLEAR(x, b) memset(x, b, sizeof(x))
#define SZ(x) x.size();

#define mp make_pair
#define pb push_back

void solve();

int T;

int main()
{
	freopen("R1C-A-L.in", "r", stdin);
	freopen("R1C-A-L.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	
	cin>>T;
	REP(t, T)
	{
		cout<<"Case #"<<t+1<<": ";
		solve();
		cout<<endl;
	}

	fclose(stdout);
}

int N;
bool used[1000];
vi d[1000];

bool dfs(int s)
{
	used[s]=1;
	int n=SZ(d[s]);
	REP(i, n)
	{
		if(used[d[s][i]]) return true;
		else if(dfs(d[s][i])) return true;
	}
	return false;
}

void solve()
{
	cin>>N;

	REP(i, N)
	{
		int M;
		cin>>M;
		d[i].clear();
		REP(j, M)
		{
			int t;
			cin>>t;
			d[i].pb(t-1);
		}
	}
	REP(i, N)
	{
		CLEAR(used, 0);
		if (dfs(i))
		{
			cout<<"Yes";
			return;
		}
	}
	cout<<"No";
}