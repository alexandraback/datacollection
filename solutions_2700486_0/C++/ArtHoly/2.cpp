#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int n,x,y;
double ans;
int T;
int list[201];
double f[1001][1001];

int main()
{
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    cin>>T;
    for (int i=1;i<=200;i++)
        list[i]=(i*2-1)*i;
    for (int Case=1;Case<=T;Case++){ 
        cin>>n>>x>>y;
        int p=1;
        while (list[p]<=n) p++;p--;
        int rest=n-list[p];
        int nownum=abs(x)+abs(y);
        //cout<<"p = "<<p<<endl;
        if (nownum<=p*2-2) 
           ans=1;
        else
        if (nownum>p*2) 
           ans=0;
        else{
             int now=rest;
             memset(f,0,sizeof(f));
             f[0][0]=1;
             for (int i=1;i<=p*2;i++) f[0][i]=f[0][i-1]*0.5;
             for (int i=1;i<=p*2;i++) f[i][0]=f[i-1][0]*0.5;
             for (int i=1;i<=p*2;i++)
                 for (int j=1;j<=p*2;j++){
                     if (i==p*2 && j==p*2) f[i][j]=f[i-1][j]+f[i][j-1];else
                     if (j==p*2) f[i][j]=f[i-1][j]+f[i][j-1]*0.5;else
                     if (i==p*2) f[i][j]=f[i-1][j]*0.5+f[i][j-1];else
                     f[i][j]=f[i-1][j]*0.5+f[i][j-1]*0.5;
                 }
             //for (int i=0;i<=p*2;i++) for (int j=0;j<=p*2;j++) cout<<"f["<<i<<"]["<<j<<"] = "<<f[i][j]<<endl;
             int nowdir=abs(y)+1;
             ans=0;
             for (int i=nowdir;i<=rest;i++) ans+=f[i][rest-i];                 
        }
        cout<<"Case #"<<Case<<": "<<ans<<endl;
    }
} 
