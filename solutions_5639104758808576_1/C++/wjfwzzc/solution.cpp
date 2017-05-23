#include<cstdio>
using namespace std;
const int MAXN=1005;
char s[MAXN];
int main() {
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int t,smax;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d%s",&smax,s);
        int ans=0,cnt=0;
        for(int i=0; i<=smax; ++i) {
            if(cnt<i) {
                ans+=i-cnt;
                cnt=i;
            }
            cnt+=s[i]-'0';
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}
