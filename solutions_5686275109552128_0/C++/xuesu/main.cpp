#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e3+3;
const int maxp=1e3+3;
int n;
int num[maxp];

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        int ans=0;
        for(int i=0;i<n;i++){
            int tmp;
            scanf("%d",&tmp);
            num[tmp]++;
            ans=max(tmp,ans);
        }
        int mx=ans;
        for(int i=1;i<=mx;i++){
            int tmp=0;
            for(int j=i+1;j<=mx;j++){
                tmp+=(j+i-1)/i*num[j]-num[j];
            }
            tmp+=i;
            ans=min(tmp,ans);
        }
        printf("Case #%d: %d\n",ti,ans);
    }
    return 0;
}
