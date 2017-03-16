#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("inp.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j,k,n,ca=1,d;
    ll a[200],c,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %d %lld",&c,&d,&v);
//        printf("%lld %d %lld\n",c,d,v);
        for(i=0;i<d;i++)
            scanf("%lld",&a[i]);
//        for(i=0;i<d;i++)
//            printf("%lld ",a[i]);
//        printf("\n");
        n=0LL;
        i=0;
        int ans=0;
        while(i<d&&n<v)
        {
            if(n+1LL<a[i])
            {
                ans++;
                n=n+(c*(n+1LL));
            }
            else
            {
                n=n+(c*a[i]);
                i++;
            }
        }
        while(n<v)
        {
            n=n+((n+1LL)*c);
            ans++;
        }

        printf("Case #%d: %d\n",ca,ans);
        ca++;
    }
    return 0;
}
