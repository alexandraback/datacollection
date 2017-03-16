#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>


using namespace std;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

const int maxQSize = (int)1e7;
pii st[maxQSize];

const int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const char goChars[5] = "NSEW";

map<pii, pii> dist;

void getPath(char *res, pii v) {
	int n = 0;
	for (;;) {
		//eprintf("(%d, %d)\n", v.first, v.second);
		assert(dist.count(v));
		pii cur = dist[v];
		//eprintf("cur.first = %d\n", cur.first);
		if (cur.second == -1)
			break;
		res[n++] = goChars[cur.second];
		pii rem(go[cur.second][0] * cur.first, go[cur.second][1] * cur.first);
		v.first -= rem.first, v.second -= rem.second;
	}
	res[n] = 0;
	reverse(res, res + n);           
}

char res[maxQSize + 1];


void solve(int &testCase) {
	int endX, endY;
	scanf("%d%d", &endX, &endY);
	dist.clear();
	int r = 0;
	st[r++] = mp(0, 0);
	dist[st[0]] = mp(0, -1);
	int ans = -1;
	for (int l = 0; ans == -1 && l < r; l++) {
		int y = st[l].first, x = st[l].second;
		int cdist = dist[st[l]].first;
		//eprintf("cdist = %d\n", cdist);
		for (int g = 0; g < 4; g++) {
			int yn = y + go[g][0] * (cdist + 1), xn = x + go[g][1] * (cdist + 1);	
			if (dist.count(mp(yn, xn)))
				continue;
			assert(r < maxQSize);
			st[r++] = mp(yn, xn);
			dist[st[r - 1]] = mp(cdist + 1, g);
			if (yn == endY && xn == endX) {
				ans = cdist + 1;
				break;
			}
		}
	}
	assert(ans != -1);
	assert(ans <= maxH);

	eprintf("ans = %d\n", ans);
	getPath(res, mp(endY, endX));
	assert(ans == (int)strlen(res));
	printf("Case #%d: %s\n", ++testCase, res);
}

int main() {
	srand(rdtsc());
#ifdef DEBUG
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif
	
	int testCase = 0;
	int n;
	while (scanf("%d", &n) >= 1) {
		for (int test = 0; test < n; test++)
			solve(testCase);
		//break;
	}
	return 0;
}
