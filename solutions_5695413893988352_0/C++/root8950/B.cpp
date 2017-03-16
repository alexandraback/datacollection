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
		if(l==1){
			if(a[0]=='?' && b[0]=='?')
				cout << "0 0\n";
			else{
				if(b[0]=='?') b[0]=a[0];
				else if(a[0]=='?')a[0]=b[0];
				cout << a[0] << " " << b[0] << "\n";
			}
		}
		else if(l==2){
			vector< pair< int,pii > > ans;
			for(int i=0;i<=9;i++){
				for(int j=0;j<=9;j++){
					for(int k=0;k<=9;k++){
						for(int m=0;m<=9;m++){
							int x=0,y=0;
							if(a[0] == '?') x=i;
							else x=a[0]-'0';
							if(a[1] == '?') x=x*10+j;
							else x=x*10+a[1]-'0';

							if(b[0] == '?') y=k;
							else y=b[0]-'0';
							if(b[1] == '?') y=y*10+m;
							else y=y*10+b[1]-'0';

							ans.pb({abs(x-y),{x,y}});
						}
					}

				}
			}
			sort(all(ans));
		//	for(int i=0;i<ans.size();i++){
					if(ans[0].sd.ft/10==0){
						cout << "0";
					}
					cout << ans[0].sd.ft << " ";
					if(ans[0].sd.sd/10==0){
						cout << "0";
					}
					cout << ans[0].sd.sd << "\n";
				//	break;
		//	}
		}
		else{
			vector< pair<int,pii > >ans;
			for(int i=0;i<=9;i++){
				for(int j=0;j<=9;j++){
					for(int k=0;k<=9;k++){
						for(int m=0;m<=9;m++){
							for(int p=0;p<=9;p++){
								for(int q=0;q<=9;q++){
									int x=0,y=0;
									if(a[0] == '?') x=i;
									else x=a[0]-'0';
									if(a[1] == '?') x=x*10+j;
									else x=x*10+a[1]-'0';
									if(a[2] == '?') x=x*10+k;
									else x=x*10+a[2]-'0';

									if(b[0] == '?') y=m;
									else y=b[0]-'0';
									if(b[1] == '?') y=y*10+p;
									else y=y*10+b[1]-'0';
									if(b[2] == '?') y=y*10+q;
									else y=y*10+b[2]-'0';
		
									ans.pb({abs(x-y),{x,y}});
								}
				
							}
						}
					}

				}
			}
			sort(all(ans));
		//	for(int i=0;i<ans.size();i++){
		//		if(ans[i].size()>0){
					if(ans[0].sd.ft/100==0){
						cout << "0";
					}
					if(ans[0].sd.ft/10==0){
						cout << "0";
					}
					cout << ans[0].sd.ft << " ";
					if(ans[0].sd.sd/100==0){
						cout << "0";
					}
					if(ans[0].sd.sd/10==0){
						cout << "0";
					}
					cout << ans[0].sd.sd << "\n";
					//break;
		//		}
		//	}
		}
	}
	return 0;
}
