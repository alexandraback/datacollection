#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define lx(x) (x<<1)
#define rx(x) (x<<1|1)
#define debug puts("here")
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define foreach(i,vec) for(unsigned i=0;i<vec.size();i++)
#define pb push_back
#define RD(n) scanf("%d",&n)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define RD4(x,y,z,w) scanf("%d%d%d%d",&x,&y,&z,&w)

/******** program ********************/

const int MAXN = 105;

int a[MAXN],n,now;

int main(){

#ifndef ONLINE_JUDGE
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
#endif

    int ncase;
    RD(ncase);
    rep1(Ncase,ncase){
        printf("Case #%d: ",Ncase);
        RD2(now,n);
        rep1(i,n)
            RD(a[i]);

        sort(a+1,a+n+1);

        if(now==1){
            cout<<n<<endl;
            continue;
        }

        int ans = n;
        int cnt = 0;

        rep1(i,n){
            if(now>a[i])
                now += a[i];
            else{
                ans = min( ans,n-i+1+cnt );
                while(now<=a[i]){
                    now = now*2-1;
                    cnt ++;
                }
                now += a[i];
            }
        }

        ans = min(ans,cnt);

        cout<<ans<<endl;
    }

	return 0;
}
