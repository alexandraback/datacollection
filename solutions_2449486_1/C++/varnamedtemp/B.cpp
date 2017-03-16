#include <iostream>
#include <cstdio>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <memory.h>
#include <bitset>

using namespace std;

#define ll long long

#define MAX_N 100
#define MAX_P_LEN 100000

int N, M, A[105][105], rowOk[105][105], colOk[105][105];
int main() {
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++) {
        scanf("%d %d",&N,&M);

        for(int i = 1;i<=100;i++) {
            fill(rowOk[i], rowOk[i] + 1 + N, 0);
            fill(colOk[i], colOk[i] + 1 + M, 0);
        }

        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++)
                scanf("%d",&A[i][j]);

        bool ok = true;
        for(int i = 1;i<=100 && ok;i++) {
            for(int r = 1;r<=N;r++) {
                int cnt = 0;
                for(int c = 1;c<=M;c++) {
                    if(A[r][c] == -1 || A[r][c] == i) cnt++;
                }
                if(cnt == M) rowOk[i][r] = 1;
            }
            for(int c = 1;c<=M;c++) {
                int cnt = 0;
                for(int r = 1;r<=N;r++) {
                    if(A[r][c] == -1 || A[r][c] == i) cnt++;
                }
                if(cnt == N) colOk[i][c] = 1;
            }

            for(int r = 1;r<=N && ok;r++) {
                for(int c = 1;c<=M && ok;c++) {
                    if(A[r][c] == i) {
                        if(!rowOk[i][r] && !colOk[i][c])
                            ok = false;
                        A[r][c] = -1;
                    }
                }
            }
        }
        printf("Case #%d: ", t);
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
