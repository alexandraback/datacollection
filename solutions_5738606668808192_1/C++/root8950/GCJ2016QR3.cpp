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
#define vvi vector< vi > 
#define vvll vector< vll > 

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
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
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed

#define inf INT_MAX/2
#define linf LLONG_MAX/2

#define all(p) p.begin(),p.end()
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

template <class T> T max(T a,T b,T c){return ( ( a > b ) ? ( ( a > c) ? a : c ) : ( ( b > c ) ? b : c ) );}
template <class T> T min(T a,T b,T c){return ( ( a < b ) ? ( ( a < c) ? a : c ) : ( ( b < c ) ? b : c ) );}
// compiling with gcc11 or above
// g++ -std=c++0x
// Lambdas [capture list](parameters) -> return_type { body }     eg.   auto f = [] (int a,int b) -> int { return a+b; };
// PIE is defined as M_PI

/////////////////////////////////////////////////////////////////////////MACRO ENDS//////////////////////////////////////////////////////////////////////////

const int MOD = 1000000000 + 7 ;
const int MAXN = 100000 + 9 ;

#define sz 4e7+1
vector<int> pr;
vector<bool> primes(sz,1);
vector<int> lp(sz,-1);
void sieve(){
	primes[0]=primes[1]=0;
	for(int i=2;i*i<=sz;i++){
		if(primes[i]==1){
			for(int j=2*i;j<sz;){
				primes[j]=0;
				lp[j]=i;
				j=j+i;
			}
		}
	}
	for(int i=0;i<sz;i++){
		if(primes[i]==1){
			pr.pb(i);
		}
	}
}

ll genNumber(vector<bool> &vec, int base){
	ll num = 1;
	for(int i=0;i<14;i++){
		num = (num * base) + ( (vec[i] == 0) ? 0 : 1 );
	}
	num = (num * base) + 1;
	return num;
}

pair<bool,int> isprime(ll num){
	if(num < sz){
		if(primes[num]==0){
			return mp(0,lp[num]);
		}
		else{
			return mp(1,-1);
		}
	}
	int loop=pr.size();
	for(int i=0;i<loop;i++){
		if(num % pr[i]==0){
			return mp(0,pr[i]);
		}
	}
	return mp(1,-1);
}

vector< vector<bool> > ans;
vector< vector<int> > hlp;
void solve(int n){
	vector<bool> counter(n,0);
	while(1){
		ll num;
		bool flag=1;
		vector<int> div;
		for(int i=2;i<=10;i++){
			num=genNumber(counter,i);
			pair<bool,int> bar = isprime(num);
			if(bar.ft == 1){
				flag=0;
				break;
			}
			div.pb(bar.sd);
		}
		if(flag==1){
			ans.pb(counter);
			hlp.pb(div);
		}
		if(ans.size()==500) break;
		int i=0;
		while(i<n && counter[i]==1)
			counter[i++]=0;
		if(i==n)
			break;
		counter[i]=1;
	}
}

int main(){
	#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#endif
	//freopen("tests.txt","r",stdin)
	//freopen("out.txt","w",stdout)
	int t=1;
	sieve();
	cin >> t;
	int tc=1;
	while(t--){
		cout << "Case #" << tc++ << ":\n";
		int n,j;
		cin >> n >> j;
		solve(14);
		for(int i=0;i<j;i++){
			cout << "1";
			for(int k=0;k<14;k++){
				cout << ans[i][k];
			}
			cout << "1";
			cout << "1";
			for(int k=0;k<14;k++){
				cout << ans[i][k];
			}
			cout << "1 ";
			for(int k=0;k<9;k++){
				cout << hlp[i][k] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
