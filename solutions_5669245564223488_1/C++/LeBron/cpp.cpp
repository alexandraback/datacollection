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

long has[200];
long long fact[2000],n,ts,m,ar[200][200];
string st[200];
vector<long> v,v1;
long tests;
long long used[2000],comps;
long long ans;
long long flag;
long lead[110][110];

void dfs(long ve)
{
 used[ve]=1;
 v.push_back(ve);
 for (int i=0;i<26;i++)
  if (ar[ve][i]==1&&used[i]==0)
   dfs(i); 
}

void solve(vector<long> v)
{
 long pr[26],su[26],in[26];
 long bl[26];
 for (int i=0;i<26;i++)
  pr[i]=su[i]=in[i]=bl[i]=0;
  
/*  for (int i=0;i<v.size();i++)
   cout<<v[i]<<"%%";
   cout<<endl;*/
 for (int i=0;i<v.size();i++)
 {
  long t=v[i];
  long q=0;
  while (q<st[t].size()&&st[t][q]==st[t][0])++q;
  if (q<st[t].size()){
    if (pr[st[t][0]-'a']){ans=0;return ;}
   pr[st[t][0]-'a']=t;}
   q=st[t].size()-1;
   while (q>=0&&st[t][q]==st[t][st[t].size()-1])--q;
   if (q>=0)
   {
    if (su[st[t][st[t].size()-1]-'a']){ans=0;return ;}
    su[st[t][st[t].size()-1]-'a']=t;
   }
   long nw=0;
   for (int q=1;q<st[t].size();q++)
   {
    if (st[t][q]!=st[t][q-1])
    {
     if (nw>0){in[st[t][q-1]-'a']++;}
     nw=q;
    }
   }
   long er=0;
   for (int q=0;q<st[t].size();q++)
    if (st[t][q]!=st[t][0])er=1;
    if (er==0)bl[st[t][0]-'a']++;
 }
 for (int i=0;i<26;i++)
  if (in[i]>1){ans=0;return ;}
 for (int i=0;i<26;i++)
  if (in[i]>0&&(pr[i]+su[i]>0)){ans=0;return ;}
  
  for (int i=0;i<=100;i++)
   for (int j=0;j<=100;j++)
     lead[i][j]=0;
  for (int i=0;i<26;i++)
   if (pr[i]>0&&su[i]>0)
    lead[su[i]][pr[i]]=1;
  for(int k=0;k<=100;k++)
   for (int i=0;i<=100;i++)
    for (int j=0;j<=100;j++)
     lead[i][j]=(lead[i][j]|(lead[i][k]&lead[k][j]));
  for (int i=0;i<=100;i++)
   if (lead[i][i]){ans=0;return;}
  
  for (int i=0;i<26;i++)
   ans=ans*fact[bl[i]]%bs;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
 fact[0]=1;
 for (int i=1;i<=100;i++)
 fact[i]=fact[i-1]*i%bs;
 
cin>>tests;
for(;tests;--tests)
{
 ++ts;
 cin>>n;
 for (int i=0;i<26;i++)
  has[i]=0;
 for (int i=1;i<=n;i++)
 cin>>st[i];
 for (int i=1;i<=n;i++)
  for (int j=0;j<st[i].size();j++)
   has[st[i][j]-'a']=1;
   
 for (int i=0;i<26;i++)
  for (int j=0;j<26;j++)
   ar[i][j]=0;
 for (int i=1;i<=n;i++)
  for (int j=0;j<st[i].size();j++)
   for (int q=0;q<st[i].size();q++)
    ar[st[i][j]-'a'][st[i][q]-'a']=1;
 
 for (int i=0;i<26;i++)
  used[i]=0;
 comps=0;
 ans=1;
 for(int i=0;i<26;i++)
  if (used[i]==0&&has[i]==1)
  {++comps;
 // cout<<"%"<<char(i+'a')<<endl;
   v.clear();
   dfs(i);
   v1.clear();
   for (int j=1;j<=n;j++){
       flag=0;
    for (int q=0;q<st[j].size();q++)
     for (int p=0;p<v.size();p++)
      if (st[j][q]==v[p]+'a')
      flag=1;
   if (flag)v1.push_back(j);}
   solve(v1);
  }
//  cout<<comps<<endl;
  ans=ans*fact[comps]%bs;
  cout<<"Case #"<<ts<<": "<<ans<<endl;
}

cin.get();cin.get();
return 0;}
