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
#define rep(i,a,b) for(int i=a;i<b;i++)
#define st ot((float)((float)t2-t1)/CLOCKS_PER_SEC)
int i,n,t,j,m,q,k,a[3101],u;
long long int tmp,tmb,maks,mnm;

int main ()
{
    scanf("%d",&t);
    rep(i,0,t){
        mnm=1000003;
        scanf("%d%d",&n,&k);
        for(j=0;j<k;j++){
            scanf("%d",&a[j]);
        }
        sort(a,a+k);
        int os=n;
        if(n==1){
            mnm=k;
        }else{
            for(u=0;u<k+1;u++){
                tmp+=u;
                n=os;
                for(j=0;j<k-u;j++){
                    //ot(j<<"--"<<n<<"--"<<a[j]<<"--"<<tmp);
                    if(n>a[j]){
                        n+=a[j];
                    }else{
                        tmp++;
                        n+=(n-1);
                        j--;
                    }
                }
                mnm=min(tmp,mnm);
                tmp=0;
            }
        }
        printf("Case #%d: %d\n",i+1,mnm);
    }
    return 0;
}
/*
1
10 4
25 20 9 100
*/
