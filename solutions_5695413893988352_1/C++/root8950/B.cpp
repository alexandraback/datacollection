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

int main() {
	#ifdef ONLINE_JUDGE
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	#endif
	//freopen("tests.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string a,b;
		cin >> a >> b;
		int l=a.length();
		cout << "Case #" << t << ": ";
		bool flag=1;
		int mx=0;
		string x="",y="";
		for(int i=0;i<l;i++){
			if(flag){
				if(a[i]=='?' && b[i]=='?'){
					x+='0';
					y+='0';
				}
				else if(a[i]=='?' && b[i]!='?'){
					x+=b[i];
					y+=b[i];
				}
				else if(a[i]!='?' && b[i]=='?'){
					x+=a[i];
					y+=a[i];
				}
				else{
					x+=a[i];
					y+=b[i];
					if(a[i]!=b[i]){
						flag=0;
						if(a[i] > b[i]) mx=1;
						else mx=2;
					}
				}
			}
			else{
				if(mx==1){
					if(a[i]=='?' && b[i]=='?'){
						x+='0';
						y+='9';
					}
					else if(a[i]=='?' && b[i]!='?'){
						x+='0';
						y+=b[i];
					}
					else if(a[i]!='?' && b[i]=='?'){
						x+=a[i];
						y+='9';
					}
					else{
						x+=a[i];
						y+=b[i];
					}
				}
				else{
					if(a[i]=='?' && b[i]=='?'){
						x+='9';
						y+='0';
					}
					else if(a[i]=='?' && b[i]!='?'){
						x+='9';
						y+=b[i];
					}
					else if(a[i]!='?' && b[i]=='?'){
						x+=a[i];
						y+='0';
					}
					else{
						x+=a[i];
						y+=b[i];
					}
				}
			}
		}
		cout << x << " " << y << "\n";
	}
	return 0;
}
