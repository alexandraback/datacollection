#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define NMAX 10
#define _INF 1000000000
int C[NMAX],E[NMAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*freopen("/Users/Ayur/Downloads/B-small-attempt0.in","r",stdin);
    freopen("/Users/Ayur/Downloads/B-output.txt","w",stdout);*/
    int t,tt,i,j,e,c,d,x;
    fill(C,C+NMAX,_INF);
    fill(E,E+NMAX,_INF);
    C[0]=0,E[0]=0;
    C[1]=0,E[1]=1;
    C[2]=0,E[2]=2;
    C[3]=0,E[3]=3;
    for(i=4;i<10;i++)
    {
        for(j=1;2*j<=i;j++)
        {
            x=C[j]+C[i-j]+1+max(E[j],E[i-j]);
            if(x<C[i]+E[i])
            {
                C[i]=C[j]+C[i-j]+1;
                E[i]=max(E[j],E[i-j]);
            }
            else if(x==C[i]+E[i] && C[j]+C[i-j]+1<C[i])
            {
                C[i]=C[j]+C[i-j]+1;
                E[i]=max(E[j],E[i-j]);
            }
            else ;
        }
    }
    //for(i=0;i<NMAX;i++) cout<<i<<": "<<C[i]<<' '<<E[i]<<'\n';
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cout<<"Case #"<<tt<<": ";
        cin>>d;
        c=0,e=-_INF;
        while(d--)
        {
            cin>>x;
            c += C[x];
            e = max(e,E[x]);
        }
        cout<<(c+e)<<'\n';
    }

    return 0;
}