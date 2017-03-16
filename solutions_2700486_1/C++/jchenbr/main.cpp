#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double ans;
int n,x,y;
const int N=2000+5;
double c[N][N];
int main(){
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int total;
    cin>>total;
    c[1][0]=c[1][1]=1;
    for (int i=2;i<=2000;i++){
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    for (int tt=1;tt<=total;tt++){
        cin>>n>>x>>y;
        int m=abs(x)+abs(y);
        m>>=1;
        int base=(2*m-1)*m,top=(2*m+1)*(m+1);
            m=m*2;
        if (base>=n){
            ans=0.0;
        }else if (n>=top){
            ans=1.0;
        }else if (y+1+m+base<=n){
            ans=1.0;
        }else{
            n-=base;
            if (x==0||y+1>n){
                ans=0.0;
            }else{
                double tmp=0;
                if (x<=m){
                    for (int i=0;i<=y;i++)
                        tmp+=c[n][i];
                    for (int i=0;i<n;i++)
                        tmp*=0.5;
                    ans=1.0-tmp;
                }else{
                    int bt=n-m;
                    double u=0.0,v=0.0;
                    for (int i=bt+1;i<=y;i++){
                        u+=c[n][i];
                    }
                    for (int i=y+1;i<m;i++){
                        v+=c[n][i];
                    }
                    for (int i=0;i<n;i++){
                        u*=0.5;
                        v*=0.5;
                    }
                    ans=(1.0-u-v)*0.5+v;
                }
            }
        }
        printf("Case #%d: %.7lf\n",tt,ans);
    }
}