#include <cstdio>
#include <cstring>

char a[35];
long long fact[15];
int N,J,mid,midr,cnt=0;
long long power(long long a, long long n)
{
    long long ret=1;
    while(n)
    {
        if(n&1) ret*=a;
        a*=a;
        n>>=1;
    }
    return ret;
}
void dfs(int d)
{
    if(d==mid)
    {
        printf("%s",a);
        for(int i=2;i<=10;i++)
            printf(" %I64d",fact[i]);
        puts("");
        cnt++;
        return;
    }
    for(int i='0';i<='1';i++)
    {
        a[d]=a[midr+d]=i;
        dfs(d+1);
        if(cnt==J) return;
    }
}
int main()
{
    //freopen("largein.txt","r",stdin);
    //freopen("largeans.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++)
    {
        cnt=0;
        scanf("%d%d",&N,&J);
        midr=(N+1)/2;
        for(int i=2;i<=10;i++)
            fact[i]=power(i,midr)+1;
        mid=(N-2)/2;
        a[0]=a[mid]=a[N-1]=a[N-mid-1]='1';
        if(N&1) a[mid+1]='0';
        printf("Case #%d:\n",cases);
        dfs(1);
    }
    return 0;
}
