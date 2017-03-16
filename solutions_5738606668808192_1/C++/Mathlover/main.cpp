#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct big
{
    typedef long long ll;
    typedef ll INT;
    static const int S_n=30, D_n=9, DM=100000000;
    static const INT S=INT(1)<<S_n, _S=S-1;
    static const int SIZE=55;
    INT a[SIZE];
    int len, tag;
    big()
    {
        len=1;
        memset(a, 0, sizeof a);
    }
    big(const INT &x)
    {
        len=1;
        memset(a, 0, sizeof a);
        *this=x;
    }
    inline void cln()
    {
        memset(a, 0, sizeof(INT)*(len+1));
        len=1;
        tag=0;
    }
    inline void fix()
    {
        for(; len>1 && !a[len]; --len);
    }
    void M(big &a, big &b, big &c)
    {
        if(b.tag)
        {
            b.tag=0;
            P(a, b, c);
            b.tag=1;
            return;
        }
        if(a.tag)
        {
            a.tag=0;
            P(a, b, c);
            a.tag=1;
            c.tag=1;
            return;
        }
        c.cln();
        int flag=0, i=1;
        big *x=&a, *y=&b;
        if(a<b) flag=1, swap(x, y);
        for(; i<=x->len; ++i)
        {
            c.a[i]+=x->a[i]-y->a[i];
            if(c.a[i]<0) c.a[i]+=S, --c.a[i+1];
        }
        c.len=i;
        c.fix();
        c.tag=flag;
    }
    void P(big &a, big &b, big &c)
    {
        if(b.tag)
        {
            b.tag=0;
            M(a, b, c);
            b.tag=1;
            return;
        }
        if(a.tag)
        {
            a.tag=0;
            M(b, a, c);
            a.tag=1;
            return;
        }
        c.cln();
        int i=1, l=max(a.len, b.len);
        INT k=0;
        for(; i<=l || k; ++i)
        {
            c.a[i]=a.a[i]+b.a[i]+k;
            if(c.a[i]>=S) k=c.a[i]>>S_n, c.a[i]&=_S;
            else k=0;
        }
        c.len=i;
        c.fix();
    }
    void T(big &a, big &b, big &c)
    {
        c.cln();
        for(int i=1; i<=a.len; ++i)
        {
            for(int j=1; j<=b.len; ++j)
            {
                int pos=i+j-1;
                c.a[pos]+=a.a[i]*b.a[j];
                if(c.a[pos]>=S) c.a[pos+1]+=c.a[pos]>>S_n, c.a[pos]&=_S;
            }
        }
        c.len=a.len+b.len;
        c.fix();
        c.tag=a.tag^b.tag;
        if(c.a[1]==0 && c.len==1) c.tag=0;
    }
    void D(big &a, INT b, big &c)
    {
        c.cln();
        INT t=0;
        int flag=b<0;
        if(b<0) b=-b;
        for(int i=len; i; --i)
        {
            c.a[i]=(a.a[i]+t)/b;
            t=((a.a[i]+t)%b)<<S_n;
        }
        c.tag=a.tag^flag;
        c.len=len;
        c.fix();
        if(c.a[1]==0 && c.len==1) c.tag=0;
    }
    void D(big &a, big &b, big &c)
    {
        c.cln();
        int flag1=a.tag, flag2=b.tag;
        a.tag=b.tag=0;
        big l, r=a, mid, TP, ONE=(INT)1;
        while(l<=r)
        {
            P(l, r, TP);
            D(TP, 2, mid);
            T(mid, b, TP);
            if(TP<=a) P(mid, ONE, l);
            else M(mid, ONE, r);
        }
        M(l, ONE, c);
        a.tag=flag1;
        b.tag=flag2;
        c.tag=a.tag^b.tag;
        if(c.a[1]==0 && c.len==1) c.tag=0;
    }
    big sqrt()
    {
        big l, r=*this, mid, TP, ONE=(INT)1;
        while(l<=r)
        {
            P(l, r, TP);
            D(TP, 2, mid);
            T(mid, mid, TP);
            if(TP<=*this) P(mid, ONE, l);
            else M(mid, ONE, r);
        }
        M(l, ONE, TP);
        return TP;
    }
    bool operator< (const big &b) const
    {
        if(b.tag && !tag) return 0;
        if(!b.tag && tag) return 1;
        if(len!=b.len) return (len<b.len)^tag;
        for(int i=len; i; --i)
        {
            if(a[i]<b.a[i]) return 1^tag;
            else if(a[i]>b.a[i]) return 0^tag;
        }
        return 0;
    }
    big& operator= (INT b)
    {
        cln();
        len=0;
        if(b==0)
        {
            len=1;
            return *this;
        }
        if(b<0) tag=1, b=-b;
        for(; b; a[++len]=b&_S, b>>=S_n);
        return *this;
    }
    big& operator= (const big &x)
    {
        cln();
        memcpy(a, x.a, sizeof(INT)*(x.len+1));
        len=x.len, tag=x.tag;
        return *this;
    }
    big operator+ (const big &x)
    {
        static big b, c;
        b=x;
        P(*this, b, c);
        return c;
    }
    big operator- (const big &x)
    {
        static big b, c;
        b=x;
        M(*this, b, c);
        return c;
    }
    big operator* (const big &x)
    {
        static big b, c;
        b=x;
        T(*this, b, c);
        return c;
    }
    big operator/ (const big &x)
    {
        static big b, c;
        b=x;
        D(*this, b, c);
        return c;
    }
    big operator/ (const INT &x)
    {
        static big c;
        static INT b;
        b=x;
        D(*this, b, c);
        return c;
    }
    big operator% (const big &x)
    {
        return *this-*this/x*x;
    }
    big operator% (const INT &x)
    {
        return *this-*this/x*x;
    }
    big& operator+= (const big &x)
    {
        static big b, c;
        b=x;
        P(*this, b, c);
        return *this=c;
    }
    big& operator-= (const big &x)
    {
        static big b, c;
        b=x;
        M(*this, b, c);
        return *this=c;
    }
    big& operator*= (const big &x)
    {
        static big b, c;
        b=x;
        T(*this, b, c);
        return *this=c;
    }
    big& operator/= (const big &x)
    {
        static big b, c;
        b=x;
        D(*this, b, c);
        return *this=c;
    }
    big& operator/= (const INT &x)
    {
        static big c;
        static INT b;
        b=x;
        D(*this, b, c);
        return *this=c;
    }
    big& operator%= (const big &x)
    {
        return *this=*this%x;
    }
    big& operator++ ()
    {
        return *this+=1;
    }
    big operator++ (int)
    {
        static big c;
        c=*this;
        ++*this;
        return c;
    }
    big& operator-- ()
    {
        return *this-=1;
    }
    big operator-- (int)
    {
        static big c;
        c=*this;
        --*this;
        return c;
    }
    bool operator> (const big &x) const
    {
        return x<*this;
    }
    bool operator== (const big &x) const
    {
        return x<=*this&&x>=*this;
    }
    bool operator<= (const big &x) const
    {
        return !(x<*this);
    }
    bool operator>= (const big &x) const
    {
        return !(x>*this);
    }
    bool operator!= (const big &x) const
    {
        return !(*this==x);
    }
    void P()
    {
        static INT p[(D_n+1)*SIZE];
        if(tag) putchar('-');
        big t=*this;
        int top=0;
        if(t.len==1 && t.a[1]==0)
        {
            p[++top]=0;
        }
        for(; !(t.len==1 && t.a[1]==0); p[++top]=(t%DM).a[1], t/=DM);
        printf("%d", (int)p[top]);
        char od[8];
        od[0]='%';
        od[1]='0';
        sprintf(od+2, "%d", D_n-1);
        int l=strlen(od);
        od[l]='d';
        od[l+1]='\0';
        for(int i=top-1; i; --i) printf(od, (int)p[i]);
    }
};

