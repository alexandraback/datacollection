#include <bits/stdc++.h>
using namespace std;
/***************************************************************************************************************************************/
typedef long long int LLI;
typedef unsigned long long int ULLI;
#define MP(X,Y)         make_pair(X,Y)
#define fill(a,v)       memset(a,v,sizeof(a))
#define DEBUG(x)        cout << #x << ": " << x << endl;
#define all(x)          (x).begin(),(x).end()
#define SORT(x)         sort(all(x))
#define VI              vector<int>
#define SI              set<int>
#define VS              vector<string>
#define PB              push_back
#define REV(a)          reverse(all(a))
#define BRPS(n,bit)     bitset<bit>(n)
#define LB(A, x)        (lower_bound(all(A), x) - A.begin())//exactly where it starts
#define UB(A, x)        (upper_bound(all(A), x) - A.begin())
#define UNQ(x)          SORT(x),(x).erase(unique(all(x)),x.end())
#define FOR(i,a,b)      for(int i=(int)(a);i<=(int)(b);i++)
#define foreach(e,x)    for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define DBG(v)          std::copy( v.begin(), v.end(), std::ostream_iterator < typeof( *v.begin() )> ( std::cout, " " ) )
#define INF             0x7FFFFFFF
#define INFL            0x7FFFFFFFFFFFFFFF

typedef pair<int, int>PII;
typedef pair<LLI, LLI>PLL;

