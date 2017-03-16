
/****** BISMILLAH HIR RAHMANIR RAHIM ******/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef map<string,string> mss;
typedef map<int, vector<int> > mvii;
typedef map<int, int> mii;
typedef queue <int> qi;
typedef map <int, vector<string> > mvis;
typedef map <string, vector<int> > mvsi;
typedef vector <string> vs;
typedef pair <int, int> pii;

#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define ALL(a) a.begin(), a.end()
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define INF 2000000000
#define pb push_back
#define MAX 100002
#define debug cout<<"A"<<"\n"
#define prnt(a) cout<<a<<"\n"
#define mod 1000000007LL
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=b; i--)
#define itrALL(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define lc ((node)<<1)
#define rc ((node)<<1|1)
#define VecPrnt(v) FOR(j,0,v.size()) cout<<v[j]<<" "; cout<<endl
#define endl "\n"
#define PrintPair(x) cout<<x.first<<" "<<x.second<<endl


/* Direction Array */

// int fx[]={1,-1,0,0};
// int fy[]={0,0,1,-1};
// int fx[]={0,0,1,-1,-1,1,-1,1};
// int fy[]={-1,1,0,0,1,1,-1,-1};

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}

inline ll power(ll a, ll b)
{
	ll multiply=1;
	FOR(i,0,b)
	{
		multiply*=a;
	}
	return multiply;
}

/****** END OF HEADER ******/

int diff;
string C, J;
vector<string> cv, cj;

void go1(int idx, string now)
{
	// prnt(now);
	if(idx==C.size())
	{
		cv.pb(now);
		return;
	}

	if(C[idx]!='?')
	{
		now+=C[idx];
		go1(idx+1,now);
	}
	else
	{
		// debug;
		FOR(i,0,10)
		{
			string temp=now; temp+=char(i+'0');
			go1(idx+1,temp);
		}
	}
}


void go2(int idx, string now)
{
	// prnt(now);
	if(idx==J.size())
	{
		cj.pb(now);
		return;
	}

	if(J[idx]!='?')
	{
		now+=J[idx];
		go2(idx+1,now);
	}
	else
	{
		// debug;
		FOR(i,0,10)
		{
			string temp=now; temp+=char(i+'0');
			go2(idx+1,temp);
		}
	}
}

int main()
{
	// ios_base::sync_with_stdio(0); 
	// cin.tie(NULL); cout.tie(NULL);
	freopen("in_b.txt","r",stdin);
	freopen("out_b.txt","w",stdout);

	int test, cases=1;
	cin>>test;

	while(test--)
	{
		cin>>C>>J;
		cv.clear(); cj.clear();

		go1(0,"");
		go2(0,"");

		// VecPrnt(cv);
		// VecPrnt(cj);

		int diff=MAX;

		int a=MAX, b=MAX;

		FOR(i,0,cv.size())
		{
			FOR(j,0,cj.size())
			{
				int x=0, y=0;

				FOR(k,0,cv[i].size()) x=x*10+(cv[i][k]-'0');
				FOR(k,0,cj[j].size()) y=y*10+(cj[j][k]-'0');

				// cout<<x<<" "<<y<<endl;

				if(abs(x-y)<diff)
				{
					diff=abs(x-y);
					a=x, b=y;
				}
				else if(abs(x-y)==diff)
				{
					if(a>x)
					{
						a=x;
						b=y;
					}
					else if(a==x)
					{
						if(b>y) b=y;
					}
				}
			}
		}

		string A="", B="";

		while(a>0)
		{
			A+=char(a%10+'0');
			a/=10;
		}

		while(b>0)
		{
			B+=char(b%10+'0');
			b/=10;
		}

		// cout<<A<<" "<<B<<endl;

		REVERSE(A); REVERSE(B);

		while(A.size()<C.size()) A='0'+A;
		while(B.size()<J.size()) B='0'+B;

		printf("Case #%d: ", cases++);
		cout<<A<<" "<<B<<endl;
	}

	return 0;
}







