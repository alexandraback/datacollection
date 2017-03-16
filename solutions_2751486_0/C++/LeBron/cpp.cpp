/*

*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
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
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long bdd[8000000],ans,lgood,calc;
string st;
long n,tests,bd,ts;

bool bad(char c)
{if (c=='a')return false;
if (c=='e')return false;
if (c=='i')return false;
if (c=='o')return false;
if (c=='u')return false;
return true;
}

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
    ++ts;calc=0;
 cin>>st;cin>>bd;//cout<<"TS"<<ts<<" "<<st<<" "<<bd<<endl;
 n=st.size();
 
 for (int i=0;i<n;i++)
 bdd[i]=0;
 
 for (int i=0;i<n;i++)
 {
     if (bad(st[i]))++calc;
     else calc=0;
     if(calc>=bd)bdd[i-bd+1]=1;
 }   
/* for (int i=0;i<n;i++)
 cout<<bdd[i]<<" ";
 cout<<endl;
 */lgood=-1;
 ans=0;
 for (long long i=0;i<n;i++)
 {
  if (i>=bd-1&&bdd[i-bd+1]==1)
  lgood=i-bd+1; 
  //cout<<i<<" "<<lgood<<endl; 
  ans+=lgood+1;
 }
 cout<<"Case #"<<ts<<": "<<ans<<endl;
}

cin.get();cin.get();
return 0;}