template<class T> inline T BIGMOD(T n, T m, T mod)
{
    LLI ans = 1;
    LLI k = n;
    while(m)
    {
        if(m & 1)
        {
            ans *= k;
            if(ans>mod) ans %= mod;
        }
        k *= k;
        if(k>mod) k %= mod;
        m >>= 1;
    }
    return ans;
}
#define eps 1e-11
template<class T> string toString(T n)
{
    ostringstream ost;
    ost << n;
    ost.flush();
    return ost.str();
}
template<class T> string toBinary(T n)
{
    string ret="";
    while(n)
    {
        if(n%2==1)ret+='1';
        else ret+='0';
        n>>=1;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
void combination(int n,vector< vector<int> > &ret)
{
    ret.resize(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++)
    {
        ret[i][0]=ret[i][i]=1;
        for(int j=1; j<i; j++)
        {
            ret[i][j]=ret[i-1][j]+ret[i-1][j-1];
        }
    }
}
int toInt(string s)
{
    int r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
LLI toLInt(string s)
{
    LLI r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
vector<string> parse(string temp)
{
    vector<string> ans;
    ans.clear();
    string s;
    istringstream iss(temp);
    while (iss >> s)ans.PB(s);
    return ans;
}
template<class T> inline T gcd(T a, T b)
{
    if (a < 0)return gcd(-a, b);
    if (b < 0)return gcd(a, -b);
    return (b == 0) ? a : gcd(b, a % b);
}
template<class T> inline T lcm(T a, T b)
{
    if (a < 0)return lcm(-a, b);
    if (b < 0)return lcm(a, -b);
    return a*(b / gcd(a, b));
}
template<class T> inline T power(T b, T p)
{
    if (p < 0)return -1;
    if (b <= 0)return -2;
    if (!p)return 1;
    return b*power(b, p - 1);
}

template<class T> inline int asd(T &ret)
{
    char r;
    bool start=false,neg=false;
    ret=0;
    bool isaNumber=false;
    while(true)
    {
        r=getchar();
        if(r==EOF)
        {
            return 0;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
        {
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start)
        {
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(neg)
        ret*=-1;
    return 1;
}

// Yet to Test
template<class T> inline int asd(T &ret1,T &ret2)
{
    asd(ret1);
    asd(ret2);
}
template<class T> inline int asd(T &ret1,T &ret2,T &ret3)
{
    asd(ret1,ret2);
    asd(ret3);
}
template<class T> inline int asd(T &ret1,T &ret2,T &ret3,T &ret4)
{
    asd(ret1,ret2);
    asd(ret3,ret4);
}

template<class T> inline void asdasd(T x,char y)
{
    // 0- print+newline, 1 - print ' ',2 - nothing;
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    char buf[21], *p = buf;
    do
    {
        *p++ = '0' + x % 10;
        x /= 10;
    }
    while (x);
    do
    {
        putchar(*--p);
    }
    while (p > buf);
    if(y==0)putchar('\n');
    else if(y==1)putchar(' ');
}

/*vector IO*/
template < typename value_type >
istream & operator>> ( istream & in, vector < value_type > & a )
{
    typedef typename vector < value_type >::iterator iterator;
    if ( ! a.size( ) )
    {
        size_t n;
        asd(n);
        a.resize( n );
    }
    for ( iterator iter = a.begin(); iter != a.end(); ++ iter )
        asd(*iter);
    return in;
}

//vector1D OUT
template < typename value_type >
ostream & operator<< ( ostream & out, const vector <  value_type > & a )
{
    int sz=a.size();
    FOR(i,0,sz-1)asdasd(a[i],i!=sz);
    return out;
}

//vector2D OUT
template < typename value_type >
ostream & operator<< ( ostream & out, const vector < vector< value_type > > & a )
{
    int sza=a.size();
    int szb=a[0].size();
    FOR(i,0,sza-1)
    {
        FOR(j,0,szb-1)asdasd(a[i][j],j!=sza);
        puts("");
    }
    return out;
}
//set OUT
template < typename value_type >
ostream & operator<< ( ostream & out, const set <  value_type > & a )
{
    foreach(e,a)asdasd(*e,e!=a.end());
    return out;
}
//MAP OUT
template < typename key_type, typename value_type >
ostream & operator<< ( ostream & in, map < key_type, value_type > & a)
{
    foreach(e,a)
    {
        cout << (*e).first << " -> " << (*e).second << endl;
    }
    return in;
}
/*END OF STL IO*/
template < typename key_type, typename value_type >
istream & operator>> ( istream & in, pair < key_type, value_type > & p)
{
    in >> p.first >> p.second;
    return in;
}
template < typename key_type, typename value_type >
ostream & operator<< ( ostream & out, const pair < key_type, value_type > & p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}
vector<int> inverseArray(int n, int m)
{
    vector<int> modI(n + 1,0);
    modI[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        modI[i] = (-(m/i) * modI[m % i]) % m + m;
    }
    return modI;
}

pair<LLI, pair<LLI, LLI> > extendedEuclid(LLI a, LLI b)
{
    LLI x = 1, y = 0;
    LLI xLast = 0, yLast = 1;
    LLI q, r, m, n;
    while(a != 0)
    {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

LLI modInverse(LLI a, LLI m)
{
    return (extendedEuclid(a,m).second.first + m) % m;
}

#define filein(x) freopen(x,"r",stdin)
#define fileout(x) freopen(x,"w",stdout)
#define fst first
#define snd second
//istringstream(temp) >> data >> value >> stamp;
//mod1 = 1000000007, mod2 = 1000000009;
//.016-.040-.900-2.48
/***************************************************************************************************************************************/
#define MX 1000001//10000001
int dp[MX];
int R(int N)
{
    string x = toString(N);
    REV(x);
    return toInt(x);
}

int main()
{
    filein("A-small-attempt0.in");
    fileout("A-small-attempt0.txt");
    fill(dp,120);
    dp[1]=1;
    for(int i=1;i<MX;i++)
    {

        dp[i+1] = min(dp[i+1],1+dp[i]);
        int rev = R(i);
        if(rev<MX)dp[rev]=min(dp[rev],1+dp[i]);
    }
    int kase,ks=0,N;
    asd(kase);
    while(kase--)
    {
        asd(N);
        printf("Case #%d: %d\n",++ks,dp[N]);
    }
}






















