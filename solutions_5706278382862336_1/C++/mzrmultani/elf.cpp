/**
  *	@author mzr_c0der
  *	Believe you can and you are halfway there
  */
#include<bits/stdc++.h>
#ifdef mzr
//#include<debug.h>
#else
#define db(...) {}
#define dbt(...) {}
#define pprintf(...) {}
#endif

using namespace std;

//#define assert(f) {if(!(f)){fprintf(stderr,"Line-->%d  Assertion failed: %s\n",__LINE__,#f);exit(1);}}
#define MOD 	 1000000007LL
#define ABS(x)   ((x)<0?-(x):(x))
#define SQR(x) 	 ((x)*(x))
#define CUBE(x)  ((x)*(x)*(x))
#define pnl      printf("\n")
#define REP(i,n)        for(__typeof(n) i=0;i<(n);i++)
#define FOR(i,a,b)      for(__typeof(b) i=(a);i<(b);++i)
#define FORE(i,a,b)     for(__typeof(b) i=(a);i<=(b);++i)
#define FORD(i,a,b,d)   for(__typeof(b) i=(a);i<(b);i+=(d))
#define FORR(i,n,e)     for(__typeof(n) i=(n);i>=(e);--i)
#define FORRD(i,n,e,d)  for(__typeof(n) i=(n);i>=(e);i-=(d))
#define REP_IT(it,m)    for(it=m.begin();it!=m.end();it++)
#define FORI(it,s) 	    for(__typeof((s).begin()) (it)=(s).begin();(it)!=(s).end();(it)++)
#define FOREACH(it, X)  for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define UNIQUE(v)       sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(a,b)       memset(a,b,sizeof(a))
#define ALL(v)          (v).begin(), (v).end()
#define RALL(v)         (v).rbegin(), (v).rend()
#define checkbit(n,b)   (((n)>>(b))&1)
#define PB push_back
#define MP make_pair
#define XX first
#define YY second
#define lln long long int
#define gc getchar_unlocked
#define pc putchar_unlocked
inline void fr(lln *a)
{
    char c=0;
    *a=0;
    while(c<33)
        c=getchar();
    while(c>33)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
}
lln gcd(lln a,lln b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
int main()
{
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    lln t,p,q,ans,n,sm,k,i;
    char b;
    fr(&t);
    REP(k,t)
    {
        cin>>p>>b>>q;
        cout<<"Case #"<<k+1<<": ";
        n=gcd(p,q);
        p/=n;
        q/=n;
        i=0;
        sm=40;
        while(i<41)
        {
            if(p==q)break;
            i++;
            if(p*2>q)
            {
                p*=2;
                p-=q;
                n=gcd(p,q);
                p/=n;
                q/=n;
                if(sm>i)sm=i;
            }
            else if(p*2==q)
            {
                if(sm>i)sm=i;
                break;
            }
            else
            {
                p*=2;
                if(q%2==0)
                {
                    q/=2;
                    p/=2;
                }
            }

        }
        if(i>40)
            cout<<"impossible"<<endl;
        else
            cout<<sm<<endl;
    }
    return 0;
}
