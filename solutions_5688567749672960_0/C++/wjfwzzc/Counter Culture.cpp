#include<cstdio>
#include<cstring>
using namespace std;
const int num[]= {10,19,109,199,1099,1999,10999,19999,109999,199999,1099999,1999999,10999999,19999999};
int main() {
    //freopen("A-small-attempt2.in","r",stdin);
    //freopen("A-small-attempt2.out","w",stdout);
    int t;
    long long n;
    char str[15];
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%lld",&n);
        if(n/10==0) {
            printf("Case #%d: %lld\n",cas,n);
            continue;
        }
        long long ans=0,base,tmp=0;
        if(n%10==0) {
            ++ans;
            --n;
        }
        int k=0;
        for(base=1; base<=n; base*=10)
            ans+=num[k++];
        base/=10;
        ans-=num[k-1];
        sprintf(str,"%lld",n);
        int len=strlen(str);
        bool flag=str[0]=='1';
        for(int i=1; flag&&i<len>>1; ++i)
            flag=str[i]=='0';
        if(flag)
            tmp=base;
        else {
            for(int i=(len>>1)-1; ~i; --i)
                tmp=tmp*10+str[i]-'0';
            ans+=tmp+1;
            tmp=0;
            for(int i=0; i<len>>1; ++i)
                tmp=tmp*10+str[i]-'0';
            for(int i=len>>1; i<len; ++i)
                tmp*=10;
            tmp+=1;
        }
        ans+=n-tmp;
        printf("Case #%d: %lld\n",cas,ans);
    }
}
