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

int a;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++){
        int n;
        cin>>n;
        set<int> s;
        s.clear();
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a);
                if(s.count(a)) s.erase(a);
                else s.insert(a);
            }
        }
        vector<int> ans;
        for(set<int>::iterator it=s.begin();it!=s.end();it++){
            ans.push_back(*it);
        }
        printf("Case #%d: ",ii);
        for(int i=0;i<ans.size();i++){
            printf("%d",ans[i]);
            if(i==ans.size()-1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
