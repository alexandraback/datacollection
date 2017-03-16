/*C*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <iostream>
#include <set>

using namespace std;

int T, nCase = 0;
int R, N, M, K;
long long p[12];
long long s[12];
set<long long> contain;
bool flag = false;

void dfs(int d) {
    if (flag) return;
    if (d >= N) {
//        for (int i = 0; i < N; ++i) printf("%d", s[i]);
//        printf("-------\n");
        contain.clear();
        contain.insert(1);
        for (int i = 0; i < N; ++i) {
            contain.insert(s[i]);
        }
        if (M >= 2) {
            contain.insert(s[0] * s[1]);
            contain.insert(s[1] * s[2]);
            contain.insert(s[0] * s[2]);
        }
        if (M >= 3)
            contain.insert(s[0] * s[1] * s[2]);

//        for(set<long long>::iterator it = contain.begin(); it != contain.end(); ++it){
//            cout << *it << " ";
//         }
//        cout << endl;
        bool ans = true;
        for (int i = 0; i < K; ++i) {
            if (contain.find(p[i]) == contain.end()) {
                ans = false;
                break;
            }
        }
        if (ans) {
            for (int i = 0; i < N; ++i) {
                printf("%d", s[i]);
            }
            printf("\n");
            flag = true;
        }
        return;
    }
    for (int i = 2; i <= M; ++i) {
        s[d] = i;
        dfs(d + 1);
        if (flag) return;
    }
}

long long solve() {
    cin >> R >> N >> M >> K;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> p[j];
        }
        flag = false;
        dfs(0);
    }
}

int main(int argc, char** argv) {
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C-small-1-attempt0.out", "w", stdout);
    cin >> T;
    while (nCase < T) {
        printf("Case #%d:\n", ++nCase);
        solve();
    }
    return 0;
}
