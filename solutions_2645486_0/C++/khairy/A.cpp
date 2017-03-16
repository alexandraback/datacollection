#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <list>
#include <set>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <complex>
#include <cmath>
#include <sstream>
#include <deque>
#include <utility>
#include <bitset>
#include <ext/hash_set>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo (1<<30)
#define M 1001
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define iter(it,s) for(it=s.begin();it!=s.end();it++)
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int e, r, n;
vi v;

int memo[20][20];

int rec(int idx, int en) {
	if (idx == n)
		return 0;
	int &res = memo[idx][en];
	if (res != -1)
		return res;
	res = 0;
	FOR (i , 0 , en + 1)
		res = max(res, rec(idx + 1, min(e, en - i + r)) + i * v[idx]);
	return res;
}

int main() {
	freopen("test.in", "rt", stdin);
		freopen("out.txt", "wt", stdout);
	int T;
	scanf("%d", &T);
	FOR (cs, 1 , T + 1) {
		mem (memo, -1);
		scanf("%d%d%d", &e, &r, &n);
		v.clear();
		v.resize(n);
		FOR (i , 0 , n)
			scanf("%d", &v[i]);
		printf("Case #%d: %d\n", cs, rec(0, e));
	}
	return 0;
}
