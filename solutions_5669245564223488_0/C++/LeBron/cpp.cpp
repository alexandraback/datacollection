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

long tests;
string st[2000];
long ts;
long n;
long has[2000];
long blocks[2000],dif,tb;
long dp[1<<10][30][30];
long long answ;
long nend;

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
 cin>>n;
 for (int j=0;j<26;j++)
  has[j]=0;
 for (int i=0;i<n;i++)
 {
  cin>>st[i];
  blocks[i]=0;
  for (int j=1;j<st[i].size();j++)
   if (st[i][j]!=st[i][j-1])++blocks[i];
   for (int j=0;j<st[i].size();j++)
    has[st[i][j]-'a']=1;
 }
 dif=0;
 for (int i=0;i<26;i++)
  dif+=has[i];
  
 
 for (int mask=0;mask<(1<<n);mask++)
  for (int last=0;last<26;last++)
   for (int blocks=0;blocks<=dif;blocks++)
   dp[mask][last][blocks]=0;
 
 dp[0][0][0]=1;
 
 for (int mask=0;mask<(1<<n);mask++)
  for (int last=0;last<26;last++)
   for (int qblocks=0;qblocks<=dif;qblocks++)
    if (dp[mask][last][qblocks])
    {
     for (int ad=0;ad<n;ad++)
     {
      if (mask&(1<<ad))continue;
      tb=qblocks;
      if (mask>0&&st[ad][0]-'a'!=last)
      ++tb;
      if (mask==0)++tb;
      tb+=blocks[ad];
      if (tb>dif)continue;
      nend=st[ad][st[ad].size()-1]-'a';
      dp[mask|(1<<ad)][nend][tb]=dp[mask|(1<<ad)][nend][tb]+dp[mask][last][qblocks];
      dp[mask|(1<<ad)][nend][tb]%=bs;
     }
    }
 answ=0;
 for (int i=0;i<26;i++)
 {
  answ+=dp[(1<<n)-1][i][dif];
 }
 cout<<"Case #"<<ts<<": ";
 cout<<answ%bs<<endl;
}

cin.get();cin.get();
return 0;}
