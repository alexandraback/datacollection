#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

int T,D;
int q[1005];

int main(){
    scanf("%d",&T);
    FOE(t,1,T){
        scanf("%d",&D);
        
        int pMax = -1;
        FOR(i,0,D){
            scanf("%d",&q[i]);
            pMax = max(pMax,q[i]);
        }

        int ans = INF;
        FOE(h,1,pMax){
            int cnt = 0;
            FOR(i,0,D){
                if (q[i] > h) cnt += (q[i]-1)/h;
            }
            //printf("%d %d\n",h,cnt);
            ans = min(ans, h+cnt);
        }

        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
