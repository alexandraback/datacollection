#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
    ll t,n,i,j;
    cin>>t;
    ll count=1;
    while(t--)
    {
        ll b,m;
        cin>>b>>m;
        cout<<"Case #"<<count<<": ";
        ll arr[b+1];
        count++;
        if(m<=pow(2,b-2))
        {
            cout<<"POSSIBLE\n";
        }
        else
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        for(i=1;i<=b-1;i++)
        {
            arr[i]=pow(2,b-1-i);
        }
        ll mat[b][b];
        for(i=0;i<b;i++)
        {
            for(j=0;j<b;j++)
            {
                if(i!=0 && j>i)
                    mat[i][j]=1;
                else
                    mat[i][j]=0;
            }
        }
        for(i=2;i<b;i++)
        {
            if(m>=arr[i])
            {
                m-=arr[i];
                mat[0][i-1]=1;
            }
        }
        if(m!=0)
        {
            for(i=1;i<b;i++)
                mat[0][i]=1;
        }
        for(i=0;i<b;i++)
        {
            for(j=0;j<b;j++)
            {
                cout<<mat[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
