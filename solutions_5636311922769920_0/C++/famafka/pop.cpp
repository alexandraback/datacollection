#include<bits/stdc++.h>
using namespace std;

int dp[200][4];

void go_ans(int t,int x)
{
    cout<<"Case #"<<t<<": "<<x<<"\n";
}

int main()
{
    freopen("inputddl.in","r",stdin);
    freopen("outputddl.txt","w",stdout);
    int t=0;
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        int K,C,S;
        cin>>K>>C>>S;
        cout<<"Case #"<<t1<<": ";
        for(int i=1;i<=S;i++)
            cout<<i<<' ';
        cout<<"\n";
    }
}
