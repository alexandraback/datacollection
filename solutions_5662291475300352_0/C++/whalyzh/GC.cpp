#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;
typedef double db;

int t,m,n;

int h,d;
int h1,d1,m1;
int h2,d2,m2;

int main()
{
#ifdef Haha
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
#endif // Haha
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        printf("Case #%d: ",cas);
        scanf("%d",&n);
        if(n==1){
            scanf("%d%d%d",&d,&h,&m);
            if(h==1) printf("0\n");
            else{
                double tt=m*(720.0-d)/360.0;
                double dd=tt*360/(m+1);
                if(dd+d>360+1e-6) printf("0\n");
                else printf("1\n");
            }

        }
        else{
            scanf("%d%d%d",&d1,&h1,&m1);
            scanf("%d%d%d",&d2,&h2,&m2);
            double tt1=m1*(720.0-d1)/360.0;
            double tt2=m2*(720.0-d2)/360.0;
            if(tt1<tt2){
                double dd=tt1*360/m2;
                if(dd+d2>360+1e-6) printf("0\n");
                else printf("1\n");
            }
            else{
                double dd=tt2*360/m1;
                if(dd+d1>360+1e-6) printf("0\n");
                else printf("1\n");
            }
        }
    }
    return 0;
}
