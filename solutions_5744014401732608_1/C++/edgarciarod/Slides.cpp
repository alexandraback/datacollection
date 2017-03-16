#include <bits/stdc++.h>
using namespace std;
//look at my code my code is amazing
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FOREACH(it, a) for (typeof(a.begin()) it = (a).begin(); it != (a).end(); it++)
#define ROF(i, a, b) for (int i = int(a); i >= int(b); i--)
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define ALL(x) x.begin(), x.end()
#define MP(a, b) make_pair((a), (b))
#define X first
#define Y second
#define EPS 1e-9
#define DEBUG(x)   cerr << #x << ": " << x << " "
#define DEBUGLN(x) cerr << #x << ": " << x << " \n"
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<bool> vb;
//ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
//cin.tie(NULL); cout.tie(NULL);

int n, m;
ll v[60];
ll numpaths[60];
bool solved = false;
int caso=0;

void bt(const int pos)
{
	const int k = n-pos-1;

	if(pos == n-1 and numpaths[pos] == m)
	{
		cout << "Case #" << ++caso << ": POSSIBLE\n";

		REP(i, n)
		{
			REP(j, n)
			{
				if( v[i] & (1LL<<j) )
					cout << '1';
				else
					cout << '0';
			}
			cout << '\n';
		}

		solved = true;

		return;
	}


	for(ll bs = 0; bs < (1LL<<k) and (not solved); bs++)
	{
		bool flag = false;
		v[pos] = (bs<<(ll)(pos+1LL));
		for(int i=0; i<k; i++)
		{
			if(bs & (1LL<<i))
			{
				numpaths[pos+i+1] += numpaths[pos];

				if(numpaths[pos+i+1] > m)
					flag = true;
			}
		}


		if(not flag)
			bt(pos+1);

		for(int i=0; i<k; i++)
		{
			if(bs & (1LL<<i))
			{
				numpaths[pos+i+1] -= numpaths[pos];
			}
		}		
	}
}

void solve()
{
	memset(numpaths, 0, sizeof numpaths);
	solved = false;

	cin >> n >> m;

	numpaths[0] = 1;

	bt(0);

	if(not solved)
		cout << "Case #" << ++caso << ": IMPOSSIBLE\n";
}

int main()
{
	int T;

	cin >> T;

	REP(i, T)
		solve();

	return 0;
}