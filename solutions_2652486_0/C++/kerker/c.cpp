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

int T,R,N,M,K,a[10],is[10],oao[3];

void dfs(int lv,int now){
    int i,j,k;

    for(k=0;k<K;k++)
        if(a[k]==now)
            is[k] = 1;
    if(lv==3)
        return;
    dfs(lv+1,now*oao[lv]);
    dfs(lv+1,now);
}

int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);

    int i,j,t=1,k;
    scanf(" %d",&T);
    while(T--){
        printf("Case #%d:\n",t++);
        scanf(" %d %d %d %d",&R,&N,&M,&K);
        int win;
        for(int r=0;r<R;r++){
            win = 0;
            for(k=0;k<K;k++)
                scanf(" %d",&a[k]);
            for(i=2;i<=M && win==0;i++){
                for(j=2;j<=M && win==0;j++){
                    for(k=2;k<=M && win==0;k++){
                        memset(is,0,sizeof(is));
                        oao[0] = i;
                        oao[1] = j;
                        oao[2] = k;
                        dfs(0,1);
                        int re = 0;
                        for(int gg=0;gg<K && re==0;gg++){
                            if(is[gg]==0)
                                    re = 1;
                        }
                        if(re==0){
                            printf("%d%d%d\n",i,j,k);
                            win = 1;
                        }
                    }
                }
            }
            if(win==0){
                for(int n=0;n<N;n++)
                    printf("%d",M);
                printf("\n");
            }
        }
    }

    return 0;
}
