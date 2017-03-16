#include<cstdio>
using namespace std;
const int MAXN=105;
int pd[MAXN];
int main() {
    //freopen("C-large.in","r",stdin);
    //freopen("C-large.out","w",stdout);
    int t,c,d,v;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d%d%d",&c,&d,&v);
        for(int i=0; i<d; ++i)
            scanf("%d",&pd[i]);
        int ans=0,k=0;
        long long sum=0;
        for(long long i=1; i<=v; ++i) {
            while(k<d&&pd[k]<=i)
                sum+=pd[k++];
            if(sum*c<i) {
                ++ans;
                sum+=i;
                i=sum*c-1;
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}
