#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll a,ll b)
{
    if(b==0)
        return 1;
    ll temp=power(a,b/2);
    temp=temp*temp;
    if(b&1)
        temp*=a;
    return temp;
}
int main()
{
    freopen("B-large (4).in","r",stdin);
    freopen("oo.txt","w",stdout);
    int t,z;
    cin>>t;
    for(z=1;z<=t;z++)
    {
        ll b,m,temp;
        cin>>b>>m;
        cout<<"Case #"<<z<<": ";
        int i,j;
        int mat[55][55]={0};
        for(i=0;i<b;i++)
        {
            for(j=i+1;j<b;j++)
            {
                mat[i][j]=1;
            }
        }
        temp=power(2,b-2);
        if(m>temp)
        {
            cout<<"IMPOSSIBLE\n";
        }
        else
        {
            temp-=m;
            cout<<"POSSIBLE\n";
        int bin[70]={0},k=0;
        while(temp)
        {
            bin[k++]=temp%2;
            temp/=2;
        }
        j=0;
        for(i=k-1;i>=0;i--)
        {
            if(bin[i])
                mat[i+1][b-1]=0;
        }
        for(i=0;i<b;i++)
        {
            for(j=0;j<b;j++)
                cout<<mat[i][j];
            cout<<endl;
        }
    }
    }
    return 0;
}
