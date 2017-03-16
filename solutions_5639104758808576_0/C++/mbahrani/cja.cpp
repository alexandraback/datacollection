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
#define F first
#define S second

using namespace std;

inline bool ascending (int i, int j) { return (i < j); }
inline bool descending (int i, int j) { return (i > j); }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t, len, tmp, ans;
string s;

#define cin fin
#define cout fout

ifstream fin("A-small-attempt0 (1).in");
ofstream fout("A-small.out");

int main()
{
	cin >> t;
	FR(q, t)
	{
		cin >> len;
		cin >> s;
		ans = tmp = 0;
		FR(i, len + 1)
		{
			if(i > tmp) ans += i - tmp, tmp += i - tmp;
			tmp += (int) s[i] - '0';
		}
		cout << "Case #" << q + 1 << ": " << ans << endl;
	}
	return 0;
}
