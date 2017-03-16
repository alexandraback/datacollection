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

#define MAXS (1005)

char in[MAXS];

void solve() {
    int S;
    cin >> S >> in;
    int ans = 0;
    int num_up = 0;
    for (int i = 0; i <= S; i++) {
        if (in[i] != '0') {
            if (i <= num_up) {
                num_up += in[i] - '0';
            } else {
                int temp = i - num_up;
                ans += temp;
                num_up += in[i] - '0';
                num_up += temp;
            }
        }
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
