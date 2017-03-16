#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <set>
#include <map>

#define show(x) cerr << "# " << #x << " = " << (x) << endl

#define FOR(i, a, b) for(__typeof(a) i = a; i != b; i++)
#define FR(i, a) FOR(i, 0, a)
#define FOREACH(i, t) FOR(i, t.begin(), t.end())
#define ALL(x) (x).begin(), (x).end()
#define SZ(a) int(a.size())
#define PB push_back
#define MP make_pair
#define PQ priority_queue
#define F first
#define S second

using namespace std;

inline bool ascending (int i, int j) { return (i < j); }
inline bool descending (int i, int j) { return (i > j); }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


#define cin fin
#define cout fout


int t, x, r, c;
string ans;


ifstream fin("D-small-attempt0.in");
ofstream fout("D-small.out");


int main()
{
	cin >> t;
	FR(q, t)
	{
		cin >> x >> r >> c;
		if(r*c % x) ans = "RICHARD";
		else
		{
			if(x == 1 || x == 2) ans = "GABRIEL";
			if(x == 3)
			{
				if((r == 1 || c == 1)) ans = "RICHARD";
				else ans = "GABRIEL";
			}
			if(x == 4){
				if(r < 3 || c < 3) ans = "RICHARD";
				else ans = "GABRIEL";
			}
		}
		cout << "Case #" << q + 1 << ": " << ans << endl;
	}
	
	return 0;
}
