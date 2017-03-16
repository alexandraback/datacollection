//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-8
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;

long bt,wh1,wh,tt,tests,bx,by,n,h,m,btt,tss,c[1000][1000],d[1000][1000],f[1000][1000],arp[1000][1000];
long gettime(long cc,long ff,long dd,long x,long y)
{
     //wh=max(h-dd,f[x][y]);
     if (cc-ff<50)return 1000000000;
     if (f[x][y]>cc-50)return 1000000000;
     if (ff+50>c[x][y])return 1000000000;
     wh=h-dd;
     bt=0;
     wh1=cc-50;
     if (wh1<wh)bt+=wh-wh1;
     wh=h-dd-bt;
     wh-=f[x][y];
     if (wh>=20)return dd+bt+10; else return dd+bt+100;
}

long gettime1(long cc,long ff,long dd,long x,long y)
{
     wh=max(h-f[x][y],h-f[x][y]);
     if (cc-ff<50)return 1000000000;
     if (cc-h<50)return 1000000000;
     if (cc-f[x][y]<50)return 1000000000;
     if (h>cc-50)return 1000000000;
     if (ff+50>c[x][y])return 1000000000;
     
     if (wh>=20)return 0; else return 0;
}

int main(){
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{tss++;
cout<<"Case #"<<tss<<":";

cin>>h>>n>>m;

for (int i=0;i<=n+3;i++)
for (int j=0;j<=m+3;j++)
{
    c[i][j]=f[i][j]=0;
    d[i][j]=1000000000;
    arp[i][j]=0;
}
d[1][1]=0;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
arp[i][j]=0;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
cin>>c[i][j];

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
cin>>f[i][j];

arp[1][1]=1;

long fl=1;
while (fl)
{
      fl=0;
 btt=1000000000;
 bx=0;by=0;
 for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
     tt=1000000000;
     if (arp[i-1][j]==1)tt=min(tt,gettime1(c[i][j],f[i][j],d[i-1][j],i-1,j));
     if (arp[i+1][j]==1)tt=min(tt,gettime1(c[i][j],f[i][j],d[i+1][j],i+1,j));
     if (arp[i][j-1]==1)tt=min(tt,gettime1(c[i][j],f[i][j],d[i][j-1],i,j-1));
     if (arp[i][j+1]==1)tt=min(tt,gettime1(c[i][j],f[i][j],d[i][j+1],i,j+1));
     if (tt<btt&&arp[i][j]==0)
     {bx=i;by=j;btt=tt;}
  }      
 // cout<<bx<<" "<<by<<endl;
 if (bx>0&&by>0)
 {fl=1; arp[bx][by]=1;
  d[bx][by]=btt;}
  
}

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
arp[i][j]=0;

for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
if (d[i][j]==0)arp[i][j]=1;

arp[1][1]=1;

arp[1][1]=1;
d[1][1]=0;

/*
for (int i=1;i<=n;i++){
for (int j=1;j<=m;j++)cout<<d[i][j]<<" ";
cout<<endl;}
*/

while (arp[n][m]==0)
{
 btt=1000000000;
 bx=0;by=0;
 for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
     tt=1000000000;
     if (arp[i-1][j]==1)tt=min(tt,gettime(c[i][j],f[i][j],d[i-1][j],i-1,j));
     if (arp[i+1][j]==1)tt=min(tt,gettime(c[i][j],f[i][j],d[i+1][j],i+1,j));
     if (arp[i][j-1]==1)tt=min(tt,gettime(c[i][j],f[i][j],d[i][j-1],i,j-1));
     if (arp[i][j+1]==1)tt=min(tt,gettime(c[i][j],f[i][j],d[i][j+1],i,j+1));
     if (tt<btt&&arp[i][j]==0)
     {bx=i;by=j;btt=tt;}
  }      
 //cout<<bx<<" "<<by<<endl;
  arp[bx][by]=1;
  d[bx][by]=btt;
  
}

cout<<" ";
cout.precision(1);
cout<<fixed<<d[n][m]*1.0/10<<endl;

}
cin.get();cin.get();
return 0;}

