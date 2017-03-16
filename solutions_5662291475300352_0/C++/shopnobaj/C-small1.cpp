#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}

struct fract
{
    long long a,b;
    fract(ll a_,ll b_)
    {
        a=a_;b=b_;
    }
    fract(){}
    fract operator*(fract nw)
    {
        fract ret;
        ret.a=a*nw.a;
        ret.b=b*nw.b;
        ll k=gcd(ret.a,ret.b);
        ret.a/=k;
        ret.b/=k;
        return ret;
    }
    fract operator-(fract nw)
    {
        fract ret;
        ret.a=a*nw.b-b*nw.a;
        ret.b=b*nw.b;
        ll k=gcd(ret.a,ret.b);
        ret.a/=k;
        ret.b/=k;
        return ret;
    }
    bool operator<(fract nw)
    {
        return a*nw.b<b*nw.a;
    }
};



int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,cs=1,d1,d2,m1,m2,d,h,m,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cin>>d>>h>>m;
            if(h==1)
            {
                printf("Case #%d: 0\n",cs++);
                continue;
            }
            else
            {
                d1=d2=d;
                m1=m;m2=m+1;
            }
        }
        else
        {
            cin>>d1>>h>>m1>>d2>>h>>m2;
        }
        if(d1>d2)
        {
            swap(d1,d2);
            swap(m1,m2);
        }
        if(d1==d2 && m1==m2)
        {
            printf("Case #%d: 0\n",cs++);
            continue;
        }
        if(d1==d2 && m2<m1) swap(m2,m1);
        //cout<<d1<<" "<<m1<<" "<<d2<<" "<<m2<<endl;
        fract time((360-d1)*m1,360);
        fract tmp(360,m2);
        fract dis=time*tmp;
        fract foo(2*360-d2,1);
        if(dis<foo) printf("Case #%d: 0\n",cs++);
        else
        {
            fract foo2(3*360-d2,1);
            if(dis<foo2) printf("Case #%d: 1\n",cs++);
            else printf("Case #%d: 2\n",cs++);
        }

    }
    return 0;
}
