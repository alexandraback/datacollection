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

long tests,n,h[1000000],dd[1000],dp[1000],
ds[1000],d[1000],nn[1000],w[1000],e[1000],s[1000];
vector<pair<long, long> > upd;
long span;
long ww,ee,fl;
long ans,as,ts;

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>tests;
for (;tests;--tests)
{
    cin>>n;
    for (int i=0;i<=800;i++)
    h[i]=0;ans=0;
    
    for (int i=1;i<=n;i++)
    {
        cin>>d[i]>>nn[i]>>w[i]>>e[i]>>s[i]>>dd[i]>>dp[i]>>ds[i];
    }
    
    for (int day=0;day<=700000;day++)
    {
        upd.clear();
        for (int i=1;i<=n;i++)
        if (day>=d[i])
        {
         span=day-d[i];
         if (span%dd[i])continue;
         span/=dd[i];
         if (span>=nn[i])continue;
         ww=w[i]+400+span*dp[i];
         ee=ww+e[i]-w[i];
         as=s[i]+span*ds[i];
         fl=0;
         for (int j=ww;j<ee;j++)
         if (h[j]<as){upd.push_back(make_pair(j,as));fl=1;}      
         if (fl)++ans;      
        }
        for (int i=0;i<upd.size();i++)
        h[upd[i].first]=max(h[upd[i].first],upd[i].second);
    }
    ++ts;
    cout<<"Case #"<<ts<<": ";
    cout<<ans<<endl;
}
cin.get();cin.get();
return 0;}




