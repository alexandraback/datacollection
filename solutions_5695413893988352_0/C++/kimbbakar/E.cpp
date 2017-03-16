 /*
 Problem name :
 Algorithm : Not Sure Yet
 Contest/Practice :
 Source :
 Comment : Whenever you start to believe  yourself, people also start to believe in you
 Date : --
 Last Update : 25-Mar-2015
*/

/*
    Am I wrong for thinking out the box from where I stay?
    Am I wrong for saying that I choose another way?

    I ain't tryna do what everybody else doing
    Just cause everybody doing what they all do
    If one thing I know, I'll fall but I'll grow
    I'm walking down this road of mine, this road that I call home

*/



#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define sf              scanf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";

typedef long long ll;
typedef unsigned long long llu;

using namespace std;


template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}
template<class T>
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);

    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}

template<class T>
inline void debug(string S1,T S2,string S3)
{
    cout<<S1<<S2<<S3;
}

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


template<class T>
inline int in(register T& num)
{
    register char c=0;
    num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    num=n?-num:num;
    return 1;
}

/******* ! Code start from here ! *******/

int dp[10][500][2];
int m[4];

string s1,s2;
string res1,res2;

int re(int p,int v,int s)
{
    if(p==sz(s1)) return v;

    int &res=dp[p][v][s];

    if(res!=-1) return res;
    res=inf;

    if(s1[p]=='?' && s2[p]=='?')
    {
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                int x=(v*(s==1?-1:1 ) )+ (i-j)*m[p]  ;
                res=min(res,re(p+1,abs( x ),(x<0) ) );
            }
        }
    }
    else if(s1[p]=='?')
    {
        int j=s2[p]-'0';
        for(int i=0;i<=9;i++)
        {

            int x=(v*(s==1?-1:1 ) )+ (i-j)*m[p]  ;
            res=min(res,re(p+1,abs( x ),(x<0) ) );
        }
    }
    else if(s2[p]=='?')
    {
        int i=s1[p]-'0';

        for(int j=0;j<=9;j++)
        {
            int x=(v*(s==1?-1:1 ) )+ (i-j)*m[p]  ;
            res=min(res,re(p+1,abs( x ),(x<0) ) );
        }
    }
    else
    {
        int i=s1[p]-'0';
        int j=s2[p]-'0';

        int x=(v*(s==1?-1:1 ) )+ (i-j)*m[p]  ;
        res=min(res,re(p+1,abs( x ),(x<0) ) );
    }

    return res;
}

void print_res(int p,int v,int s,int val,string a,string b)
{
    if(p==sz(s1))
    {
        reverse(all(a) );
        reverse(all(b) );
        if(res1>a)
        {
            res1=a;
            res2=b;
        }
        else if(res1>=a && res2>b)
        {
            res1=a;
            res2=b;
        }
        return;
    }

    if(s1[p]=='?' && s2[p]=='?')
    {
        for(int j=0;j<=9;j++)
        {
            for(int i=0;i<=9;i++)
            {
                int x=(v*(s==1?-1:1 ) )+ (i-j)*m[p]  ;
                if(re(p+1,abs( x ),(x<0) )==val)
                {
                    print_res(p+1,abs( x ),(x<0),val,a+(char)(i+'0'),b+(char)(j+'0') ) ;
//                    res1.pb(i+'0');
//                    res2.pb(j+'0');
//                    return;

                }

            }
        }
    }
    else if(s1[p]=='?')
    {
        int j=s2[p]-'0';
        for(int i=0;i<=9;i++)
        {
            int x=(v*(s==1?-1:1 ) )+ (i-j)*m[p]  ;
            if(re(p+1,abs( x ),(x<0) )==val)
            { //what_is(p) what_is(i) what_is(x) what_is(val)
                print_res(p+1,abs( x ),(x<0),val,a+(char)(i+'0'),b+(char)(j+'0') ) ;
//                res1.pb(i+'0');
//                res2.pb(j+'0');
//                return;
            }
        }
    }
    else if(s2[p]=='?')
    {
        int i=s1[p]-'0';

        for(int j=9;j>=0;j--)
        {
            int x=(v*(s==1?-1:1 ) )+ (i-j)*m[p]  ;

            if(re(p+1,abs( x ),(x<0) )==val)
            { //what_is(p)
                print_res(p+1,abs( x ),(x<0),val,a+(char)(i+'0'),b+(char)(j+'0') ) ;
//                res2.pb(j+'0');
//                res1.pb(i+'0');
//                return;

            }
        }
    }
    else
    {
        int i=s1[p]-'0';
        int j=s2[p]-'0';

        int x=(v*(s==1?-1:1 ) )+ (i-j)*m[p]  ;

        print_res(p+1,abs( x ),(x<0),val,a+(char)(i+'0'),b+(char)(j+'0') ) ;

//        res1.pb(i+'0');
//        res2.pb(j+'0');

    }
}

int main()
{
//     std::ios_base::sync_with_stdio(false);

    #ifdef kimbbakar
        freopen ( "in.txt", "r", stdin );
        freopen ( "out.txt", "w", stdout );
    #endif

    int t,tcase=1;

    in(t);

    m[0]=1;
    m[1]=10;
    m[2]=100;

    while(t--)
    {
        cin>>s1>>s2;
        reverse(all(s1) );
        reverse(all(s2) );

        res1.clear();
        res2.clear();



        reset(dp,-1);
        string a;
        string b;
        res1=res2="999999";

        print_res(0,0,0,re(0,0,0),a,b);



        pf("Case #%d: ",tcase++);


        cout<<res1<<" "<<res2<<"\n";
    }


    return 0;
}




