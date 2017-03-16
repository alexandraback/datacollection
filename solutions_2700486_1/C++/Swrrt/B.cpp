#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int GS[4005];
double F[4005][4005];
int main(){
    int T,n,m,i,j,k,l,tt,x0,y0;
    tt=0;
    GS[0]=1;
    for(i=1;i<=4000;i++){
        GS[i]=(i+1)*(2*i+1);
    }
    scanf("%d",&T);
    freopen("B.out","w",stdout);
    while(T--){
        tt++;
        scanf("%d%d%d",&n,&x0,&y0);
        if(x0<0)x0=-x0;
        printf("Case #%d: ",tt);
        if((x0+y0)%2==1)printf("0\n");
        else{
            for(i=1;i<=4000;i++)if(GS[i]>=n)break;
            m=i-1;
            if(x0+y0<=2*m)printf("%.10lf\n",(double)1);
            else if(x0+y0>2*m+2)printf("%.10lf\n",(double)0);
            else if(n==GS[m+1])printf("%.10lf\n",(double)1);
            else{
                n-=GS[m];
                F[0][0]=1;
                for(i=0;i<=2*m+3&&i<=n;i++)
                    for(j=0;j<=2*m+3&&j+i<=n;j++)
                        if(i||j){
                            F[i][j]=0;
                            if(j!=2*m+3&&i!=2*m+3)
                            {
                                if(i>0&&j!=2*m+2)F[i][j]+=F[i-1][j]/2.0;
                                else if(i>0)F[i][j]+=F[i-1][j];
                                if(j>0&&i!=2*m+2)F[i][j]+=F[i][j-1]/2.0;
                                else if(j>0)F[i][j]+=F[i][j-1];
                            }
                        }
                double ans=0;
                
                for(i=y0+1;i<=2*m+3&&i<=n;i++){
                    ans+=F[i][n-i];
//            printf("%d %d %.10lf\n",i,n-i,F[i][n-i]);
                }
                if(ans>1.0000000000)ans=1.0000000000;
                printf("%.10lf\n",ans);
            }
        }
    }
    return 0;
}
