#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
int N,J;
char a[35];
const int MAXN=1e8;
vector<bool> p(MAXN,true);
vector<int> prime;
int fact=0,cnt=0;
void init()
{
    p[0]=p[1]=false;
    for(int i=2;i<10000;i++)
    {
        for(int j=i*i;j<MAXN;j+=i)
            p[j]=false;
    }
    prime.push_back(2);
    for(int i=3;i<MAXN;i+=2)
        if(p[i]) prime.push_back(i);
}
bool isprime(long long n)
{
    //if(n<MAXN) return p[n];
    long long t=sqrt(n);
    for(int i=0;i<(int)prime.size();i++)
    {
        //printf("%d\n",prime[i]);
        if(prime[i]>t) break;
        if(n%prime[i]==0)
        {
            fact=prime[i];
            return false;
        }
    }
    return true;
}
long long base(int n)
{
    long long t=1;
    long long ret=0;
    for(int i=N-1;i>=0;i--)
    {
        if(a[i]=='1')
            ret+=t;
        t*=n;
    }
    return ret;
}
bool check()
{
    int factor[12]={};
    for(int i=2;i<=10;i++)
    {
        long long t=base(i);
        //printf("%d %lld\n",i,t);
        if(isprime(t)) return false;
        factor[i]=fact;
    }
    printf("%s",a);
    for(int i=2;i<=10;i++)
        printf(" %d",factor[i]);
    puts("");
    return true;
}
void dfs(int d)
{
    if(d==N-1)
    {
        //printf("%s\n",a);
        if(check())
        {
            cnt++;
            //printf("%d\n",cnt);
        }
        return;
    }
    for(int i='0';i<='1';i++)
    {
        a[d]=i;
        dfs(d+1);
        if(cnt==J) return;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("small.txt","w",stdout);
    init();
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++)
    {
        cnt=0;
        scanf("%d%d",&N,&J);
        a[0]=a[N-1]='1',a[N]='\0';
        printf("Case #%d:\n", cases);
        dfs(1);
    }
    return 0;
}
