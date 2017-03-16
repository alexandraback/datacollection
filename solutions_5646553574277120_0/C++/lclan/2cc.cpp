#include<iostream>
#include<string.h>
using namespace std;
int c,d,v;
int ans ;
int x[100];
bool check(int now)
{
    memset(x,0,sizeof(x));
    x[0]=1;
    for(int i=1;i<=v;i++)
    {
        if((now&(1<<i))!=0)
        {
            for(int k=0;k<c;k++)
            {
                for(int j=v;j>=0;j--)
                {
                    if(x[j]==1)
                    {
                        x[j+i]=1;
                    }
                }
            }
        }
    }
    for(int i=1;i<=v;i++)
    {
        if(x[i]==0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int now,int use)
{
    if(use>=ans)return;
    if(check(now))
    {
        ans=use;
        return;
    }
    for(int i=1;i<=v;i++)
    {
        if((now&(1<<i))==0)
        {
            dfs(now+(1<<i),use+1);
        }
    }
}
int main()
{
    int i,j,k;
    int t,s;
    cin>>t;
    s=1;
    while(t--)
    {
        cin>>c>>d>>v;
        int now=0;
        for(i=0;i<d;i++)
        {
            cin>>j;
            now+=(1<<j);
        }
        ans=5;
        dfs(now,0);
        cout<<"Case #"<<s<<": "<<ans<<endl;
        s++;
    }
}
