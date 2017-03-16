
// AUTHOR: AMAN JAIN
#include <bits/stdc++.h>
using namespace std;

#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)

#define p(n)                        printf("%d",&n)
#define pc(n)                       printf("%c",&n)
#define pl(n)                       printf("%lld",&n)
#define pf(n)                       printf("%lf",&n)
#define ps(n)                       printf("%s",n)

#define VI vector < int >
#define VVI(A,N,M) vector< VI > A( N, VI (M) )
#define LL long long
#define LLU unsigned long long
#define PI acos(-1)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size()) 
#define CLR(v) memset(v,0,sizeof(v))
#define SORT(c) sort(ALL(c)) 
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FOR(i,start,end) for(int i=start;i<end;i++)
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define sieve(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define INF 1000000007
#define EPS 1e-9
#define mt(x, y, z) mp(mp(x,y),z)
#define in_s(c,x) ((c).find(x) != (c).end()) 
#define in_o(c,x) (find(all(c),x) != (c).end()) 
#define setbits(x) __builtin_popcount(x) //tell number of 1's in binary form
#define GC getchar_unlocked
#define out_c(start,end) copy(start, end, ostream_iterator< typeof(*start) >(cout, " "));
template<class T>inline T modinv(T a,T n){T i=n,v=0,d=1;while(a>0){T t=i/a,x=a;a=i%x;i=x;x=d;d=v-t*x;v=x;}return (v+n)%n;}
LL modpow(LL n ,LL k,LL mod){LL ans=1;while(k>0){if(k&1)ans=(ans*n)%mod;k>>=1;n=(n*n)%mod;}return ans%mod;}
//template<class T>inline void output(T a){if(a){T v=a%10;output(a/10);putchar((char)(v+'0'));}}
//template<class T>inline T input(T x){char c=GC();x=0;T s=1;while(c<48||c>57){if(c=='-')s=-1;c=GC();}while(c>=48&&c<=57){x=(x<<3)+(x<<1)+c-48;c=GC();}return x*s;}

template <class T> string str(T Number){
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << Number;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str();
	return Result;
}
LL StringToNumber ( const string &Text )
{
     istringstream ss(Text);
     LL result;
     return ss >> result ? result : 0;
}
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
template<class T>inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
double rnd(float d) //for rounding values
{
	          return floor(d + 0.49);
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	for(int g=1;g<=T;++g){
		printf("Case #%d: ",g);
		string s;
		cin>>s;
		string t;
		LL p;
		for(int i=0;i<sz(s);++i){
			if(s[i]=='/'){
				p=StringToNumber(t);
				t="";
			}
			else t.pb(s[i]);
		}
		LL q=StringToNumber(t);
		LL d=gcd(p,q);
		p/=d;
		q/=d;
		if(p==0 || p>q || ((q&(q-1))!=0)){
			printf("impossible\n");
			continue;
		}
		if(p==1 && q==1){
			printf("0\n");
			continue;
		}
		if(p==1 && ((q&(q-1))==0)){
			int co=0;
			while(q>1){
				q/=2;
				++co;
			}
			printf("%d\n",co);
			continue;
		}
		// if(((q&(q-1)))!=0){
		// 	printf("impossible\n");
		// 	continue;
		// }
		// if(p<=q){
		// 	int co=0;
		// 	while(q>1){
		// 		q/=2;
		// 		++co;
		// 	}
		// 	--co;
		// 	if(co>=0){
		// 		printf("%d\n",co);
		// 		continue;
		// 	}
		// }
		// printf("impossible\n");
		int co1=0;
		LL m=q;
		while(m>1){
			m/=2;
			++co1;
		}
		int co2=0;
		LL n=p;
		while(n>1){
			n/=2;
			++co2;
		}
		printf("%d\n",co1-co2);
	}

	return 0;
}