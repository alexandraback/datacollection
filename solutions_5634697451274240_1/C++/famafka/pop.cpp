#include<bits/stdc++.h>
using namespace std;

int dp[200][4];

void go_ans(int t,int x)
{
    cout<<"Case #"<<t<<": "<<x<<"\n";
}

void make_reverse(string &s,int l,int r)
{
    for(int i=l;i<=r;i++)
        if(s[i]=='-')
            s[i]='+';
        else
            s[i]='-';
    while(l<r)
    {
        swap(s[l],s[r]);
        ++l,--r;
    }
}

int main()
{
    freopen("inputbg.in","r",stdin);
    freopen("outputbg.txt","w",stdout);
    int t=0;
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        string s;
        cin>>s;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='-')
            {
                if(i==0)
                    dp[i][0]=0;
                else
                    dp[i][0]=dp[i-1][0];
                if(i==0)
                    dp[i][1]=1;
                else
                    dp[i][1]=dp[i-1][0]+1;
            }else
            {
                if(i==0)
                    dp[i][0]=1;
                else
                    dp[i][0]=dp[i-1][1]+1;
                if(i==0)
                    dp[i][1]=0;
                else
                    dp[i][1]=dp[i-1][1];
            }
        }
        go_ans(t1,dp[n-1][1]);
    }
}
