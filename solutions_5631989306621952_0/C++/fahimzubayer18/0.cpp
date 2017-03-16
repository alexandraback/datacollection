#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
bool bi[1002];

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);


    int a,b,c,d,e,x,y,z,n,m;

    int t;
    scanf("%d",&t);

    for(int te=1;te<=t;te++)
    {
        printf("Case #%d: ",te);
        cin>>s;
        string ans;
        ans="";

        z=s.size()-1;

        for(a=0;a<=z;a++) bi[a]=false;

        while(1)
        {
            if(z<0) break;
            x=z;
            for(a=z-1;a>=0;a--)
            {
                if(s[a]>s[x])
                {
                    x=a;
                }
            }
            bi[x]=true;
            ans=ans+s[x];
            z=x-1;
        }
        for(a=0;a<s.size();a++)
        {
            if(bi[a]) continue;
            ans=ans+s[a];
        }
        cout<<ans<<endl;
    }

    return 0;
}
