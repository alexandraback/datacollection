#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e4;
int n;
int sum[maxn];
char buf[maxn];

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        scanf("%d%s",&n,buf);
        memset(sum,0,sizeof(sum));
        int ans=0;
        sum[0]=buf[0]-'0';
        for(int i=1;i<=n;i++){
            if(sum[i-1]<i){
                ans+=i-sum[i-1];
                sum[i-1]=i;
            }
            sum[i]=sum[i-1]+buf[i]-'0';
        }
        printf("Case #%d: %d\n",ti,ans);
    }
    return 0;
}
