#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;


int f[1005][1005],n;
bool ans=false;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);freopen("result.out","w",stdout);
 //   freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    int T;
    cin>>T;
    for (int N=1; N<=T; N++)
    {
        cin>>n;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) f[i][j]=0;
        ans=false;
        for (int i=0; i<n; i++)
        {
            int m,x;
            cin>>m;
            for (int j=0; j<m; j++)
            {
                cin>>x;
                x--;
                f[i][x]++;
            }
        }
        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                {
                    if ((i==j) || (i==k) || (j==k)) continue;
                    f[i][j]+=f[i][k]*f[k][j];
                }
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if ((i!=j) && (f[i][j]>=2)) {ans=true; break;}


        cout<<"Case #"<<N<<": ";
        if (ans) cout<<"Yes"; else cout<<"No";
        cout<<endl;
    }
    return 0;
}
