#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define INF (0x3f3f3f3f)

#define SZ(x) ((int)((x).size()))
#define PB(x) push_back(x)
#define MEMSET(x,v) memset(x,v,sizeof(x))
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))

typedef long long LL;
typedef pair<int, int> PII; typedef pair<PII, int> PII2;

#define MAXN (1005)

int D;
int in[MAXN];

void solve() {
    cin >> D;
    int ans = 0;
    REP(i, D) {
        cin >> in[i];
        ans = max(ans, in[i]);
    }
    for (int i = 1; i <= ans; i++) {
        int temp = i;
        REP(j, D) {
            if (in[j] > i) {
                temp += (in[j] - 1) / i;
            }
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
}

int main() {
    int test;
    cin >> test;
    REP(t, test) {
        printf("Case #%d: ", t + 1);
        solve();
    }
    
    return 0;
}
