#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N,M;
long long t1[102][2];
long long t2[102][2];

long long dp[103][103];

long long ddp(int x, int y){
    if(x >= N || y >= M)  return 0;
    if(dp[x][y] != -1)  return dp[x][y];
    long long sum = 0, tmp;
    long long remain;
    if(t1[x][1] == t2[y][1]){
        tmp = min(t1[x][0],t2[y][0]);
        sum = max (ddp(x+1,y+1) + min(t1[x][0],t2[y][0]), sum);
        remain = t1[x][0]-t2[y][0];
        int x1 = x, y1 = y;
        while(remain!=0 && x1 < N && y1 < M){
            if(remain > 0){
                y1++;
                if(y1 >= M) break;
                if(t1[x1][1] == t2[y1][1]){
                    tmp += min(remain, t2[y1][0]);
                    remain = remain - t2[y1][0];
                    sum = max(tmp + ddp(x1+1, y1+1), sum);
                }
            }
            else if(remain < 0){
                x1++;
                if(x1 >= N) break;
                if(t1[x1][1] == t2[y1][1]){
                    tmp += min(-remain, t1[x1][0]);
                    remain = remain + t1[x1][0];
                    sum = max(tmp + ddp(x1+1, y1+1), sum);
                }
            }
        }
    }
    sum = max(max(sum, ddp(x+1,y)), ddp(x, y+1));
    return dp[x][y] = sum;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int c=1;c<=T;c++){
        printf("Case #%d: ", c);
        memset(dp, -1, sizeof(dp));
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;++i){
            scanf("%lld %lld",&t1[i][0] , &t1[i][1]);
        }
        for(int i=0;i<M;++i){
            scanf("%lld %lld",&t2[i][0] , &t2[i][1]);
        }
        printf("%lld\n", ddp(0,0));
    }
    return 0;
}
