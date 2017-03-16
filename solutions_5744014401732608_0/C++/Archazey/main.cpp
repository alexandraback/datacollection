#include<bits/stdc++.h>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;

const int NMAX=55;

int t,n;
bool mat[NMAX][NMAX];
long long m;

int main()
{
    int i,j,k,nr;
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    cin.sync_with_stdio(false);
    cin>>t;
    for (k=1;k<=t;k++)
    {
        cin>>n>>m;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                mat[i][j]=0;
        nr=0;
        while ((1LL<<nr)<=m) nr++;
        nr--;
        cout<<"Case #"<<k<<": ";
        if (m==(1LL<<nr))
        {
            if ((n-1)<(nr+1)) {cout<<"IMPOSSIBLE\n";continue;}
            else
            {
                for (i=1;i<=(nr+1);i++)
                    for (j=i+1;j<=(nr+1);j++)
                        mat[i][j]=1;
                for (i=1;i<=(nr+1);i++) mat[i][n]=1;
            }
        }
        else
        {
            if ((n-2)<(nr+1)) {cout<<"IMPOSSIBLE\n";continue;}
            else
            {
                for (i=1;i<=(nr+2);i++)
                    for (j=i+1;j<=(nr+2);j++)
                        mat[i][j]=1;
                for (i=50;i>=2;i--)
                    if (m&(1LL<<(i-2)))
                        mat[i][n]=1;
            }
        }
        cout<<"POSSIBLE\n";
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++) cout<<mat[i][j];
            cout<<"\n";
        }

    }
    return 0;
}

