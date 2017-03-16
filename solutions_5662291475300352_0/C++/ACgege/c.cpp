#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define eps 1e-8
#define db double
#define rt return
#define cn const
#define op operator
#define N 100
using namespace std;

int d[N][3];
int main()
{
     freopen("C-small-1-attempt3.in","r",stdin);
    freopen("c.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++)
             scanf("%d%d%d",&d[i][0],&d[i][1],&d[i][2]);

       int x1=d[0][0],y1=d[0][2];
       int x2=x1,y2=y1+1;

       if(n==2) {x2=d[1][0];y2=d[1][2];}

       if(d[0][1]==2) n=2;

       int ans=0;
         if(n==2)
         {
             if(y1<y2){
                swap(x2,x1);
                swap(y1,y2);
             }

             if(y1==y2) ans=0;
             else{

                double t1=(360-x1)/360.0 * y1;
                double t2=(360-x2)/360.0 *y2;

                t1=max(t1,t2);
               t2+=y2;

                if(t2<t1) ans=1;
              //printf("%lf  %lf\n",t1,t2);
             }
         }
            printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
