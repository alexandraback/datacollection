#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int,long long> State ;

vector <State > a;
vector <State > b;
map<pair<State , State >, long long > dp;

vector <vector <int> > nxta;
vector <vector <int> > nxtb;

long long DP(State A, State B)
{
	if (A.first >= a.size() || B.first >= b.size())
		return 0;
	if (A.second == 0)
	{
		A.first ++;
		if (A.first < a.size())
			A.second = a[A.first].second;
		else
			return 0;
	}
	if (B.second == 0)
	{
		B.first ++;
		if (B.first < b.size())
			B.second = b[B.first].second;
		else
			return 0;
	}
	

	pair<State,State> C (A,B);
	if (dp.count(C))
		return dp[C];
	long long ans = 0;
	if (a[A.first].first == b[B.first].first)
	{
		long long cnt = min(A.second, B.second);
		long long d = DP(make_pair(A.first, A.second -cnt), make_pair(B.first, B.second -cnt));
		ans = max(ans, cnt + d);
	} else  {
		long long d = DP(make_pair(A.first, 0), make_pair(B.first, 0));
		ans = max(ans, d);
		if (nxta[A.first][b[B.first].first] != 1000)
		{
			int nxt = nxta[A.first][b[B.first].first];
			long long d = DP(make_pair(nxt, a[nxt].second), B);
			ans = max(ans, d);
		}
		

		if (nxtb[B.first][a[A.first].first] != 1000)
		{
			int nxt = nxtb[B.first][a[A.first].first];
			long long d = DP(A, make_pair(nxt, b[nxt].second));
			ans = max(ans, d);
		}
		

	}
	return dp[C] = ans;
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc ++) {
		int n,m;
		cin >> n >> m;
		a.resize(n);
		b.resize(m);
		for (int i =0; i < n; ++i) {
			long long x;
			int y;
			cin >> x >> y;
			a[i] = make_pair(y,x);
		}
		for (int i =0; i < m; ++i) {
			long long x;
			int y;
			cin >> x >> y;
			b[i] = make_pair(y,x);
		}
		nxta.assign(n,vector <int> (101, 1000));
		nxtb.assign(m,vector <int> (101, 1000));
		for (int i = n-2; i >= 0; i--)
		{
			nxta[i] = nxta[i+1];
			nxta[i][a[i+1].first] = i+1;
		}
		for (int i = m-2; i >= 0; i--)
		{
			nxtb[i] = nxtb[i+1];
			nxtb[i][b[i+1].first] = i+1;
		}


		dp.clear();
		cout << "Case #" << tc << ": " << DP(make_pair(0,a[0].second), make_pair(0,b[0].second))  << endl;
	}
	return 0;
}