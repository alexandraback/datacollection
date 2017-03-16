#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); (i) <= (b); ++(i))
#define mp make_pair
#define inf 2000000000
#define pb push_back
#define X first
#define Y second
#define LL long long
const double eps = 0.0000000001;

vector<int> gr[1010];
int used[1010];
int b[1002][1002];
int n;
bool ok;

void dfs(int v,int t, int p)
{
	b[t][v] = 1;
	for (size_t j = 0; j < gr[v].size(); ++j)
	{
		int to = gr[v][j];
		if (to == p) continue;
		++b[t][to];
		if (b[t][to] == 1)
			dfs(to,t,v);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin >> T;
	FOR(test,1,T)
	{
		cin >> n;
		FOR(i,1,n)
		{
			gr[i].clear();
		}

		FOR(i,1,n)
			FOR(j,1,n)
			b[i][j] = 0;

		FOR(i,1,n)
		{
			int cnt;
			cin >> cnt;
			FOR(j,1,cnt)
			{
				int x;
				cin >> x;
//				gr[i].pb(x);
				gr[x].pb(i);
			}
		}

		FOR(i,1,n)
		{
			dfs(i,i,-1);
		}
		ok = false;
		FOR(i,1,n)
			FOR(j,1,n)
			if (b[i][j] >= 2)
			{
				ok= true;
				break;
			}
		cout<<"Case #"<<test<<": "<<((ok) ? "Yes\n" : "No\n");
		
			
	}	
    return 0;
}