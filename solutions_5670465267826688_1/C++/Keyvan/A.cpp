/*
ID: keyvank2
TASK: combo
LANG: C++
*/

#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define FOR(i,j,k) for(int i = j; i < (int)(k); i++)
#define FORV(i, v) FOR(i, 0, ((v).size()))
#define REP(i,j,k) for(int i = j; i >= (int)(k); i--)
#define setmax(i) const int maxn = (int) i;
#define setmod(i) const int MOD = (int) i;
#define all(a) a.begin(),a.end()
#define autodef(x,v) typeof(v) x = (v)
#define autoref(x,v) typeof(v)& x = (v)
#define forit(it, c) for (autodef(it, ((c).begin())); it != ((c).end()); ++it)

//typedef complex<double> Point;
//#define X real()
//#define Y imag()

using namespace std;

//ifstream fin("");
//ofstream fout("");
//#define cin fin
//#define cout fout

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef pair<pii,int> ppi;
typedef pair<pll,ll> ppl;
typedef pair<int,pii> pip;
typedef pair<ll,pll> plp;
typedef pair<pii,pii> ppp;

const int INF = (int) 2e9;
const ll INFL = (ll) 9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const ll MAXLL = ((~0) ^ ((ll)1 << 63));

template<class T> inline T pow2(T a) { return a*a;}
template<class T> inline bool mineq(T& a, T b){return (a > b) ? (a=b, true) : false;}
template<class T> inline bool maxeq(T& a, T b){return (a < b) ? (a=b, true) : false;}

//srand (time(NULL));

#define int long long

inline int mul(int a, int b)
{
    if(a == -1 || a == 1 || b == 1 || b == -1)
	return a*b;
    if(abs(a) == abs(b))
	return (a*b < 0 ? 1:-1);

    int sgn = (a*b < 0? -1 : 1);
    a = abs(a);
    b = abs(b);

    if((a == 2 && b == 4) || (a == 3 && b == 2) || (a == 4 && b == 3))
	sgn *= -1;

    FOR(i,2,4+1)
	if(i != b && i != a)
	{
	    return i*sgn;
	}

    cerr << "MUL ERROR!";
    return 0;
}

inline int po(int a, int b)
{
    int t = 1;
    FOR(i,0,b)
    {
	t = mul(t,a);
    }
    return t;
}

setmax(1e6+10);

const string no = "NO" , yes = "YES";

int n,x, l[maxn], r[maxn];
string str, t;

inline int toint(char a)
{
    return (a == 'i' ? 2 : (a == 'j'?3:4) );
}

void processlr()
{
    l[0] = toint(str[0]);
    FOR(i,1,n)
    {
	l[i] = mul(l[i-1],toint(str[i]));
    }

    r[n-1] = toint(str[n-1]);
    REP(i,n-2,0)
    {
	r[i] = mul(toint(str[i]),r[i+1]);
    }
}

string bruteforce()
{
    str.clear();
    FOR(i,0,x)
	str += t;

  // if(str.size() < 100)
    //   cerr << str << endl;
    n *= x;

    processlr();

    int mid = 0;
    FOR(i,0,n)
    {
	FOR(j,i+2,n)
	{
	    mid = (j == i+2? toint(str[j-1]):mul(mid,toint(str[j-1])));
	    if( l[i] == 2 && mid == 3 && r[j] == 4)
		return yes;
	}
    }
    return no;
}

inline int calcleft(int p)
{
    int now = l[p];
    FOR(i,0,4)
    {
	if(now == 2)
	    return i;
	now = mul(l[n-1],now);
    }
    return INF;
}

inline int calcright(int p)
{
    int now = r[p];
    FOR(i,0,4)
    {
	if(now == 4)
	    return i;
	now = mul(now,r[0]);
    }
    return INF;
}

inline int calcmid(int lp, int rp)
{
    int now = 1, l2 = (lp == n? 1: r[lp]), r2 = (rp == -1? 1 : l[rp]);
    FOR(i,0,4)
    {
	int cur = mul(mul(l2,now),r2);
	if(cur == 3)
	    return i;
	now = mul(now,r[0]);
    }
    return INF;
}

string solve()
{
    cin >> n >> x >> str;
    
    processlr();

    int mid = 0;
    FOR(i,0,n)
    {
	FOR(j,i+2,n)
	{
	    int now = calcleft(i) + calcright(j);
	    mid = (j == i+2? toint(str[j-1]):mul(mid,toint(str[j-1])));

	    if(now <= x-1 && now % 4 == (x-1)%4 && mid == 3)
		return yes;
	}
    }

    FOR(i,0,n)
    {
	FOR(j,0,n)
	{
	    int now =  calcleft(i) + calcright(j) + calcmid(i+1,j-1);
	    if(now % 4 == (x-2) % 4 && now <= x-2)
		return yes;
	}
    }
    return no;
    
}

void check()
{
    while(true)
    {
	int a,b;
	cin >> a >> b;
	cerr << mul(a,b) << endl;
    }
}

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
  
    //check();

    int z;
    cin >> z;
    FOR(i,1,z+1)
    {
	cout << "Case #" << i << ": " << solve() << "\n";
	cerr << "Case #" << i << ": Done" << endl;
    }

}
