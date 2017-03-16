#if 1
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <sstream>
#include <iostream>
#include <bitset>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int , int> pii;
typedef vector <int> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbgv(x) {cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

LL xabs(LL a) { return a < 0 ? -a : +a; }
void solve(int test)
{
	int n; cin >> n;
	vector<LL> w(n);
	for(int i = 0; i < n; ++i)
		cin >> w[i];

	sort(w.rbegin(), w.rend());
	vector<LL> r;
	for(int i = 0; i < w.size(); ++i)
		if(rand() & 1)
			r.pb(w[i]);
	w = r;
	for(int i = 0; i < 10000; ++i)
	{

		vector<LL> l, r;
		LL s1 = w[0], s2 = 0;
		l.pb(w[0]);
		vector<int> used(n);
		used[i] = true;
		while(true)
		{
			bool fl = false;

			int wh = -1;
			int to = -1;
			LL best = xabs(s1 - s2);
			if(s1 < s2)
			{
				for(int i = 0; i < w.size(); ++i)
				{
					int j = rand() % w.size();
					if(used[j])
						continue;
					s1 += w[j];
					l.pb(w[j]);
					used[j] = true;
					fl = true;
					break;
				}
			} else if(s2 < s1)
			{
				for(int i = 0; i < w.size(); ++i)
				{
					int j = rand() % w.size();
					if(used[j])
						continue;
					s2 += w[j];
					r.pb(w[j]);
					used[j] = true;
					fl = true;
					break;
				}				
			}

			if(!fl)
				break;
		}
		if(s1 == s2 && s1 > 0)
		{
			cout << "Case #" << test << ":" << endl;
			for(int i = 0; i < l.size(); ++i)
			{
				if(i) cout << " ";
				cout << l[i];
			}
			cout << endl;
			for(int i = 0; i < r.size(); ++i)
			{
				if(i) cout << " ";
				cout << r[i];
			}
			cout << endl;
			return;
		}
		random_shuffle(w.begin(), w.end());		
	}
	cout << "Case #" << test << ": Impossible" << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin);freopen(NAME ".out","w",stdout);

	int tt; cin >> tt;
	for(int t = 1; t <= tt; ++t) solve(t);
	

	return 0;
}
/*************************
*************************/
#endif
