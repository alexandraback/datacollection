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

int T,N,s[10005];
char tmp[10005];

int main(){
    scanf("%d",&T);
    FOE(t,1,T){
        scanf("%d%s",&N,tmp);
        FOR(i,0,N+1) s[i] = tmp[i]-'0';

        int ans = 0, cnt=0;
        FOR(i,0,N+1){
            if (cnt < i){
                int tar = i-cnt;
                ans += tar;
                cnt += tar+s[i];
            }
            else{
                cnt += s[i];
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
