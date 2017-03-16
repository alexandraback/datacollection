#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define eps 1e-9
#define FOR(x, s, e) for(int x = (s); x < (e); ++x)
#define FORc(x, s, e, c) for(int x = (s); x < (e) && (c); ++x)
#define STEP(x, s, e, d) for(int x = (s); x < (e); x+=(d))
#define ROF(x, s, e) for(int x = (s); x >= (e); --x)
#define ROFc(x, s, e, c) for(int x = (s); x >= (e) && (c); --x)
#define vb vector<bool>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define ALL(X) X.begin(), X.end()
#define LL long long
#define pii pair<int, int>
#define x first
#define y second
#define gcd(x, y) __gcd((x), (y))
#define countbit(x) __builtin_popcount(x)

using namespace std;

bool dp[2000100];
int pre[2000100];

int main(int argc, char **argv){
    int T;
    cin >> T;
    FOR(ca, 1, T+1){
        int N;
        cin >> N;
        vi A(N);
        FOR(i, 0, N) cin >> A[i];
        sort(ALL(A));
        bool ok = 0;
        printf("Case #%d:\n", ca);
        FORc(i, 1, (1<<N)-1, !ok){
            vi B;
            LL S = 0;
            FOR(j, 0, N) if ((1<<j)&i) S += A[j]; else B.pb(A[j]);
            memset(dp, 0, sizeof(dp));
            memset(pre, -1, sizeof(pre));
            dp[S] = 1;
            FORc(j, 0, B.size(), !ok)
                FOR(k, 0, S-B[j]+1)
                    if (dp[k+B[j]])
                        dp[k] = 1, pre[k] = k+B[j];
            if (dp[0]){
                ok = 1;
                FOR(j, 0, N) if ((1<<j)&i) printf("%d ", A[j]); puts("");
                int t = 0;
                while (t != S){
                    printf("%d ", pre[t] - t);
                    t = pre[t];
                }
                puts("");
            }
        }
        if (!ok) puts("Impossible");
    }
	return 0;
}
