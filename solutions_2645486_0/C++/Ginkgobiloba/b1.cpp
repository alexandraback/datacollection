#include <iostream>
using namespace std;

int v[100];
int s[50][50];

int main()
{
    int e, r, n, t;
    cin>>t;
    for(int a=1; a<=t; ++a)
    {
        cin>>e>>r>>n;
        for(int i=1; i<=n; ++i)
            cin>>v[i];
        for(int i=0; i<=e; ++i)
            s[0][i]=0;
        for(int i=1; i<=n; ++i)
        {
            for(int j=0; j<=e; ++j)
                s[i][j]=-1;
            for(int j=0; j<=e; ++j)
                if(s[i-1][j]!=-1)
                {
                    for(int k=0; k<=j; ++k)
                    {
                        int t=s[i-1][j]+k*v[i];
                        int tt=j-k+r;
                        if(tt>e) tt=e;
                        if(s[i][tt]==-1||s[i][tt]<t)
                            s[i][tt]=t;
                    }
                }
        }
        int max=-1;
        for(int i=0; i<=e; ++i)
            max=max>s[n][i]?max:s[n][i];
        cout<<"Case #"<<a<<": "<<max<<endl;
    }
    return 0;
}
