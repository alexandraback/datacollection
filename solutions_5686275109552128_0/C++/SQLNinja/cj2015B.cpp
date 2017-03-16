#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,a,i,t;
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int a;cin>>a;
        int b[a];
        for(i=0;i<a;i++) cin>>b[i];
        sort(b,b+a);
        int ans=0;
        while(b[a-1]>3)
        {
            b[a-1]=b[a-1]/2+b[a-1]%2;
            sort(b,b+a);
            ans++;
        }
        if(b[a-1]<=3) ans+=b[a-1];
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;

}
