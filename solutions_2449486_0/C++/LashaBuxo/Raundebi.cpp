//Lasha Bukhnikashvili
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#define INF 1000001
#define Pi 3.14159265358
#define mod9 %1000000009
#define mod7 %1000000007
#define time clock()/(double)CLOCKS_PER_SEC
using namespace std;
 string ans;
 int T,y,i,j,n,m,row[101],col[101],a[100][100];
int main(){
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
   cin>>T;
   y=1;
   while (y<=T){
         cin>>n>>m;
         ans="";
         for (i=1;i<=max(n,m);i++)
             col[i]=row[i]=-INF;
         for (i=1;i<=n;i++)
             for (j=1;j<=m;j++)
                 cin>>a[i][j];
         for (i=1;i<=n;i++)
             for (j=1;j<=m;j++){
                 row[i]=max(row[i],a[i][j]);
                 col[j]=max(col[j],a[i][j]);
             };
         for (i=1;i<=n;i++)
             for (j=1;j<=m;j++)
                 if (a[i][j]!=row[i] && a[i][j]!=col[j]) ans="NO";
         if (ans=="") ans="YES";
         cout<<"Case #"<<y<<": "<<ans<<endl;
          y++;
   };   
 return 0;
}

