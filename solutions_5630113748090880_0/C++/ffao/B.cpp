#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;

vector<int> rows[101];
int ssq[101][101];
int bd[101][101];
int ans[101];

void read() {
    scanf("%d", &n);
    REP(i, 2*n-1) {
        rows[i].resize(n);
        REP(j, n) {
            scanf("%d", &rows[i][j]);
        }
    }    
}

void solve() {
    sort(rows, rows+(2*n-1));


    for (int m = 0; m < (1<<(2*n-1)); m++) if (__builtin_popcount(m) == n) {
        int nxt = 0;
        REP(i,2*n-1) if (m & (1<<i)) {
            REP(j,n) bd[nxt][j] = rows[i][j];
            nxt++;
        }

        /*REP(i,n) {REP(j,n) {
            printf("%d ", bd[i][j]);
        }
        printf("\n");}
        printf("\n");*/

        REP(picked, n) {
            REP(j,n) ans[j] = bd[j][picked];

            int idx = 0;
            if (idx == picked) idx++;
            bool ok = true;
            REP(i,2*n-1) if (! (m & (1<<i))) {
                REP(j,n) if (rows[i][j] != bd[j][idx]) ok = false;
                idx++;
                if (idx == picked) idx++;
            }

            if (ok) {
                REP(j,n) printf("%d ", ans[j]);
                printf("\n");
                return;
            }
        }
    }
}


























int myMod = 0;
int howMany = 1;

int main(int argc, char** argv) {
    if (argc > 1) {
        stringstream ss; ss << argv[1]; ss >> myMod;
        ss.str(""); ss.clear();
        ss << argv[2]; ss >> howMany;
    }

    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        read();
        if (i % howMany == myMod) {
            printf("Case #%d: ", i+1);
            solve();
        }
    }
}