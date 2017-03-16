#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 55;

int T, N, M;
int has[MAXN][MAXN];
Int cnt[MAXN][MAXN];

Int dfs(int node) {
    if (node == N - 1) {
        return 1;
    } else {
        Int ans = 0;

        for (int i = 0; i < N; i++) {
            if (has[node][i]) {
                ans += dfs(i);
            }
        }
        
        return ans;
    }
}

void run() {
    cnt[0][N - 1] = dfs(0);
}

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        
        bool poss = false;
        
        memset(has, 0, sizeof(has));

        for (int i = 1; i < N; i++) {        
            has[i - 1][i] = 1;
        }

        for (int r = 0; r < N * (N + 1) / 2; r++) {
            run();

            if (cnt[0][N - 1] >= M) {
                if (cnt[0][N - 1] == M) {
                    poss = true;
                }
                break;
            } else {
                bool fixed = false;
                for (int i = 0; !fixed && i < N; i++) {
                    for (int j = i + 1; !fixed && j < N; j++) {
                        if (has[i][j] == 0) {
                            has[i][j] = 1;
                            fixed = true;
                        }
                    }
                }
            }
        }

        cout << "Case #" << t << ": ";

        if (poss) {
            cout << "POSSIBLE" << endl;
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << has[i][j];
                }
                cout << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    
    return 0;
}
