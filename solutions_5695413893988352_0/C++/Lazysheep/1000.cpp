#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<time.h>
#include<cmath>
#include<vector>
#include <iomanip>
#define PB(u)  push_back(u);
#define AA   first
#define BB   second
#define inf 0x3f3f3f3f
using namespace std ;
#define MAX 2005
#define sz size()
typedef long long ll ;
typedef pair<int,int> PII ;
const double eps=1e-8;
const double pi=acos(-1.0);

char s[2][MAX];
vector<int> G[2];

void dfs(int id,int now,int len,int num)
{
    if(now>=len)
    {
        G[id].PB(num);
        return ;
    }
    if(s[id][now]=='?')
    {
        for(int j=0;j<=9;j++)
        {
            dfs(id,now+1,len,num*10+j);
        }
    }
    else
    {
        dfs(id,now+1,len,num*10+s[id][now]-'0');
    }
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int T;
    cin>>T;
    int cas=1;
    while(T--)
    {
        G[0].clear();
        G[1].clear();
        scanf(" %s %s",s[0],s[1]);
        int len1=strlen(s[0]),len2=strlen(s[1]);
        int dif=inf,a=0,b=0;
        dfs(0,0,len1,0);
        dfs(1,0,len2,0);
        for(int i=0;i<G[0].size();i++)
        {
            for(int j=0;j<G[1].size();j++)
            {
                //cout<<G[0][i]<<" "<<G[1][j]<<endl;
                if(abs(G[0][i]-G[1][j])<dif)
                {
                    dif=abs(G[0][i]-G[1][j]);
                    a=G[0][i];
                    b=G[1][j];
                }
                else if(abs(G[0][i]-G[1][j])==dif)
                {
                    if(G[0][i]<a)
                    {
                        a=G[0][i];
                        b=G[1][j];
                    }
                    else if(G[0][i]==a&&G[1][j]<b)
                    {
                        b=G[1][j];
                    }
                }
            }
        }
        printf("Case #%d: ",cas++);
        cout<<setfill('0')<<setw(len1)<<a<<" "<<setfill('0')<<setw(len2)<<b<<endl;
    }
    return 0 ;
}
