#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

bool use[100];
int mar[60][60];
int ans[60];
int cnt[2555];
int T, N;
vector<int> tmp;

void Solve(int dep) {
    if(dep >= N) return;
    
    int min1 = 10000, min2 = 10000, pos1, pos2;
    for(int i = 0; i < 2 * N - 1; i++) {
        if(use[i] == false) {
            if(mar[i][dep] < min1) {
                min2 = min1;
                pos2 = pos1;
                min1 = mar[i][dep];
                pos1 = i;
            }
            else if(mar[i][dep] < min2) {
                min2 = mar[i][dep];
                pos2 = i;
            }
        }
    }
    
    memset(cnt, 0, sizeof(cnt));
    tmp.clear();
    if(min1 != min2) {
        for(int i = dep; i < N; i++) {
            cnt[mar[pos1][i]]++;
        }
        
        for(int i = 0; i < 2 * N - 1; i++) {
            if(use[i] == false) {
                if(cnt[mar[i][dep]] == 0) {
                    tmp.push_back(mar[i][dep]);
                }
                else cnt[mar[i][dep]]--;
            }
        }
        tmp.push_back(min1);
        sort(tmp.begin(), tmp.end());
        for(int i = dep; i < N; i++) {
            ans[i] = tmp[i - dep];
        }
        return;
    }
    else {
        for(int i = dep; i < N; i++) {
            cnt[mar[pos1][i]]++;
            cnt[mar[pos2][i]]++;
        }
        for(int i = 0; i < 2 * N - 1; i++) {
            if(use[i] == false) {
                cnt[mar[i][dep]]--;
            }
        }
        for(int i = 1; i <= 2500; i++) {
            if(cnt[i] != 0) {
                ans[dep] = i;
                use[pos1] = true;
                use[pos2] = true;
                Solve(dep + 1);
                return;
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        printf("Case #%d:", cas);
        for(int i = 0; i < 2 * N - 1; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%d", &mar[i][j]);
            }
        }
        memset(use, false, sizeof(use));
        Solve(0);
        for(int i = 0; i < N; i++) {
            printf(" %d", ans[i]);
        }
        puts("");
    }
    return 0;
}