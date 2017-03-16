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

int ans;

int main(){
    int T; scanf("%d",&T);
    FOE(t,1,T){
        int R,C,W;
        scanf("%d%d%d",&R,&C,&W);

        int ans = (C/W) + W-1;
        if (C%W != 0) ++ans;
        printf("Case #%d: %d\n",t,ans*R);
    }
    return 0;
}
