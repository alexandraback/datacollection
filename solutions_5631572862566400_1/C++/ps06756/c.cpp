#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define cnt(c, x) ((c).find(x) != (c).end())
#define pb push_back
#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int) (x).size())
#define mp(x,y) make_pair((x), (y))
#define mp3(x,y,z) make_pair((x), make_pair( (y), (z)))
#define foreach(C, i) for(auto i = (C).begin(); i != (C).end(); i++)
#define xx first
#define yy second
#define clr clear()
#define var(x) cout<< #x << " = "<<x<<"\n";
#define print(x) for_each((x).begin(), (x).end(), [](auto n) { cout<<x<<" " })
typedef int32_t i3;
typedef int64_t i6;
typedef vector<i3> vi;
typedef pair<i3,i3> ii;
typedef vector<pair<i3,i3> > vii;

int ans = 2;
bool checkIfCorrect(vector<int>& temp, vector<int>& vec)
{
	bool flag = true;
	for(int k = 0; k <  SZ(temp); k++)
	{
		if (vec[temp[k]] != temp[(k+1)%SZ(temp)] && vec[temp[k]] != temp[(k - 1 + SZ(temp))%SZ(temp)])
			flag = false;
	}
	return flag;

}

int dfs(int source, vector<bool>& visited, vector<vector<int> >& vec, int len)
{
		if (!visited[source])
		{
			ans = max(ans, len);
			visited[source] = true;
			foreach(vec[source], it)
				dfs(*it, visited, vec, len + 1);
		}
		return (0);
}

int main()
{
	int tc; cin >> tc;
	FOR(i,1,tc + 1)
	{
		int n; cin >> n;
		vector<vector<int> > vec(n+1);
		REP(i,n)
		{
			int temp; cin >> temp;
			vec[i+1].pb(temp);
			vec[temp].pb(i+1);
		}
		ans = 2;
		for(int j = 1; j <= n; j++)
		{
			vector<bool> visited(n + 1, false);
			dfs(j, visited, vec, 1);
		}
		cout << "Case #"<<i<<": " << ans << "\n";
	}
	return (0);
}
