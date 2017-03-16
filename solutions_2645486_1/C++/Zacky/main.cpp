#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10005;

int value[MAXN];
int main()
{
   freopen("B-large.in","r",stdin);
   freopen("B-large.out","w",stdout);
   int cas,T,E,R,N,i,j,e,x;
   long long ans;

   scanf("%d",&T);
   for(cas = 1;cas <= T;++cas) {
    scanf("%d %d %d",&E,&R,&N);
    for(i = 1;i <= N;++i) {
        scanf("%d",&value[i]);
    }
    ans = 0;
    e = E;
    for(i = 1;i <= N;++i) {
        for(j = i + 1;j <= N;++j) {
            if(value[j] > value[i]) break;
        }
        if(j > N) {
            ans += 1LL * value[i] * e;
            e = min(E,R);
        }
        else {
          x = max(e + R - E,0);
          ans += 1LL * value[i] * x;
          e = e - x + R;
        }
    }
    cout<<"Case #"<<cas<<": "<<ans<<endl;
   }
}
