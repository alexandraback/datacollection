#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int t,n,m,b[105][105],cnt;
bool gogo(){
     if(n==1||m==1)return true;
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
           bool flag1=0,flag2=0,flag3=0,flag4=0;
           /*if(i==1)flag1=true;
           if(i==n)flag2=true;
           if(j==1)flag3=true;
           if(j==m)flag4=true;*/
           for(int ii=1;ii<i;ii++)
              if(b[ii][j]>b[i][j])flag1=true;
           for(int ii=i+1;ii<=n;ii++)
              if(b[ii][j]>b[i][j])flag2=true;
           for(int jj=1;jj<j;jj++)
              if(b[i][jj]>b[i][j])flag3=true;
           for(int jj=j+1;jj<=m;jj++)
              if(b[i][jj]>b[i][j])flag4=true;
           if((flag1||flag2)&&(flag3||flag4))return false;
        }
     return true;
}
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
       cin>>n>>m;
       memset(b,0,sizeof(b));
       for(int i=1;i<=n;i++)
          for(int j=1;j<=m;j++)
             cin>>b[i][j];
       printf("Case #%d: %s\n",k,gogo()?"YES":"NO");
    }
    //system("pause");
    return 0;
}
