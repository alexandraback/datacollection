#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <time.h>
using namespace std;
#define ot(x) cout<<x<<endl
#define cen cout<<endl
#define rep(u,a,b) for(int u=a;u<b;u++)
#define reo(z,b) for(int z=0;z<b;z++)
#define st ot((float)((float)t2-t1)/CLOCKS_PER_SEC)
long long int i,t,j,m,q,k,u,n,maks,mnm,a[10005];
long long int tmp,tma;
int main ()
{
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        printf("Case #%lld: ",i);
        if(!x && !y)
            printf("WEEW\n");
        else{
            if(x>0){
                while(x--)
                    printf("WE");
            }else
            if(x<0){
                while(x++)
                    printf("EW");
            }
            if(y>0){
                while(y--)
                    printf("SN");
            }else
            if(y<0){
                while(y++)
                    printf("NS");
            }
            printf("\n");
        }
    }
    return 0;
}
/*
space for testcase

*/
