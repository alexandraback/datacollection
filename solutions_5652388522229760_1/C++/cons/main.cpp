#include <cstdio>
#include <cstring>
#define FOR(i,x,y) for(int i=x;i<=y;++i)
int t,n,add,cnt,ans;
bool vis[10];
void make(int n)
{
    int last;
    while(n)
    {
        last=n%10;
        n/=10;
        if(!vis[last])
        {
            --cnt;
            vis[last]=true;
        }
    }
}
int main()
{
    scanf("%d",&t);
    FOR(i,1,t)
    {
        printf("Case #%d: ",i);
        scanf("%d",&n);
        if(n==0) {printf("INSOMNIA\n");continue;}
        memset(vis,0,sizeof(vis));
        cnt=10;
        add=0; ans=0;
        while(cnt)
        {
            add+=n;
            ++ans;
            make(add);
        }
        printf("%d\n",n*ans);
    }
    return 0;
}
