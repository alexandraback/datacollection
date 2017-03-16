#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cassert>
#include <cstdarg>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

template<typename T> int size(T& a){ return (int) a.size(); }
template<typename T> T sqr(T a){ return a * a; }

#pragma comment(linker, "/STACK:256000000")

#define _(a, b) memset((a), (b), sizeof(a))
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define REPD(i, a, b) for(int i = (b) - 1; i >= a; --i)

const int MAXN = 110;
const int ANY = int(1e9);
int a[MAXN][MAXN];
int N, M;

bool cmp(pii pa, pii pb) {
	if(a[pa.fs][pa.sc] != a[pb.fs][pb.sc])
		return a[pa.fs][pa.sc] < a[pb.fs][pb.sc];

	return pa < pb;
}

vector<pii> v;

bool check(int x, int y) {
	int diff = 0;
	REP(i, 0, N) {
		if(a[i][y] != ANY && a[i][y] != a[x][y]) diff++;
	}
	if(diff == 0) return true;
	diff = 0;
	REP(j, 0, M) {
		if(a[x][j] != ANY && a[x][j] != a[x][y]) diff++;
	}
	if(diff == 0) return true;

	return false;
}

bool solve() {
	cin >> N >> M;
	REP(i, 0, N) REP(j, 0, M)
		cin >> a[i][j];

	v.clear();
	REP(i, 0, N) REP(j, 0, M) {
		v.pb(mp(i, j));
	}
	sort(v.begin(), v.end(), cmp);

	for(int i = 0, j; i < size(v); i = j) {
		for(j = i; j < size(v) && a[v[j].fs][v[j].sc] == a[v[i].fs][v[i].sc]; j++);

		REP(k, i, j) {
			if(!check(v[k].fs, v[k].sc)) return false;
			a[v[k].fs][v[k].sc] = ANY;
		}
	}

	return true;
}

int main() {                     
#ifdef shindo
	
	if(false) {
		freopen("input.txt", "w", stdout);
		puts("1000");
		REP(i, 0, 1000) {
			printf("1 1");
			REP(j, 0, 100) printf("0");
			printf("\n");
		}
	}

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

	int T;
	scanf("%d\n", &T);
	REP(i, 0, T) {
		printf("Case #%d: ", i + 1);
		puts(solve() ? "YES" : "NO");
	}

	
/*	
#ifdef shindo
	printf("\n-------------\n\n\nWalltime = %.3lf\n", clock() * 1e-3);
#endif
*/
}