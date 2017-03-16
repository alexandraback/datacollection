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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
 
using namespace std;

long n,tests,ts,ar[1<<20],ans;
map<long, long> mapp;
set<long> done;
long cuts;
long U;
long dp[2000];

int get(int x)
{
    if (done.find(x)!=done.end())
     return mapp[x];
    if (x<=U)return 0;
    long a,b;
    a=x/2;
    b=x-a;
    long res=get(a)+get(b)+1;
    done.insert(x);
    mapp[x]=res;
    return res;
}
int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
for (;tests;--tests)
{
    ++ts;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    ans=1e9;
    
    long mx=0;
    for (int i=1;i<=n;i++)
     mx=max(mx,ar[i]);
     
    for (int upper=1;upper<=mx;upper++)
    {   
        for (int j=0;j<=mx;j++)
         dp[j]=1e9;
        for (int j=1;j<=upper;j++)
         dp[j]=0;
        for (int j=1;j<=mx;j++)
        {
            for (int q=1;q*2<=j;q++)
             dp[j]=min(dp[j],dp[q]+dp[j-q]+1);
        }
     U=upper;
        mapp.clear();
        done.clear();
        cuts=0;
        for (int i=1;i<=n;i++)
        {
        int q=ar[i];
        cuts+=dp[q];
        }
        ans=min(ans,upper+cuts);
    }
    
    cout<<"Case #"<<ts<<": "<<ans<<endl;
}

cin.get();cin.get();
return 0;}
