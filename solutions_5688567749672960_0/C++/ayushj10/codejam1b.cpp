/*Programmed by Ayush Jaggi*/

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz size()
#define clr clear()
#define mem(a,b) memset(a,b,sizeof(a))
#define in(type,a) scanf("%" #type,&a)
#define ins(a) scanf("%s",a)
#define out(type,a) printf("%" #type,a)
#define pn printf("\n")
#define ps printf(" ")
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define all(a) a.begin(),a.end()
#define repv(i,a) rep(i,all(a))
#define sortv(a) sort(all(a))
#define len length()

#define tc int t;\
in(d,t);\
while(t--)
//#define test int t; in(d,t); while(t--)

#define scn int n;\
in(d,n);
//#define scn int n; in(d,n);

#define scnm int n,m;\
in(d,n);\
in(d,m);
//#define scnm int n; in(d,n); in(d,m)

//iterator example
//for(map<ii,int>::const_iterator it=graph.begin(); it!=graph.end(); it++)
//it->F, it->S operations

//__typeof(a) -> hardware call equivalent to typeof(a)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

ll MOD=1000000007;

template<class T> inline T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}

//__gcd(a,b) hardware call

inline ll expo(ll base, int nent)
{
    if(nent==1)
        return base;
    else if(nent&1)
    {
        ll temp=expo(base,nent/2);
        temp=(temp*temp)%MOD*base;
        if(temp>=MOD)
            temp%=MOD;
        return temp;
    }
    else
    {
        ll temp=expo(base,nent/2);
        temp*=temp;
        if(temp>=MOD)
            temp%=MOD;
        return temp;
    }
}

/*
inline void prime()
{
    int s, d, count=0;
    lb=sqrt(n);
    for(s=2; s<=lb; s++)
        if(!pr[s])
        {
            sieve[count++]=s;
            for(d=s*s; d<=n; d+=s)
                pr[d]=1;
        }
}
*/

int m[1000005];

inline int memo(int a)
{
    if(!m[a])
    {
        int rev=0, temp=a, c;
        while(temp)
        {
            c=temp%10;
            if(rev)
                rev=rev*10+c;
            else if(c)
                rev=c;
            temp/=10;
        }
        if(rev<a && a%10)
            m[a]=min(memo(a-1),memo(rev))+1;
        else m[a]=memo(a-1)+1;
    }
    return m[a];
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out1.txt","w",stdout);
    m[1]=1;
    int counter=1;
    tc
    {
        scn;
        printf("Case #%d: %d\n",counter++,memo(n));
    }
    return 0;
}
