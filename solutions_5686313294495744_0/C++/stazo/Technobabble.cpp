#include<bits/stdc++.h>
using namespace std;
string s[20],t[20];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int n,tt,i,j,ans=0,x,y,k,ct,mc,nub=1;
    cin >> tt;
    while(tt--)
    {
        cin >> n;
        mc=0;
        for(i=0;i<n;i++)
            cin >> s[i] >> t[i];
        for(i=1;i<(1<<n);i++)
        {
            ct=0;
            for(j=0;j<n;j++)
            {
                if(((1<<j)&i)!=0)
                    continue;
                x=0;
                y=0;
                for(k=0;k<n;k++)
                {
                    if(k!=j&&((1<<k)&i)!=0)
                    {
                        if(s[k]==s[j])
                            x=1;
                        if(t[k]==t[j])
                            y=1;
                    }
                }
                ct++;
                if(x==0||y==0)
                    break;
            }
            if(j==n)
                mc=max(mc,ct);
        }
        printf("Case #%d: %d\n",nub++,mc);
    }
}
