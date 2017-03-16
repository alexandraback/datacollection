/***********************
 	
  	root8950

***********************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppii pair< pii,pii >
#define ppll pair< pll,pll >
#define vi vector<int>
#define vll vector< ll >
#define v(x) vector< x >
#define vvi vector< vector< int > > 
#define vv(x) vector< vector< x > > 

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

#else
#define trace(...)
#endif

#define traverse(container, it) for(auto it:container)

#define ft first
#define sd second
#define mp make_pair
#define pb push_back

#define root 1
#define lft (idx << 1)
#define rgt ((idx << 1 ) + 1)
#define cllft lft, st, mid
#define clrgt rgt, mid + 1, ed

#define inf INT_MAX/2
#define linf LLONG_MAX/2

#define all(p) p.begin(), p.end()
#define set(p) memset(p, -1, sizeof(p))
#define clr(p) memset(p, 0, sizeof(p))
#define mem(p, v) memset(p, v, sizeof(p))
#define cpy(d, s) memcpy(d, s, sizeof(s))
#define asst(X,L,R) assert(X >= L && X <= R)

/*
#define gc getchar_unlocked
int rd_int(){ int num=0; char c=gc(); bool flag=0; while(!((c>='0' & c<='9') || c == '-')) c=gc(); if(c=='-'){ flag=1; c=gc(); } while(c>='0' && c<='9'){ num=(num<<1)+(num<<3)+c-'0'; c=gc(); } if(flag) return -num; return num; }
#define pc putchar_unlocked
void wr_int(int num){ if(num<0){pc('-');num=-num;} char snum[20];int i=0;do{snum[i++]=num%10+48;num/=10;}while(num);i--;while(i>=0){pc(snum[i--]);}pc('\n');}
*/

template <class T> T max(T a, T b, T c){ return ( ( a > b ) ? ( ( a > c) ? a : c ) : ( ( b > c ) ? b : c ) ); }
template <class T> T min(T a, T b, T c){ return ( ( a < b ) ? ( ( a < c) ? a : c ) : ( ( b < c ) ? b : c ) ); }

// compiling with gcc11 or above
// g++ -std=c++0x
// Lambdas [capture list](parameters) -> return_type { body }     eg.   auto f = [] (int a,int b) -> int { return a+b; };
// PIE is defined as M_PI

/////////////////////////////////////////////////////////////////////////MACRO ENDS/////////////////////////////////////////////////////////////////////////////////

const int MOD = (1e9) + 7 ;
const int MAXN = (1e5) + 9 ;

int T = 1, N = 1;


int Subsets(int n, vector< pair<string,string> > &vec, map<string,int> &_ma, map<string,int> &_mb) {
	vector<bool> counter(n, 0);
	int ans=0;
	while (1) {
		vector<bool>  cnta(20);
		vector<bool> cntb(20);
		int p=0;
		for (int i = 0; i < n; i++) {
			if (counter[i] == 1) {
				cnta[_ma[vec[i].ft]]=1;
				cntb[_mb[vec[i].sd]]=1;
			}
		}
		bool flag=1;
		for (int i = 0; i < n; i++) {
			if (counter[i] == 0) {
				p++;
				if(cnta[_ma[vec[i].ft]]==0 || cntb[_mb[vec[i].sd]] == 0){
					flag=0;
				}
			}
		}
		if(p!=n && flag){
			ans=max(ans,p);
		}
		int i = 0;
		while (i < n && counter[i] == 1)
			counter[i++] = 0;
		if (i == n)
			break;
		counter[i] = 1;
	}
	return ans;
}

int main() {
	#ifdef ONLINE_JUDGE
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	#endif
	//freopen("tests.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		map<string,int> _ma,_mb;
		vector< pair<string,string> > vec(n);
		vector<string> a(n),b(n);
		for(int i=0;i<n;i++){
			cin >> a[i] >> b[i];
			vec[i].ft=a[i];
			vec[i].sd=b[i];
		}
		sort(all(a));
		sort(all(b));
		_ma[a[0]]=0;
		_mb[b[0]]=0;
		for(int i=1;i<n;i++){
			if(a[i]!=a[i-1]){
				_ma[a[i]]=i;
			}
			if(b[i]!=b[i-1]){
				_mb[b[i]]=i;
			}
		}
		int ans=Subsets(n,vec,_ma,_mb);
		cout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}
