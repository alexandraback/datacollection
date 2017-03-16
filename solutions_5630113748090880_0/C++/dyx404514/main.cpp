#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int vis[3000];
int main()
{
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        int n;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<2*n;i++){
            for(int j=0;j<n;j++){
                int x;
                scanf("%d",&x);
                vis[x]++;
            }

        }
        for(int i=0;i<=2500;i++){
            if(vis[i]%2)
                printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
