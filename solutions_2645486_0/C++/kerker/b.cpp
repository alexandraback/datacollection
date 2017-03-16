#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int a[15],ans,N,R,E;

void dfs(int lv,int left,int now){
    if(lv==N+1){
        ans = max(ans,now);
        return;
    }
    int i,j;
    for(i=0;i<=left;i++){
        dfs(lv+1,min(left-i+R,E),now+i*a[lv]);
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t,T,n,i,j;
    scanf(" %d",&T);
    for(t=0;t<T;t++){
        scanf(" %d %d %d",&E,&R,&N);
        for(n=1;n<=N;n++)
            scanf(" %d",&a[n]);
        ans = 0;
        dfs(1,E,0);
        printf("Case #%d: %d\n",t+1,ans);
    }

    return 0;
}
