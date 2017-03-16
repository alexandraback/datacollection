#include<bits/stdc++.h>
using namespace std;

long long mi(long long n,long long k)
{
    long long ret=1;
    while(k--) ret*=n;
    return ret;
}

string ToStr(long long n)
{
    stack<long long> s;
    do{
        s.push(n%2);
        n/=2;
    }while(n);
    string ret="";
    while(!s.empty())
    {
        ret+=char(s.top()+'0');
        s.pop();
    }
    return ret;
}

bool isPrime(long long n)
{
    if(n<2) return false;
    for(long long i=2;i*i<=n;++i) if(n%i==0) return false;
    return true;
}

long long jinzhi(long long n,long long k)
{

    stack<long long> s;
    do{
        s.push(n%2);
        n/=2;
    }while(n);
    long long ret=0;
    while(!s.empty())
    {
        ret+=s.top()*mi(k,s.size()-1);
        s.pop();
    }
    return ret;
}

struct answer
{
    string val;
    long long a[10];
};

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    long long T;
    scanf("%lld",&T);
    for(long long cas=1;cas<=T;++cas)
    {
        long long N,J;
        scanf("%lld%lld",&N,&J);
        long long st=1+mi(2,N-1);
        long long ed=st;
        for(long long i=1;i<N-1;++i) ed+=mi(2,i);
        answer ans[510];
        long long cnt=0;
        for(long long i=st;i<=ed;i+=2)
        {
            bool f=true;
            for(long long j=2;j<=10;++j)
            {
                long long tmp=jinzhi(i,j);
                if(isPrime(tmp)) {f=false;break;}
            }
            if(f)
            {
                ++cnt;
                ans[cnt].val=ToStr(i);
                for(long long j=2;j<=10;++j)
                {
                    long long tmp=jinzhi(i,j);
                    for(long long k=2;k*k<=tmp;++k)
                    {
                        if(tmp%k==0)
                        {
                            ans[cnt].a[j-1]=k;
                            break;
                        }
                    }
                }
                if(cnt==J) break;
            }
        }
        printf("Case #%d:\n",cas);
        for(long long i=1;i<=cnt;++i)
        {
            cout<<ans[i].val;
            for(long long j=1;j<=9;++j) printf(" %d",ans[i].a[j]);
            printf("\n");
        }
    }
    return 0;
}
