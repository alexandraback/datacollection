#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test;
    cin>>test;
    for(int x=1;x<=test;x++)
    {
        int n;
        cin>>n;
        int mat[n+9][n+9];
        for(int i=0;i<n+9;i++)
            for(int j=0;j<n+9;j++)
            mat[i][j]=0;
        ll m;
        cin>>m;
        ll lim=1;
        cout<<"Case #"<<x<<": ";
        bool flag=false;
        for(int i=2;i<=n;i++)
        {
            if(flag)
            {
                mat[i][i-1]=1;
            }
            else
            {
                if(lim<=m)
                {
                    if(lim==m)
                        flag=true;
                    for(int j=1;j<i;j++)
                        mat[i][j]=1;
                    lim*=2;
                }
                else
                {
                    flag=true;
                    int to=2;
                    while(m!=0)
                    {
                        int rem=m%2;
                        m/=2;
                        if(rem!=0)
                        {
                            mat[i][to]=1;
                        }
                        to++;
                    }
                }
            }
        }
        if(!flag)
            cout<<"IMPOSSIBLE\n";
        else
        {
            cout<<"POSSIBLE\n";
            for(int i=n;i>0;i--)
            {
                for(int j=n;j>0;j--)
                {
                    cout<<mat[i][j];
                }
                cout<<endl;
            }
        }
    }
    fclose(stdout);
}
