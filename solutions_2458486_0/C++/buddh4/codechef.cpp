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

const int MAXN = 20;
map<int, int> keys[1 << MAXN];

bool dp[1 << MAXN];

struct Chest {
	int openKey;
	vi keys;
	void scan() {
		int K;
		keys.clear();
		cin >> openKey >> K;
		REP(i, 0, K) {
			int key;
			cin >> key;
			keys.pb(key);
		}
	}
	bool canOpen(map<int, int> state) {
		return state[openKey] > 0;
	}

	void open(map<int, int> & state) {
//		assert(canOpen(state));
		state[openKey]--;
		REP(i, 0, size(keys)) {
			state[keys[i]]++;
		}
	}
};

Chest chests[MAXN];

int N;

void constructKeys() {
	REP(mask, 1, (1 << N)) {
		REP(j, 0, N) {
			if(!((mask >> j) & 1)) continue;

			keys[mask] = keys[mask - (1 << j)];
			chests[j].open(keys[mask]);

			break;
		}
	}
}

void constructDP() {
	_(dp, 0);
	dp[(1 << N) - 1] = true;

	REPD(mask, 0, (1 << N) - 1) {
		REP(j, 0, N) {
			if((mask >> j) & 1) continue;

			if(chests[j].canOpen(keys[mask]) && dp[mask | (1 << j)]) {
				dp[mask] = true;
				break;
			}
		}
	}
}

vi restoreAns() {
	vi ret;
	map<int, int> state = keys[0];
	int currentMask = 0;

	REP(i, 0, N) {
		REP(j, 0, N) {
			if((currentMask >> j) & 1) continue;

			if(chests[j].canOpen(state) && dp[currentMask | (1 << j)]) {
				ret.pb(j + 1);
				currentMask |= 1 << j;
				chests[j].open(state);
				break;
			}

		}
	}

	return ret;
}

void solve() {
	int K;
	cin >> K >> N;

	REP(mask, 0, 1 << N) keys[mask].clear();

	REP(i, 0, K) {
		int key;
		cin >> key;
		keys[0][key]++;
	}

	REP(i, 0, N) chests[i].scan();

	constructKeys();
	constructDP();

	if(!dp[0]) {
		puts(" IMPOSSIBLE");
		return;
	}

	vi ans = restoreAns();
	REP(i, 0, size(ans)) {
		printf(" %d", ans[i]);
	}
	printf("\n");
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
		printf("Case #%d:", i + 1);
		solve();
	}

	
/*	
#ifdef shindo
	printf("\n-------------\n\n\nWalltime = %.3lf\n", clock() * 1e-3);
#endif
*/
}