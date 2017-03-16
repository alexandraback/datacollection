#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 100700
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

int str[maxn];
int main(){
    freopen("B-small-attempt0 (3).in","r",stdin);
    freopen("outpu.txt","w",stdout);
    int i,j,k;
    int n,m;
    int _,cas=1;
    cin>>_;
    while(_--){
        scanf("%d%d%d",&n,&m,&k);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int tmp = i&j;
                if(tmp<k)ans++;
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
