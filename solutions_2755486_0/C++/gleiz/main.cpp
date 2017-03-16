#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct att{
    int strength;
    int start;
    int end;
    int day;
}att, *ATT;

bool operator < (const struct att& x, const struct att& y){
    if (x.day < y.day){
        return true;
    }else{
        return false;
    }
}

int d = 0, n = 0, w = 0, e = 0, s = 0, dd = 0, dp = 0, ds = 0;

struct att attack[100000];
int cnt = 0;
int wall[1000010] = {0};
int need[1000010] = {0};
int main()
{
    int T = 0;
    int res = 0;

    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++){
        int N = 0;
        scanf("%d", &N);
        cnt = 0;
        for (int i = 0; i<N; i++){
            scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &dd, &dp, &ds);

            for (int x = 0; x<n; x++){
                if (x == 0){
                    attack[cnt].day = d + x * dd;
                    attack[cnt].start = w + x * dp + 1;
                    attack[cnt].end = e + x * dp;
                    attack[cnt].strength = s + x * ds;
                }else{
                    attack[cnt].day = d + x * dd;
                    attack[cnt].start = w + x * dp + 1;
                    attack[cnt].end = e + x * dp;
                    attack[cnt].strength = s + x * ds;
                }
                cnt++;
            }
        }

        sort(attack, attack + cnt);
        memset(need, 0, sizeof(need));
        memset(wall, 0, sizeof(wall));

        int top = 0;
        res = 0;
        while (top < cnt){
            int pstart = top;
            int pend = top;
            while (pend < cnt && attack[pend].day == attack[pstart].day){
                int succ = 0;
                for (int i = attack[pend].start; i <= attack[pend].end; i++){
                    int pos = i + 500000;
                    if (wall[pos] < attack[pend].strength){
                        if (need[pos] < attack[pend].strength){
                            need[pos] = attack[pend].strength;
                        }
                        succ = 1;
                    }
                }
                if (succ){
                    res++;
                }
                pend++;
            }

            for (int i = pstart; i<pend; i++){
                for (int j = attack[i].start; j<=attack[i].end; j++){
                    int pos = j + 500000;
                    if (wall[pos] < need[pos]){
                        wall[pos] = need[pos];
                    }
                }
            }
            top = pend;
        }
        printf("Case #%d: %d\n", cas, res);
    }
    return 0;
}
