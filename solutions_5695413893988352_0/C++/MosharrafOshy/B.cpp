#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define ll  long long
#define llu unsigned long long
#define M 5000
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define Check(x,w) (x&(1<<w))==(1<<w)?true:false
#define pii pair<int,int>
using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

string u,v;

int main()
{
    freopen("inB1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,tt,a,b,c,d,e,f,c1,c2,d1,d2,e1,e2,f1,f2,g1,g2,h1,h2,i,j,k,l,n,m;
    int a1,a2,b1,b2;
    fs(tt);
    for(t=1; t<=tt; t++)
    {
        cin>>u>>v;
        int x=u.size();
        for(i=x; i<=3; i++)
            u+='0',v+='0';
        a=b=1000;
        if(u[0]=='?')
            c1=0,c2=9;
        else
            c1=c2=u[0]-'0';
        for(i=c1; i<=c2; i++)
        {
            if(v[0]=='?')
                d1=0,d2=9;
            else
                d1=d2=v[0]-'0';
            for(j=d1; j<=d2; j++)
            {
                if(u[1]=='?')
                    e1=0,e2=9;
                else
                    e1=e2=u[1]-'0';
                for(k=e1; k<=e2; k++)
                {
                    if(v[1]=='?')
                        f1=0,f2=9;
                    else
                        f1=f2=v[1]-'0';
                    for(l=f1; l<=f2; l++)
                    {
                        if(u[2]=='?')
                            g1=0,g2=9;
                        else
                            g1=g2=u[2]-'0';
                        for(m=g1; m<=g2; m++)
                        {
                            if(v[2]=='?')
                                h1=0,h2=9;
                            else
                                h1=h2=v[2]-'0';
                            for(n=h1; n<=h2; n++)
                            {
                                c=(i*100)+(k*10)+m;
                                d=(j*100)+(l*10)+n;
                                //pf("c=%d d=%d i=%d j=%d k=%d l=%d m=%d n=%d\n",c,d,i,j,k,l,m,n);
                                if(abs(c-d)<a)
                                {
                                    a=abs(c-d);
                                    a1=c;
                                    a2=d;
                                }
                                else if(abs(c-d)==a)
                                {
                                    if(c<a1)
                                    {
                                        a1=c;
                                        a2=d;
                                    }
                                    else if(c==a1)
                                    {
                                        if(d<a2)
                                        {
                                            a1=c;
                                            a2=d;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(x==1)
            a1/=100,a2/=100;
        if(x==2)
            a1/=10,a2/=10;
        a=0;
        b=a1;
        while(b>0)
        {
            b/=10;
            a++;
        }
        pf("Case #%d: ",t);
        if(a1==0)
            a++;
        for(i=0; i<x-a; i++)
            pf("0");
        pf("%d",a1);
        pf(" ");
        a=0;
        b=a2;
        while(b>0)
        {
            b/=10;
            a++;
        }
        if(a2==0)
            a++;
        for(i=0; i<x-a; i++)
            pf("0");
        pf("%d",a2);
        pf("\n");
    }
    return 0;
}
