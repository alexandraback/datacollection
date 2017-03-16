#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
bool dp[2000001];
int data[25];
int cas=1;
int n;
bool used[25];
int sum;
int tsum;
int total;
int seta[25];
int setb[25];
int cnta;
int cntb;
bool judge(int pos)
{
    if(pos==n)
        return 0;
    if(sum==0)
        return 0;
    if(!used[pos])
    {
        setb[cntb++]=data[pos];
        tsum+=data[pos];
        if(tsum==sum)
            return 1;
        if(judge(pos+1))
            return 1;
        tsum-=data[pos];
        cntb--;
    }
    return judge(pos+1);
}
bool solve(int pos)
{
    if(pos==n)
        return 0;
    sum+=data[pos];
    seta[cnta++]=data[pos];
    used[pos]=1;
    if(sum<total/2)
    {
        if(judge(0))
            return 1;
        if(solve(pos+1))
            return 1;
    }
    sum-=data[pos];
    used[pos]=0;
    cnta--;
    if(judge(0))
        return 1;
    return solve(pos+1);
}
int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("out2.txt","w",stdout);

    int t;

    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n;
        sum=0;
        tsum=0;
        total=0;
        for(int i=0;i<n;i++)
        {
            cin>>data[i];
            total+=data[i];
        }
        sort(data,data+n);
        cnta=0;
        cntb=0;
        memset(used,0,sizeof(used));
        //cout<<cnta<<" "<<cntb<<endl;
        printf("Case #%d:",cas++);
        if(!solve(0))
            cout<<"Impossible"<<endl;
        else
        {
            cout<<endl;
            for(int i=0;i<cnta;i++)
            {
                if(i)
                    cout<<" ";
                cout<<seta[i];
            }
            cout<<endl;
            for(int i=0;i<cntb;i++)
            {
                if(i)
                    cout<<" ";
                cout<<setb[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
