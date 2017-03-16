#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long n,m,c;
    int ans[MAXN][MAXN],cur,T;
    bool isLarger,isEqual;
    cin>>T;
    for (int test=1;test<=T;test++)
    {
        cin>>n>>m;
        cout<<"Case #"<<test<<": ";
        isLarger = false;
        isEqual = false;
        c = 1;
        for (int i=0;i<n-2;i++)
        {
            c*=2;
            if (c>m)
            {
                isLarger = true;
                break;
            }
            if (c==m) isEqual = true;
        }

        if (c>m) isLarger = true;
        if (c==m) isEqual = true;

        if ((!isLarger)&&(!isEqual))
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"POSSIBLE"<<endl;
        memset(ans,0,sizeof(ans));
        for (int i=1;i<n;i++)
        {
            for (int j=i+1;j<n;j++) ans[i][j] = 1;
        }
        if (isLarger)
        {
            cur = 2;
            while (m>0)
            {
                if (m&1) ans[cur][n] = 1;
                m/=2;
                cur++;
            }
        }
        else
        {
            for (int i=1;i<n;i++) ans[i][n] = 1;
        }

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++) cout<<ans[i][j];
            cout<<endl;
        }
    }

    return 0;
}
