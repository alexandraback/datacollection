#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
#define ll long long
const long long LINF = ~(((long long)0x1)<<63)/2;
const int INF=0X3F3F3F3F;
const double eps=1e-7;
ll solve(ll pre,ll now,ll n,int len,int start)
{
    ll ans=0;
    ans+=(pre+1-start)*(len-now);
    ans+=(now-pre+1-n)*((pre+1-start)+(len-now));
    ll p=now-pre+1-2;
    if(p>=n)
    {
        ans+=(p-n+1+1)*(p-n+1)/2;
    }
    //ans+=(now-pre+1-n+1+1)*(now-pre+1-n+1)/2-1;
   // cout<<pre<<" "<<now<<" "<<len<<" "<<start<<" "<<ans<<endl;
    return ans;
}
int main()
{
    int i,j,T;
    freopen("A-small-attempt1.in.txt","r",stdin);
    freopen("A-small-attempt1.out.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        string s;
        cin>>s;
        int n;
        scanf("%d",&n);
        int now=0;
        ll ans=0;
        int pre=0;
        int start=0;
        s.push_back('a');
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                if(i-pre>=n){
                    ans+=solve(pre,i-1,n,s.size()-1,start);
                    start=i-n+1;
                }
                pre=i+1;
            }
        }
        printf("Case #%d: ",cas);
        cout<<ans<<endl;
    }
    return 0;
}