big tran(long long q,int n)
{
    big p=q;
    big ans=0;
    big base=1;
    while(p!=0)
    {
        ans=ans+p%2*base;
        base*=n;
        p/=2;
    }
    return ans;
}
#define MAXN 10
#define C 16381
long long mi;

long long multi(long long a, long long b, long long n)
{
    long long tmp = a % n, s = 0;
    while(b)
    {
        if(b & 1) s = (s + tmp) % n;
        tmp = (tmp + tmp) % n;
        b >>= 1;
    }
    return s;
}

long long Pow(long long a, long long b, long long n)
{
    long long tmp = a % n, s = 1;
    while(b)
    {
        if(b & 1) s = multi(s, tmp, n);
        tmp = multi(tmp, tmp, n);
        b >>= 1;
    }
    return s;
}

int witness(long long a, long long n)
{
    long long u = n - 1, t = 0, i, x, y;
    while(!(u & 1))	u >>= 1, t ++;
    x = Pow(a, u, n);
    for(i = 1; i <= t; i ++)
    {
        y = multi(x, x, n);
        if(y == 1 && x != 1 && x != n -1) return 1;
        x = y;
    }
    if(x != 1) return 1;
    return 0;
}

int test(long long n)
{
    long long a;
    int i;
    if(n == 2) return 1;
    if(n < 2 || !(n & 1)) return 0;
    srand((long long)time(0));
    for(i = 0; i < MAXN; i ++)
    {
        a = ((long long) rand()) % (n - 2) + 2;
        if(witness(a, n)) return 0;
    }
    return 1;
}

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

