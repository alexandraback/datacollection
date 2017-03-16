//
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<climits>
#include<fstream>
#include<iomanip>
#include<queue>
#include<stack>
#define lli long long

using namespace std;

int a[100][100];
int main()
{

    ifstream cin("B.in");
    ofstream cout("B.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    lli T,n,m,p=1,k,l;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        memset(a,0,sizeof(a));

        cout<<"Case #"<<t<<": ";
        cin>>n>>m;

        if(n==2 && m>1){cout<<"IMPOSSIBLE\n";continue;}
        else if(n==2 && m==1)
        {
            cout<<"POSSIBLE\n";
            cout<<"01\n"<<"00\n";
            continue;
        }

        p=1;
        for(int i=1;i<=n-2;i++)p*=2;
        if(p<m){cout<<"IMPOSSIBLE\n";continue;}

        cout<<"POSSIBLE\n";


        p=1; k=1;
        while(p<m)
        {
            k++;
            for(int i=k-1;i>=1;i--)
            {
                a[i][k]=1;
            }
            p*=2;
        }

        l=0;
        if(m==p)
        {
            for(int i=1;i<=k;i++)a[i][n]=1;
            l=1;

        }

        p/=2;

        if(l==0)
        {
            while(m)
            {
                m-=p;
                a[k][n]=1;

                if(m==0)break;
                while(m<p)
                {
                    p/=2;
                    k--;
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<a[i][j];
            }
            cout<<"\n";
        }

    }

    return 0;
}



