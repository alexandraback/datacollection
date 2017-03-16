#include<bits/stdc++.h>
using namespace std;

int dp[200][4];

void go_ans(int t,int x)
{
    cout<<"Case #"<<t<<": "<<x<<"\n";
}

long long proof(long long mask,int base,int N)
{
    for(int i=2;i<=100;i++)
    {
        long long res=0;
        long long cur=1;
        for(int bit=0;bit<N;bit++)
        {
            if((1<<bit) & mask)
                res=(res+cur)%i;
            cur=(cur*base)%i;
        }
        if(res==0)
            return i;
    }
}

bool good(int mask,int N)
{
    for(int base=2;base<=10;base++)
    {
        if(!proof(mask,base,N))
            return false;
    }
    return true;
}

void go(int mask,int N)
{
    for(int bit=N-1;bit>=0;bit--)
        if((1<<bit) & mask)
            cout<<"1";
        else
            cout<<"0";
    cout<<' ';
    for(int base=2;base<=10;base++)
    {
        cout<<proof(mask,base,N)<<' ';
    }
    cout<<"\n";
}

int main()
{
    ///freopen("inputcl.in","r",stdin);
    freopen("outputcl.txt","w",stdout);
    int t=0;
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        int N,K;
        cin>>N>>K;
        cout<<"Case #1:\n";
        vector<int> ans;
        for(int mask=(1<<(N-1))+1;mask<(1<<N) && K;mask+=2)
        {
            if(good(mask,N))
            {
                ans.push_back(mask);
                --K;
            }
        }
        if(K)
        {
            cout<<"-1\n";
            return 0;
        }
        for(int i=0;i<ans.size();i++)
            go(ans[i],N);
    }
}
