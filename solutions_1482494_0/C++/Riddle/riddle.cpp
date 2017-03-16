#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int MaxN = 1005;

int A[MaxN], B[MaxN];
int F[MaxN];

int main(){
    int T;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.txt", "w", stdout);
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas){
        memset(F, 0, sizeof(F));
        int N;scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            scanf("%d%d", A + i, B + i);
        }
        int cnt = 0;
        int level = 0;
        int sum = 0;
        while(1){
            int flag = 0;
            for(int i = 0; i < N; ++i){
                if(F[i] != 2 && B[i] <= level){
                    flag = 1;
                    level += 2 - F[i];
                    cnt ++;
                    F[i] = 2;
                    sum ++;
                    break;
                }
            }
            if(flag) continue;
            int Max = -1, idx = -1;
            for(int i = 0; i < N; ++i){
                if(F[i] == 0 && A[i] <= level){
                    flag = 1;
                    if(Max < B[i]){
                        Max = B[i];
                        idx = i;
                    }
                }
            }
            if(!flag) break;
            F[idx] = 1;
            sum ++;
            level ++;
        }
        printf("Case #%d: ", cas);
        if(cnt == N){
            printf("%d\n", sum);
        }
        else {
            puts("Too Bad");
        }
    }
}
