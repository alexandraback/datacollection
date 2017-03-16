#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int a[1007];
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas=0,t,tmp,n;

    cin >> t;
    while (cin >> n) {
        for (int i=0;i<n;++i){
            cin >> a[i];
        }
        int ans=100000000;
        for (int x=1;x<=1000;++x){
            tmp=0;
            for (int i=0;i<n;++i) {
                tmp+=(a[i]+x-1)/x-1;
            }
            ans=min(ans,x+tmp);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
