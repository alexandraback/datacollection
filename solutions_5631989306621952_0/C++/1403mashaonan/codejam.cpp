#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std;
#define   MAX           500005
#define   MAXN          1000005
#define   maxnode       105
#define   sigma_size    2
#define   lson          l,m,rt<<1
#define   rson          m+1,r,rt<<1|1
#define   lrt           rt<<1
#define   rrt           rt<<1|1
#define   middle        int m=(r+l)>>1
#define   LL            long long
#define   ull           unsigned long long
#define   mem(x,v)      memset(x,v,sizeof(x))
#define   lowbit(x)     (x&-x)
#define   pii           pair<int,int>
#define   bits(a)       __builtin_popcount(a)
#define   mk            make_pair
#define   limit         10000

//const int    prime = 999983;
const int    INF   = 0x3f3f3f3f;
const LL     INFF  = 0x3f3f;
const double pi    = acos(-1.0);
const double inf   = 1e18;
const double eps   = 1e-9;
const LL     mod   = 1e9+7;
const ull    mxx   = 1333331;

/*****************************************************/
inline void RI(int &x) {
      char c;
      while((c=getchar())<'0' || c>'9');
      x=c-'0';
      while((c=getchar())>='0' && c<='9') x=(x<<3)+(x<<1)+c-'0';
}
/*****************************************************/

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,kase=0;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        kase++;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(ans=="") ans+=s[i];
            else{
                if(s[i]>=ans[0]) ans=s[i]+ans;
                else ans=ans+s[i];
            }
        }
        printf("Case #%d: ",kase);
        cout<<ans<<endl;
    }
    return 0;
}




