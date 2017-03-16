#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

long long l[1000];
int T,n;
long long a,b;
char s[100];
bool check(long long t){
    sprintf(s,"%lld",t);
    int m = strlen(s);
    for(int i=0; i<m; ++i)
        if(s[i]!=s[m-i-1]) return false;
    return true;
}
bool cmp(long long x, long long y){
    return x*x<=y;
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("c.out","w",stdout);

    n=0;
    for(int i=0;i<10000;++i){
        long long t = i;
        if (check(t) && check(t*t))
            l[n++]=i;
    }

    cin>>T;
    for(int cs=1;cs<=T;++cs){
        cin>>a>>b;
//        int ans = (lower_bound(l, l+n, int(sqrt(b+1)+1e-8))
//                 -lower_bound(l, l+n, int(sqrt(a-1)+1e-8)))-1;
//                 cout<<int(sqrt(a-1)+1e-8)<<' '<<int(sqrt(b+1)+1e-8)-1<<endl;
         int ans = lower_bound(l, l+n, b, cmp)
                 -lower_bound(l, l+n, a-1, cmp);

        cout<<"Case #"<<cs<<": "<<ans<<endl;
    }
}
