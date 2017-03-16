#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int te;
    cin>>te;
    for(long long int t=1;t<=te;t++)
    {
        long long int d[60];
        memset(d,0,sizeof(d));
        long long int b,m;
        cin>>b>>m;
        vector< vector<bool> > ma(55, vector<bool>(50,false));
        d[1]=1;
        long long int cont=1;
        ma[1][b]=true;
        long long int tmp=1;
        for(int i=2;i<b;i++)
        {
            if(cont>=m) break;
            if(tmp+cont>m)
            {
               bitset<32> bs (m-cont);
               for(int j=1;j<=32;j++)
               {
                   if(bs[j-1])
                   {
                       ma[j+1][i]=true;
                       ma[i][b]=true;
                   }
               }
               cont=m;
            }
            else
            {
                for(int j=1;j<i;j++)
                {
                    ma[j][i]=true;
                    ma[i][b]=true;
                }
                cont+=tmp;
            }
            tmp=tmp*(long long int)2;
        }
        cout<<"Case #"<<t<<": ";
        if(cont==m)
        {
            cout<<"POSSIBLE"<<endl;
            for(int i=1;i<=b;i++)
            {
                for(int j=1;j<=b;j++)
                {
                    cout<<ma[i][j];
                }
                cout<<endl;
            }
            cout<<endl;
        }
        else
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
