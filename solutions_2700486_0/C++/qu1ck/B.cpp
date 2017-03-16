#include <cstdio>
#include <algorithm>
#include <cmath>

double pw[1000001];

using namespace std;

double C[1000][1000];

double log2(int a){
    return log(a)/log(2);
}

double approx_cnk_log(int n,int m){
    if(n<m)return 0;
    if(n<1000 && m<1000)return log(C[n][n-m]);
    if(n==m || m==0)return 1;
    if(m==1 || n-m==1)return n;
    printf("%d %d %.3lf\n",n,m,n*log2(n)-m*log2(m)-(n-m)*log2(n-m));
    return n*log2(n)-m*log2(m)-(n-m)*log2(n-m);
}

int main() {
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    for(int i=0;i<1000;i++)C[i][0]=1;
    for(int i=1;i<1000;i++)
        for(int j=1;j<1000;j++)C[i][j]=C[i][j-1]+C[i-1][j];
    //printf("%.4lf\n",log2(16.));
    pw[0]=1.;
    for(int i=1;i<1000000;i++)pw[i]=pw[i-1]*.5;
    int ncase;
    scanf("%d",&ncase);
    for(int C=1;C<=ncase;C++){
        double ans=0;
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        if(x<0)x=-x;
        int h=1,s=1;
        while(s+h+1+h+2<=n){
            s+=h+1+h+2;
            h+=2;
            //printf("%d %d\n",s,h);
        }
        int r=n-s;
        if(x+y<h){
            ans=1.;
        }else if(x+y==h+1){
            int g=r-h-1;
            //printf("g: %d\n",g);
            if(g<0)g=0;
            if(y<g)ans=1.;
            else{
                h-=g,r-=g;
                int t=min(h,r);
                //printf("t: %d\n",t);
                for(int i=y-g;i<=t;i++){
                    //printf("p, i, r-i: %.3lf %d %d\n",pow(2.,approx_cnk_log(r,i+1)-r-1),i,r-i);
                    ans+=pow(2.,approx_cnk_log(r,i+1)-r-1);
                }
            }
        }

        printf("Case #%d: %.9lf\n",C,ans);
    }
    return 0;
}