long long pollard_rho(long long n, long long c)
{
    long long x, y, d, i = 1, k = 2;
    srand((long long)time(0));
    x = ((long long) rand()) % (n - 1) + 1;
    y = x;
    while(1)
    {
        i ++;
        x = (multi(x, x, n) + c) % n;
        d = gcd(y - x + n, n);
        if(d != 1 && d != n) return d;
        if(y == x) return n;
        if(i == k) y = x, k <<= 1;
    }
}

void cal(long long n, long long c)
{
    long long r;
    if(n <= 1) return;
    if(test(n))
    {
        if(mi > n) mi = n;
        return;
    }
    r = pollard_rho(n, c--);
    cal(n / r, c);
    cal(r, c);
}

long long MaxPrimeFactor(long long n)
{
    if(test(n))
        return n;

    long long k=-1,g;
    mi=n;
    cal(n,C);

    g=MaxPrimeFactor(mi);
    k=g>k?g:k;

    g=MaxPrimeFactor(n/mi);
    k=g>k?g:k;
    return k;
}
void print(long long i)
{
    int temp[100];
    int cnt=0;
    while(i)
    {
        temp[cnt++]=i%2;
        i/=2;
    }
    for(int i=cnt-1; i>=0; --i)
        cout<<temp[i];
}
bool judge(big n)
{
    for(int i=2;i<=20;++i)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    int t;
    int ca=0;
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("Case #%d:\n",++ca);
        for(long long i=(1LL<<n-1)+1; i<(1LL<<n)-1; i+=2)
        {
            if(m==0)
                break;
            bool flag=0;
            for(int j=2; j<=10; ++j)
            {
                big q=tran(i,j);
                if(judge(q))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                continue;
            print(i);
            for(int j=2; j<=10; ++j)
            {
                big q=tran(i,j);
                bool flag=0;
                int ans=-1;
                for(int k=2; k<=20; ++k)
                {
                    if(q%k==0)
                    {
                        ans=k;
                        break;
                    }
                }
                printf(" %d",ans);
            }
            puts("");
            m--;
        }

    }
}
