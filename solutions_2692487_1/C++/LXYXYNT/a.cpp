#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <sstream>
using namespace std;

typedef long long ll;
const double pi = acos(-1.0);
const double eps = 1e-8;

int a[111];
ll f[111][222];
int n,ans,k;

int main(){
    int _,cas=0;
    scanf("%d",&_);
    while (_--){
        ans=0;
        
        memset(f,0,sizeof(f));
        
        scanf("%d%d",&k,&n);
        for (int i=0;i<n;++i) scanf("%d",&a[i]);
        sort(a,a+n);
        
        f[0][0]=k;
        for (int i=0;i<n;++i)
            for (int j=0;j<=n;++j){
                if (f[i][j]==0) continue;
                f[i+1][j+1]=max(f[i+1][j+1],f[i][j]);
                if (f[i][j]==1) continue;
                
                if (a[i]<f[i][j]) f[i+1][j]=max(f[i+1][j],f[i][j]+a[i]);
                
                int tmp=0;
                ll tnow=f[i][j];
                while (tnow<=a[i]){
                    tnow=tnow*2ll-1ll;
                    ++tmp;
                }
                if (j+tmp>n) continue;
                f[i+1][j+tmp]=max(f[i+1][j+tmp],tnow+a[i]);
            }
        for (int i=0;i<=n;++i)
            if (f[n][i]){
                ans=i;
                break;
            }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
