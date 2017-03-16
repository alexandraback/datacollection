#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;    
#define eps 1e-10
double f[15][1 << 10][10];
int cnt[100][1 << 10];
int K, L, S;
char key[10], goal[10];
void calcF(){
    int i, j, l, k, m;
    for (i = 0; i <= S; i++) {
        for (j = 1; j < (1 << (L + 1)); j++) {
            for (l = 0; l <= S; l++) {
                if (f[i][j][l] < eps) continue;
                if (i == S) continue;
                for (k = 0; k < K; k++) {
                    int tmp = 1;
                    for (m = 0; m < L; m++) {
                        if (!(j & (1 << m))) continue;
                        if (key[k] == goal[m]) tmp += 1 << (m + 1);
                    }
                    if (tmp & (1 << L)) f[i + 1][tmp][l + 1] += f[i][j][l] / K;
                    else f[i + 1][tmp][l] += f[i][j][l] / K;
                }
            }
        }
    }
}
int main() {
    int N, cas;
    scanf("%d", &N);
    for (cas = 1; cas <= N; cas++) {
        cin >> K >> L >> S;
        scanf("%s%s", key, goal);
        for (int i = 0; i <= 10; i++) 
            for (int j = 0; j < (1 << 10); j++) 
                for (int k = 0; k < 10; k++) 
                    f[i][j][k] = 0;
        f[0][1][0] = 1;
        int res = 0;
        calcF();
        double ans = 0;
        for (int j = 1; j < (1 << (L + 1)); j++) {
            for (int k = 0; k <= S; k++) {
                if (f[S][j][k] > eps) res = max(res, k);
                ans += f[S][j][k] * k;
            }
        }
        printf("Case #%d: %.8lf\n", cas, res - ans);
    }
    return 0;
}
