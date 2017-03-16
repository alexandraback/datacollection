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

string st;
long long tests;

pair<long long, long long> parse(string st)
{
 long er=0;
 long long a,b;
 a=b=0;
 for (int i=0;i<st.size();i++)
 {
  if (st[i]=='/'){++er;continue;}
  if (er==0)a=a*10+st[i]-48;
  else b=b*10+st[i]-48;
 }
 return make_pair(a,b);
}

pair<long long, long long> tp;
long long a;
long ts;

long long gcd(long long a,long long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

bool nice(long long x)
{
 for (int i=0;i<=40;i++)
  if (x==(1ll<<i))return true;
  return false;
}

long solve(long long a,long long b)
{
 long long res=0;
 while (a<b){++res;a*=2;}
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
 cin>>st;
 tp=parse(st);   
 ++ts;
 cout<<"Case #"<<ts<<": ";
 long long q=(1ll<<40);
// cout<<q%tp.second<<endl;
// cout<<tp.first<<" "<<tp.second<<endl;
 a=tp.second;
 q=gcd(tp.first,tp.second);
 tp.first/=q;
 tp.second/=q;
 if (!nice(tp.second))cout<<"impossible"<<endl;
 else cout<<solve(tp.first,tp.second)<<endl;
}

cin.get();cin.get();
return 0;}
