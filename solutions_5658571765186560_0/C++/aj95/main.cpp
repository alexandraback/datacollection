#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

bool x[5][5][5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*freopen("/Users/Ayur/Downloads/D-small-attempt0.in","r",stdin);
    freopen("/Users/Ayur/Downloads/D-output-small.txt","w",stdout);*/
    int i,j,k;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
            for(k=1;k<=4;k++)
                x[i][j][k]=false;
    
    x[2][1][1]=true;
    x[2][1][3]=x[2][3][1]=true;
    x[2][3][3]=true;
    
    for(j=1;j<=4;j++)
        for(k=1;k<=4;k++)
            x[3][j][k]=true;
    
    x[3][2][3]=x[3][3][2]=false;
    x[3][3][3]=false;
    x[3][3][4]=x[3][4][3]=false;
    
    for(j=1;j<=4;j++)
        for(k=1;k<=4;k++)
            x[4][j][k]=true;

    x[4][3][4]=x[4][4][3]=false;
    x[4][4][4]=false;
    
    
    int t,tt,d,r,c;
    cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        cout<<"Case #"<<tt<<": ";
        cin>>d>>r>>c;
        if(x[d][r][c]) cout<<"RICHARD\n";
        else cout<<"GABRIEL\n";
    }
    return 0;
}