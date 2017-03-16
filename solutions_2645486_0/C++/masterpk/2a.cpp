#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<sstream>
#include<bitset>
#include<deque>
#include<utility>
#include<cstdlib>
#include<iomanip>
#include<cctype>
#include<climits>
#include<iostream>
using namespace std;
#define ll             long long
#define ull            unsigned long long
string tostr(long long x) { stringstream ss; ss << x; return ss.str(); }
long long toint(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }
int e,r,n,max1;
int v[100];
int dp[11][11];
void rec(int pos,int en,int gain)
{
    if(pos==n)
    {
        //cout<<en<<"\n";
        max1=max(max1,gain);
        return ;
    }
    for(int i=0;i<=en;i++)
    {
        if((en-i+r)<=e)
        rec(pos+1,(en-i)+r,gain+v[pos]*i);
        else
        rec(pos+1,e,gain+v[pos]*i);
    }
return ;
}
int main()
{
freopen("B-small-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int test;
cin>>test;
for(int tt=1;tt<=test;tt++)
{

    cin>>e>>r>>n;
    for(int i=0;i<n;i++)
    cin>>v[i];
    max1=0;
    rec(0,e,0);
    cout<<"Case #"<<tt<<": "<<max1<<endl;

}

return 0;
}
