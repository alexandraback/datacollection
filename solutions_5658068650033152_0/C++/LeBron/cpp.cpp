/*
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,m,k,s,ans,t;
long ts,tests;
long done[30][30],ar[30][30];

long cbits(long x)
{
 long r=0;
 for (int i=0;i<=20;i++)
  if (x&(1<<i))++r;
 return r;
}

void generate(long x)
{
 for (int i=0;i<=n+1;i++)
  for (int j=0;j<=m+1;j++)
   ar[i][j]=0;
 for (int i=0;i<n;i++)
  for (int j=0;j<m;j++)
  {
   t=m*i+j;
   if (x&(1<<t))ar[i+1][j+1]=1;
  }
}

void solve(long a,long b)
{
 if (a<=0||a>n||b<=0||b>m)return;
 done[a][b]=2;
 if (ar[a-1][b]==0&&done[a-1][b]==1)solve(a-1,b);
 if (ar[a+1][b]==0&&done[a+1][b]==1)solve(a+1,b);
 if (ar[a][b-1]==0&&done[a][b-1]==1)solve(a,b-1);
 if (ar[a][b+1]==0&&done[a][b+1]==1)solve(a,b+1);
}

long calc()
{
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
  {
   done[i][j]=1;
  }
 for (int i=1;i<=m;i++)
 {
  if (ar[1][i]==0)solve(1,i);
  if (ar[n][i]==0)solve(n,i);
 }
 for (int i=1;i<=n;i++)
 {
  if (ar[i][1]==0)solve(i,1);
  if (ar[i][m]==0)solve(i,m);
 }
 
  long res=0;
  for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
    if (done[i][j]==1&&ar[i][j]==0)++res;
  return res;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>tests;
for (;tests;--tests)
{
 ++ts;
 cin>>n>>m>>k;
 s=n*m;
 ans=n*m;
 for (int mask=0;mask<(1<<s);mask++)
 {
  long t=cbits(mask);
  if (t>=ans)continue;
  generate(mask);
 long p=calc()+t;

  if (p>=k)ans=t;
 }
 cout<<"Case #"<<ts<<": "<<ans<<endl;
}

cin.get();cin.get();
return 0;}
