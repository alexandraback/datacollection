#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cassert>
#include <unordered_map>


using namespace std;
typedef long long ll;
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define EPS 1E-9
#define INF 1E12
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

typedef pair<int, int> PII;

ll power(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1ll) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
ll toll(string x)
{
	ll ans = 0;
	for (char v : x)
	{
		ans = ans * 10 + v - '0';
	}
	return ans;
}

int dist[1000005];

int main()
{
	int t;
	cin >> t;

	for (int i = 1; i < 1000005; i++) dist[i] = 2000005;
	queue<int> Q;
	vector<bool> inQ(1000005, 0);
	inQ[1] = 1;
	dist[1] = 1;
	Q.push(1);
	while (!Q.empty())
	{
		int u = Q.front(); Q.pop();
		inQ[u] = 0;
		char r[50];
		sprintf(r, "%d", u);
		string s(r);
		reverse(s.begin(), s.end());
		int x = toll(s);
		
		if (x < 1000005 && dist[u] + 1 < dist[x])
		{
			dist[x] = dist[u] + 1;
			if (!inQ[x])
			{
				Q.push(x);
				inQ[x] = 1;
			}
		}

		x = u + 1;
		if (x < 1000005 && dist[u] + 1 < dist[x])
		{
			dist[x] = dist[u] + 1;
			if (!inQ[x])
			{
				Q.push(x);
				inQ[x] = 1;
			}
		}
	}


	for (int cs = 1; cs <= t; cs++)
	{
		printf("Case #%d: ", cs);
		ll n;
		cin >> n;
		cout << dist[n]<<endl;
	}
	

	return 0;
}