#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "bitset"

using namespace std;

typedef long long ll;
typedef pair < int, int > ii;

const int N = 16;

int n, tick;
int a[N], b[N], dp[1 << N];
map < string, int > M;

void solve() {
    M.clear();
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if(!M[s1]) M[s1] = ++tick;
        if(!M[s2]) M[s2] = ++tick;
        a[i] = M[s1];
        b[i] = M[s2] + n;
        //printf("a[%d] = %d b[%d] = %d\n", i, a[i], i, b[i]);
    }
    memset(dp, 0, sizeof(dp));
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(~mask & (1 << i)) {
                bool c1 = 0, c2 = 0;
                for(int j = 0; j < n; j++) {
                    if(mask & (1 << j)) {
                        c1 |= a[i] == a[j];
                        c2 |= b[i] == b[j];
                    }
                }
                //printf("mask = %d i = %d c1 and c2 = %d\n", mask, i, c1 and c2);
                dp[mask ^ (1 << i)] = max(dp[mask ^ (1 << i)], dp[mask] + (c1 and c2));
            }
        }
    }
    printf("%d\n", dp[(1 << n) - 1]);
}

int main () {
    
    freopen("C-small-attempt0.in.txt", "r", stdin);
    freopen("small.txt", "w", stdout);
    
    int n;
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    
    return 0;
    
}