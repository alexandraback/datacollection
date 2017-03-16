#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
typedef double db;
const int maxn = 111111;
#define mp make_pair
#define pb push_back
#define OPEN(s) freopen(s,"r",stdin);
#define SAVE(s) freopen(s,"w",stdout);

int n, m;
db p[ maxn ], ps[ maxn ],bs[maxn];
db s,f,ans;

db typ(){
   db ans = 0.0;
   ans += s * (m-n+1);
   ans += f * (m-n+1+m+1);
   return ans;
}

db bak(int x){
   return x+ps[n-x-1]*(m-n+1+x)+(1.0-ps[n-x-1])*(m-n+1+x+m+1);
}

db ent(){
   return 1+m+1;
}

int main() {
    OPEN("D:\\A-small-attempt0.in");
    SAVE("D:\\A-s.out");
    int T, cas = 0;
    cin >> T;
    while(T -- ){
         cin >> n >> m;
         for(int i=0;i<n;++i) cin >> p[i];
         ps[0]=p[0];
         for(int i=1;i<n;++i) ps[i]=ps[i-1]*p[i];
         bs[n-1]=p[n-1];
         for(int i=n-2;i>=0;--i) bs[i]=bs[i+1]*p[i];
         s=1.0;
         for(int i=0;i<n;++i) s*=p[i];
         f=1.0-s;
         ans=1e10;
         ans = min( ans, typ());
         for(int i=1;i<=n;++i) ans = min(ans, bak(i));
         ans = min(ans, ent());
         ++ cas;
         printf("Case #%d: %.6f\n",cas, ans);               
    }
    return 0;
}
