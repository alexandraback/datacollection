#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

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
        if(n==0)
            printf("INSOMNIA\n");
        else{
            int vis[10];
            memset(vis,0,sizeof(vis));
            int num=0,t=n;
            while(num<10){
                int tmp=n;
                while(tmp){
                    int id=tmp%10;
                    if(!vis[id]){
                        num++;
                        vis[id]=1;
                    }
                    tmp/=10;
                }
                if(num==10)
                    break;
                n+=t;
            }
            printf("%d\n",n);
        }
    }
    return 0;
}
