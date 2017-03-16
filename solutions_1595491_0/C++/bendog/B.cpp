#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[1024][1024];
int score[1024];
int p;
int recur(int a,int b);
int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    int cas,q,s,n,i;
    FILE* fp =  fopen("GB.out","w");
//    scanf("%d",&cas);
    cin>>cas;
   // cout<<cas<<endl;
    for(q=1;q<=cas ; q++)
    {
        cin>>n>>s>>p;
        for(i = 0 ;i < n ; i++)cin>>score[i];
        memset(dp,-1,sizeof(dp));
        fprintf(fp,"Case #%d: %d\n",q,recur(s,n-1));
       // cout<<"Case #"<<q<<": "<<recur(s,n-1)<<endl;
    }
    return 0;
}
int recur(int a,int b)
{
    int t;
    if(b == -1)return 0;
    if(dp[a][b]>-1)return dp[a][b];

    int avg = score[b]/3;
    int re = score[b]%3;

    if(re==0)
    {
        if(avg >= p)
            t = recur(a,b-1)+1;
        else if(avg-1 >=0 && avg+1 == p && a > 0)
            t = recur(a-1,b-1)+1;
        else
            t= recur(a,b-1);
    }
    else if(re==1)
    {
        if(avg+1 >= p)
            t = recur(a,b-1)+1;
        else
            t = recur(a,b-1);
    }
    else
    {
        if(avg+1 >= p)
            t = recur(a,b-1)+1;
        else if(avg+2 ==p && a > 0)
            t = recur(a-1,b-1)+1;
        else
            t = recur(a,b-1);
    }
   // cout<<a<<' '<<b<<' '<<t<<endl;
    return dp[a][b] = t;
}
