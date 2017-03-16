#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <list>
#include <stack>
#include <tuple>
#include <utility>
#include <complex>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <typeinfo>
using namespace std;

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

#define REP(i,n) for(int i=0; i<(n); i++)
#define REPA(i,s,e) for(int i=(s); i<=(e); i++)
#define REPD(i,s,e) for(int i=(s); i>=(e); i--)
#define ALL(a) (a).begin(), (a).end()

#define PRT(a) cerr << #a << " = " << (a) << endl
#define PRT2(a, b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << endl
#define PRT3(a, b, c) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << ", " << #c << " = " << (c) <<  endl
template <class Ty> void print_all(Ty b, Ty e) {
	cout << "[ ";
	for(Ty p=b; p!=e; ++p) {
		cout << (*p) << ", ";
	}
	cout << " ]" << endl;
}

// -----------------------------------------------------------------------------
// Code starts 
// -----------------------------------------------------------------------------

int N;
vector<int> G;
vector<int> dist;
int ans;

void dfs(int f, int v, int pre, int depth) {
    dist[v] = depth;
    if (G[v] == f || G[v] == pre) {
        ans = max(ans, abs(dist[v] - dist[f]) + 1);        
    }

    if (depth == N - 1) return;

    if (G[v] == pre) {
        for (int i = 0; i < N; i++) {
            if (dist[i] == -1) {
                dfs(f, i, v, depth + 1);
                break;
            }
        }
    } else if (dist[G[v]] == -1) {
        dfs(f, G[v], v, depth + 1);
    }
    dist[v] = -1;
}

void check() {
    for (int i = 0; i < N; i++) {
        fill(ALL(dist), -1);
        dfs(i, i, -1, 0);
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    dist.resize(N);
    REP(i, N) {
        cin >> G[i];
        G[i]--;
    }

    ans = -1;
    check();
    printf("%d\n", ans);
}

// -----------------------------------------------------------------------------
// Code ends 
// -----------------------------------------------------------------------------

void coding() {
    int T;
    cin >> T;
    REPA(t,1,T) {
        fprintf(stderr, "%3d / %d\n", t, T);
        printf("Case #%d: ", t);
        solve();
    }
}

#define _LOCAL_TEST 2

int main() {
#if _LOCAL_TEST == 0
	clock_t startTime = clock();
	freopen("c.in", "r", stdin);
#elif _LOCAL_TEST == 1
	freopen("../input/C-small-attempt0.in", "r", stdin);
    freopen("../output/C-small_test.out", "w", stdout);
#elif _LOCAL_TEST == 2
	freopen("../input/C-large.in", "r", stdin);
    freopen("../output/C-large.out", "w", stdout);
#endif

	coding();

#if _LOCAL_TEST == 0
	clock_t elapsedTime = clock() - startTime;
	cerr << endl;
	cerr << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cerr << "This is local test" << endl;
	cerr << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif

}
