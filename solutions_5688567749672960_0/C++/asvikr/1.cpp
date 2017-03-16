#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL cnt=0;
bool vis[1000005];
LL d[1000005];
void solve(LL n)
{
    queue<LL> Q;
    memset(vis,false,sizeof(vis));
    memset(d,0,sizeof(d));
    Q.push(n);
    while(!Q.empty())
    {
        LL temp=Q.front();
        Q.pop();
        LL p=0,num=temp;
        while(temp!=0)
        {
            if(temp%10==0 && p==0)
            {
                p=num;
                break;
            }
            p=p*10+temp%10;
            temp/=10;
        }
        if(vis[p]==false && p<num){
        vis[p]=true;
        d[p]=d[num]+1;
        Q.push(p);
        if(p==0)
            return;
        }
        if(vis[num-1]==false){
        vis[num-1]=true;
        d[num-1]=d[num]+1;
        Q.push(num-1);
        if(num-1==0)
            return;
        }
    }
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        printf("Case #%d: ",t);
        LL n;
        scanf("%lld",&n);
        cnt=0;
        solve(n);
        printf("%lld\n",d[0]);
    }
return 0;
}
