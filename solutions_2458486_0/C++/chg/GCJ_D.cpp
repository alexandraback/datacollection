#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define foreach(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define sqr(x) ((x)*(x))
#define clr(a, b) memset(a, b, sizeof(a))
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
#define all(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
int dcmp(double x) { if (x < -eps) return -1; else return x > eps;}
#define se(x) cout<<#x<<" = "<<x<<endl

const int N = 1 << 20;
vi dp[N];
int cnt[N];
int need[22];
int flag[N];
vi have[22];
vi ikey;
map<int, int> kmap;
int n, k;

void init() {
	cnt[0] = 0;
	forn (i, 1 << 20)
		cnt[i] = cnt[i >> 1] + (i & 1);
}

void calcKey(int key[], int st) {
	forn (i, 30)
		key[i] = 0;
	forn (i, SZ(ikey))
		key[ikey[i]]++;
	forn (i, n) if ((1 << i) & st) {
		key[need[i]]--;
		forn (j, SZ(have[i])) {
			key[have[i][j]]++;
		}
	}
}

void resetKey() {
	kmap.clear();
	int mark = 0;
//	printf("need: ");
	forn (i, n) {
		if (kmap.find(need[i]) == kmap.end()) {
			kmap[need[i]] = mark++;
		}
		need[i] = kmap[need[i]];
//		printf("%d, ", need[i]);
	}
//	puts("");
//	printf("have: ");
	forn (i, k) {
		if (kmap.find(ikey[i]) == kmap.end())
			ikey[i] = mark;
		else
			ikey[i] = kmap[ikey[i]];
//		printf("%d, ", ikey[i]);
	}
//	puts("");
	forn (i, n) {
//		printf("room %d: ", i);
		forn (j, SZ(have[i])) {
			if (kmap.find(have[i][j]) == kmap.end())
				have[i][j] = mark;
			else
				have[i][j] = kmap[have[i][j]];
//			printf("%d, ", have[i][j]);
		}
//		puts("");
	}
}

void solve() {
	scanf("%d%d", &k, &n);
	int val;
	ikey = vi(k);
	forn (i, k) {
		scanf("%d", &val);
		ikey[i] = val;

	}
	forn (i, n) {
		int m;
		scanf("%d%d", &val, &m);
		need[i] = val;
		have[i] = vi(m);
		forn (j, m) {
			scanf("%d", &val);
			have[i][j] = val;
		}
	}
	resetKey();
	clr(flag, 0);
	int tot = 1 << n;
	int key[30];
	dp[0] = vi();
	flag[0] = true;
	forn (st, tot) {
		if (!flag[st]) continue;
		calcKey(key, st);
		forn (i, n) {
			if ((1 << i) & st) continue;
			if (key[need[i]] <= 0) continue;
			int tt = st + (1 << i);
			vi v = dp[st];
			v.push_back(i);
			if (!flag[tt] || dp[tt] > v)
				dp[tt] = v;
			flag[tt] = 1;
		}
	}
	if (!flag[tot - 1]) {
		puts("IMPOSSIBLE");
	} else {
		forn (i, n) {
			if (i) printf(" ");
			printf("%d", dp[tot - 1][i] + 1);
		}
		puts("");
	}
}

int main() {
//	freopen("in.txt","r",stdin);
//	freopen("D:\\in.txt","r",stdin);
	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
//	freopen("D-large.in","r",stdin);freopen("D-large.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
