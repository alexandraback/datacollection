#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long  ull;
/*
#include<bits/stdc++.h>


using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI           acos(-1)
#define INF             1<<30
#define DFS_GRAY           -1
#define DFS_WHITE           0
#define DFS_BLACK           1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }

int t, k, l, s,cnt,temp,tot,mx;
ss keys, target,x;
void rec()
{
	
	if (x.length() == s)
	{
		temp = 0;
		lop(i, s)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	lop(i, k)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	//R_W;
	cin >> t;
	long long int m,n;
	n = t;
	m = t-1;
	t = m;
	while(t--)
	{
		cin >> k >> l >> s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
	}
}
*/
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     mp              make_pair
#define     pii             pair<int,int>
#define     fs              first
#define     sc              second
#define     VI              vector<int>
#define     clr(a)          a.clear()
#define     pob             pop_back
#define     pub             push_back
#define     eps             1E-5
#define     sf              scanf
#define     pf              printf
#define     all(a)          a.begin(),a.end()
#define     allr(a)         a.rbegin(),a.rend()
#define     full(a,l)       a,a+l
/*
#include<bits/stdc++.h>


using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI           acos(-1)
#define INF             1<<30
#define DFS_GRAY           -1
#define DFS_WHITE           0
#define DFS_BLACK           1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }

int t, k, l, s,cnt,temp,tot,mx;
ss keys, target,x;
void rec()
{
	
	if (x.length() == s)
	{
		temp = 0;
		lop(i, s)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	lop(i, k)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	//R_W;
	cin >> t;
	long long int m,n;
	n = t;
	m = t-1;
	t = m;
	while(t--)
	{
		cin >> k >> l >> s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
	}
}
*/
#define     fread(name)     freopen(name,"r",stdin)
#define     fwrite(name)    freopen(name,"w",stdout)
#define     sz(a)           (int)a.size()
/*
#include<bits/stdc++.h>


using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI           acos(-1)
#define INF             1<<30
#define DFS_GRAY           -1
#define DFS_WHITE           0
#define DFS_BLACK           1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }

int t, k, l, s,cnt,temp,tot,mx;
ss keys, target,x;
void rec()
{
	
	if (x.length() == s)
	{
		temp = 0;
		lop(i, s)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	lop(i, k)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	//R_W;
	cin >> t;
	long long int m,n;
	n = t;
	m = t-1;
	t = m;
	while(t--)
	{
		cin >> k >> l >> s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
	}
}
*/
#define     count_one       __builtin_popcount
#define     count_onell     __builtin_popcountll
#define     fastIO          ios_base::sync_with_stdio(false)
#define     PI              (acos(-1.0))
#define     linf            (1LL<<62)//>4e18
#define     inf             (0x7f7f7f7f)//>2e9
#define     fore(x,i)       for(typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define     rfore(x,i)      for(typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define     For(i,a,b)      for(int i=a;i<=b;++i)
#define     rFor(i,a,b)     for(int i=a;i>=b;--i)
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//int X[]={1,1,2,2,-1,-1,-2,-2},Y[]={2,-2,1,-1,2,-2,1,-1};
//int X[]={0,-1,-1,-1,0,1,1,1},Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0},Y[]={0,1,0,-1};
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ll bigMod(ll a,ll x,ll p){ll r=1;while(x>0){if(x%2!=0){r=(r*a)%p;}a=(a*a)%p;x=(x>>1);}return r;}
//ll modInverse(ll a, ll p){return bigMod(a,p-2,p);}
//ll extGcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extGcd(b,a%b,y,x);y-=a/b*x;return g;}}
template<class T> T pwr(T b, T p){T r=1,x=b;while(p){if(p&1)r*=x;x*=x;p=(p>>1);}return r;}
template<class T> T lcm(T a,T b){return(a/__gcd(a,b))*b;}
template<class T> T sqr(T a){return a*a;}
template<class T> void xswap (T &x,T &y){if(x!=y){x^=y;y^=x;x^=y;}}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//struct tuple{double f,s,t;tuple(){}tuple(double a,double b,double c){f=a,s=b,t=c;}};
//int cross_product(tuple a,tuple b){int v=a.f*(b.s-b.t)-a.s*(b.f-b.t)+a.t*(b.f-b.s);return (v==0?0:(v>0?+1:-1));}
//tuple make_vector(tuple s,tuple e){tuple a;a.f=e.f-s.f;a.s=e.s-s.s;a.t=e.t-s.t;return a;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T> inline bool isOn(T &mask,int pos){return((mask)&(1LL<<pos));}
template<typename T> inline T setf(T mask,int pos){return mask=((mask)&(~(1LL<<pos)));}
template<typename T> inline T sett(T mask,int pos){return mask=((mask)|(1LL<<pos));}
template<typename T> inline T flip(T mask,int pos){return mask=((mask)^(1LL<<pos));}
/*
#include<bits/stdc++.h>


using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI           acos(-1)
#define INF             1<<30
#define DFS_GRAY           -1
#define DFS_WHITE           0
#define DFS_BLACK           1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }

int t, k, l, s,cnt,temp,tot,mx;
ss keys, target,x;
void rec()
{
	
	if (x.length() == s)
	{
		temp = 0;
		lop(i, s)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	lop(i, k)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	//R_W;
	cin >> t;
	long long int m,n;
	n = t;
	m = t-1;
	t = m;
	while(t--)
	{
		cin >> k >> l >> s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
	}
}
*/
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//double dtor(double x){return x*PI/180.0;}
//double rtod(double x){return x*180.0/PI;}
//double pdis(pdd a,pdd b){return sqrt((double)sqr(a.fs-b.fs)+sqr(a.sc-b.sc));}
//template<class T> double rAng(T a,T b,T c){double d=(sqr(a)+sqr(b)-sqr(c))/(a*b*2);d=(d<-1?-1:(d>1?1:d));return acos(d);}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//template<class T> string to_string(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int to_int(string s){int r=0;istringstream sin(s);sin>>r;return r;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> void put(T1 e){cout<<e<<endl;}
/*
#include<bits/stdc++.h>


using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI           acos(-1)
#define INF             1<<30
#define DFS_GRAY           -1
#define DFS_WHITE           0
#define DFS_BLACK           1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }

int t, k, l, s,cnt,temp,tot,mx;
ss keys, target,x;
void rec()
{
	
	if (x.length() == s)
	{
		temp = 0;
		lop(i, s)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	lop(i, k)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	//R_W;
	cin >> t;
	long long int m,n;
	n = t;
	m = t-1;
	t = m;
	while(t--)
	{
		cin >> k >> l >> s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
	}
}
*/
/*#include<bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
    long long int t,r,c,q,w,ans,i=1,div;
    cin >> t;
    while(t--)
    {
        cin >> r >> c >> w;
        long long int mul = r*(c-1);
        ans = mul/w;
        cout <<"Case #" << i << ": " << ans + w << endl;
        i++;
    }
}*/
template<class T1,class T2> void put(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void put(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void put(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void put(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1> void putv(vector<T1>e1){for(int i=0;i<sz(e1);i++)(!i?cout<<e1[i]:cout<<" "<<e1[i]);cout<<endl;}
template<class T1> void puta(T1 arr[],int l){for(int i=0;i<l;i++)(!i?cout<<arr[i]:cout<<" "<<arr[i]);cout<<endl;}
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T1> bool tk(T1 &e1){return(cin>>e1?true:false);}
template<class T1,class T2> bool tk(T1 &e1,T2 &e2){return(cin>>e1>>e2?true:false);}
template<class T1,class T2,class T3> bool tk(T1 &e1,T2 &e2,T3 &e3){return(cin>>e1>>e2>>e3?true:false);}
template<class T1,class T2,class T3,class T4> bool tk(T1 &e1,T2 &e2,T3 &e3,T4 &e4){return(cin>>e1>>e2>>e3>>e4?true:false);}
///HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
int K,TL,SL;
string keys;
/*#include<bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
    long long int t,r,c,q,w,ans,i=1,div;
    cin >> t;
    while(t--)
    {
        cin >> r >> c >> w;
        long long int mul = r*(c-1);
        ans = mul/w;
        cout <<"Case #" << i << ": " << ans + w << endl;
        i++;
    }
}*/
string tword;

pii sol(int idx,string s)
{
    if(idx==SL)
    {
        int ans = 0;
        For(i,0,SL-TL)
        {
            if(!s.compare(i,TL,tword))ans++;
        }
//        put(s," #end",ans);
        return mp(ans,ans);
    }
    pii ans = mp(0,-inf);
    For(i,0,K-1)
    {
    	/*
#include<bits/stdc++.h>


using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI           acos(-1)
#define INF             1<<30
#define DFS_GRAY           -1
#define DFS_WHITE           0
#define DFS_BLACK           1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }

int t, k, l, s,cnt,temp,tot,mx;
ss keys, target,x;
void rec()
{
	
	if (x.length() == s)
	{
		temp = 0;
		lop(i, s)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	lop(i, k)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	//R_W;
	cin >> t;
	long long int m,n;
	n = t;
	m = t-1;
	t = m;
	while(t--)
	{
		cin >> k >> l >> s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
	}
}
*/
        pii tmp = sol(idx+1,s+keys[i]);
        ans.sc = max(ans.sc,tmp.sc);
        /*#include<bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
    long long int t,r,c,q,w,ans,i=1,div;
    cin >> t;
    while(t--)
    {
        cin >> r >> c >> w;
        long long int mul = r*(c-1);
        ans = mul/w;
        cout <<"Case #" << i << ": " << ans + w << endl;
        i++;
    }
}*/
        ans.fs += tmp.fs;
    }
    return ans;
}

int main()
{
  freopen("B-small-attempt0 (4).in","r",stdin);
  freopen("q1out.txt.txt","w",stdout);
    int T,t=1;
    cin>>T;
    long long int yo = T-1;
    yo = yo + 1;
    while(yo--)
    {
//        tk(K,TL,SL);
        cin>>K>>TL>>SL;
        /*
#include<bits/stdc++.h>


using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI           acos(-1)
#define INF             1<<30
#define DFS_GRAY           -1
#define DFS_WHITE           0
#define DFS_BLACK           1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }

int t, k, l, s,cnt,temp,tot,mx;
ss keys, target,x;
void rec()
{
	
	if (x.length() == s)
	{
		temp = 0;
		lop(i, s)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	lop(i, k)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	//R_W;
	cin >> t;
	long long int m,n;
	n = t;
	m = t-1;
	t = m;
	while(t--)
	{
		cin >> k >> l >> s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
	}
}
*/
        cin>>keys;
        cin>>tword;
        pii ans = sol(0,"");
        /*
#include<bits/stdc++.h>


using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI           acos(-1)
#define INF             1<<30
#define DFS_GRAY           -1
#define DFS_WHITE           0
#define DFS_BLACK           1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }

int t, k, l, s,cnt,temp,tot,mx;
ss keys, target,x;
void rec()
{
	
	if (x.length() == s)
	{
		temp = 0;
		lop(i, s)
		{
			if (x.substr(i, l) == target)++cnt,++temp;
		}
		mx = max(mx, temp);
		return;
	}
	lop(i, k)
	{
		x += keys[i];
		rec();
		x.pop_back();
	}
}
int main()
{
	//R_W;
	cin >> t;
	long long int m,n;
	n = t;
	m = t-1;
	t = m;
	while(t--)
	{
		cin >> k >> l >> s>>keys>>target;
		cnt =0;
		mx = 0;
		tot = pw(k,s);
		rec();
		printf("Case #%d: ", i + 1);
		cout <<fixed<<setprecision(12)<<mx-double(cnt)/tot<<endl;
	}
}
*/
/*#include<bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
    long long int t,r,c,q,w,ans,i=1,div;
    cin >> t;
    while(t--)
    {
        cin >> r >> c >> w;
        long long int mul = r*(c-1);
        ans = mul/w;
        cout <<"Case #" << i << ": " << ans + w << endl;
        i++;
    }
}*/
        double ok = (double)ans.sc-double(ans.fs)/double(pwr(K,SL));
        /*#include<bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
    long long int t,r,c,q,w,ans,i=1,div;
    cin >> t;
    while(t--)
    {
        cin >> r >> c >> w;
        long long int mul = r*(c-1);
        ans = mul/w;
        cout <<"Case #" << i << ": " << ans + w << endl;
        i++;
    }
}*/
        cout<<"Case #"<<t++<<": "<<setprecision(8)<<ok<<endl;
    }
    /*#include<bits/stdc++.h>
 
 
using namespace std;
 
int main()
{
    long long int t,r,c,q,w,ans,i=1,div;
    cin >> t;
    while(t--)
    {
        cin >> r >> c >> w;
        long long int mul = r*(c-1);
        ans = mul/w;
        cout <<"Case #" << i << ": " << ans + w << endl;
        i++;
    }
}*/
    return 0;
}


