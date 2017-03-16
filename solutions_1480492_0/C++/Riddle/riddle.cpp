#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int MaxN = 7;
const int inf = 1 << 20;

int F[MaxN], S[MaxN], P[MaxN];
double point[MaxN * MaxN];
int pt = 0;
int N;
int stat[1 << 6];
int flag[1 << 6];
int wei[7] = {0};

struct Box{
    int pt;
    int F[MaxN];
    double P[MaxN];
};

Box que[1 << 20];

int calc(int a){
    if(a) return 1;
    return 0;
}

int check(int a){
    for(int i = 0; i < N; ++i){
        for(int j = i + 1; j < N; ++j){
            if(calc(a & (1 << i)) == calc(a & (1 << j)) && fabs(P[i] - P[j]) <= 5.0)
                return 1;
        }
    }
    return 0;
}

void dfs(int a, int mask){
    if(a == N){
        flag[mask] = 1;
        return ;
    }
    if(wei[a] == 0 || wei[a] == 2) dfs(a + 1, mask);
    if(wei[a] == 1 || wei[a] == 2) dfs(a + 1, mask | (1 << a));
}

void output(int a){
    for(int i = 0; i < N; ++i){
        printf("%d ", calc(a & (1 << i)));
    }puts("");
}

int main(){
    int T;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.txt", "w", stdout);
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas){
        pt = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            char ss[10];
            scanf("%s%d%d", ss, S + i, P + i);
            F[i] = ss[0] == 'L' ? 0 : 1;
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j && S[i] < S[j] && P[i] >= P[j] + 5){
                    point[pt++] = 1.0 * (P[i] - P[j] - 5) / (S[j] - S[i]);
                }
            }
        }
        point[pt++] = 0.0;
        sort(point, point + pt);
        int head = 0, tail = 0;
        double Max = 0;

        memset(stat, 0, sizeof(stat));
        int p = 0;
        for(int i = 0; i < N; ++i){
            p |= (F[i] << i);
        }
//        for(int i = 0; i < pt; ++i){
//            printf("%.4f ", point[i]);
//        }puts("");
        stat[p] = 1;
        int lag = 0;
        for(int st = 0; st < pt; ++st){
            memset(flag, 0, sizeof(flag));
            Max = max(Max, point[st]);
            if(st && point[st] == point[st - 1]) continue;
//            printf("st = %d :\n", st);
//            for(int i = 0; i < (1 << N); ++i){
//                if(stat[i]) {
//                    output(i);
//                }
//            }
            for(int i = 0; i < N; ++i){
                P[i] += S[i] * (point[st] - (st == 0 ? 0 : point[st - 1]));
            }

            for(int mask = 0; mask < (1 << N); ++mask){
                if(!stat[mask]) continue;
                for(int i = 0; i < N; ++i){
                    int f = 1;
                    for(int j = 0; j < N; ++j) if(i != j){
                        if(calc(mask & (1 << i)) != calc(mask & (1 << j))){
                            if(fabs(P[i] - P[j]) < 5.0){
                                f = 0;
                                break;
                            }
                        }
                    }
                    if(f) wei[i] = 2;
                    else wei[i] = calc(mask & (1 << i));
                }
                dfs(0, 0);
            }
            memset(stat, 0, sizeof(stat));
            int f = 0;
            for(int i = 0; i < (1 << N); ++i){
                if(flag[i] && !check(i)) {
                    stat[i] = 1;
                    f = 1;
                }
            }
            if(!f) break;
            if(st == pt - 1) lag = 1;
        }
        printf("Case #%d: ", cas);
        if(lag) puts("Possible");
        else {
            printf("%.6f\n", Max);
        }
    }
}
