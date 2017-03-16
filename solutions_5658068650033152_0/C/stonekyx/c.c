#include <stdio.h>
#include <string.h>
#include <limits.h>

int check(int x)
{
    int cnt=0;
    while(x) {
        cnt+=(x&1);
        x>>=1;
    }
    return cnt;
}

const int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};

int check_range(int x, int y, int N, int M)
{
    return x>=0 && y>=0 && x<N && y<M;
}

int get_mini(int x, int N, int M)
{
    static int map[50][50];
    int i;
    int ans=0;
    for(i=0; i<N; i++) {
        int j;
        for(j=0; j<M; j++) {
            if(x&(1<<(i*M+j))) {
                map[i][j]=1;
                ans++;
            } else map[i][j]=0;
        }
    }
    for(i=0; i<N; i++) {
        int j;
        for(j=0; j<M; j++) {
            int k;
            for(k=0; k<4; k++) {
                int ni=i+dx[k], nj=j+dy[k];
                if(!check_range(ni, nj, N, M)) break;
                if(!map[ni][nj]) {
                    break;
                }
            }
            if(k>=4) {
                ans--;
            }
        }
    }
    return ans;
}

int main()
{
    int T, Tcnt=0;
    for(scanf("%d", &T); T; T--) {
        int i;
        int N, M, K;
        int size;
        int ans = INT_MAX;
        scanf("%d%d%d", &N, &M, &K);
        size = N*M;
        for(i=0; i<(1<<size); i++) {
            if(check(i)>=K) {
                int tans = get_mini(i, N, M);
                if(ans>tans) ans = tans;
            }
        }
        printf("Case #%d: %d\n", ++Tcnt, ans);
    }
    return 0;
}

