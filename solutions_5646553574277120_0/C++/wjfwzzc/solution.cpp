#include<cstdio>
using namespace std;
const int MAXN=8;
int pd[MAXN];
int main() {
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("C-small-attempt0.out","w",stdout);
    int t,c,d,v;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d%d%d",&c,&d,&v);
        for(int i=0; i<d; ++i)
            scanf("%d",&pd[i]);
        int ans=0,sum=0,k=0;
        for(int i=1; i<=v; ++i) {
            while(k<d&&pd[k]<=i)
                sum+=pd[k++];
            if(sum<i) {
                ++ans;
                sum+=i;
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}
