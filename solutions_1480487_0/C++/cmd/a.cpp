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

void solve(int test)
{
	int n; cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	int sum = 0;
	for(int i = 0; i < n; ++i)
		sum += s[i];

	
	vector<int> w = s;
	vector<LD> res(n);
	for(int i = 0; i < n; ++i)
	{
		LD l = 0.0, r = 1.0;
		for(int it = 0; it < 200; ++it)
		{
			LD mid = (l + r) / 2.0;
			LD rem = (1.0 - mid) * sum;
			bool fl = true;
			for(int j = 0; j < n; ++j) if(i != j)
			{
				LD w = (s[i] + sum * mid - s[j]);
				if(w < 0) {
				   w = 0;
				}
				rem -= w;
			}
			
			if(rem > eps)
				l = mid;
			else
				r = mid;
		}
		res[i] = r * 100.0;
	}
	cout << "Case #" << test << ":";
	cout.precision(9);
	cout.setf(ios::fixed);
	for(int i = 0; i < n; ++i)
		cout << " " << res[i];
	cout << endl;
	
}
int main()
{
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin);freopen(NAME ".out","w",stdout);

	int tt; cin >> tt;
	for(int t = 1; t <= tt; ++t)
		solve(t);

	return 0;
}
/*************************
*************************/
#endif
