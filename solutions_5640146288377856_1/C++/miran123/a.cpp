#include<bits/stdc++.h>

using namespace std;
int main()
{
    freopen("in1.in","r",stdin);
    freopen("out1.out","w",stdout);
    int t,cas = 0;
    cin>>t;
    while(t--)
    {
        cas++;
        int r,c,w;
        printf("Case #%d: ",cas);
        cin>>r>>c>>w;
        int ans = (c/w)*(r-1);
        ans += c/w + (w-1);
        if(c%w) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
