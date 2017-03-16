#include <bits/stdc++.h>
#define openfile(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define mpr std::make_pair
#define lg(x) (31-__builtin_clz(x))
#define lgll(x) (63-__builtin_clzll(x))
#define __count __builtin_popcount
#define __countll __builtin_popcountll
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define ALL(c) (c).begin(),(c).end()
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define FORit(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define pb push_back
#define RI(x) scanf("%d",&x)
#define RID(x) int x;RI(x)
using namespace std;
typedef long long LL;
typedef double LD;
typedef vector<int> VI;
typedef std::pair<int,int> PII;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}
const int N=1010, INF=1e9;
const LD EPS=1e-7;
int T;
char str[N];

// does not work when n is prime
long long modit(long long x,long long mod) {
	if(x>=mod) x-=mod;
	//if(x<0) x+=mod;
	return x;
}
long long mult(long long x,long long y,long long mod) {
	long long s=0,m=x%mod;
	while(y) {
		if(y&1) s=modit(s+m,mod);
		y>>=1;
		m=modit(m+m,mod);
	}
	return s;
}
long long f(long long x,long long mod) {
	return modit(mult(x,x,mod)+1,mod);
}
long long pollard_rho(long long n) {
  if(!(n&1)) return 2;
  while (true) {
    long long y=2, x=rand()%(n-1)+1, res=1;
    for (int sz=2; res==1; sz*=2) {
      for (int i=0; i<sz && res<=1; i++) {
        x = f(x, n);
        res = __gcd(abs(x-y), n);
      }
      y = x;
    }
    if (res!=0 && res!=n) return res;
  }
}
long long power(long long x,long long p,long long mod){
	long long s=1,m=x;
	while(p) {
		if(p&1) s=mult(s,m,mod);
		p>>=1;
		m=mult(m,m,mod);
	}
	return s;
}
long long wit[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool witness(long long a,long long n,long long u,int t){
	long long x=power(a,u,n);
	for(int i=0;i<t;i++) {
		long long nx=mult(x,x,n);
		if(nx==1&&x!=1&&x!=n-1) return 1;
		x=nx;
	}
	return x!=1;
}

bool miller_rabin(long long n) {
	// iterate s times of witness on n
	// return 1 if prime, 0 otherwise
	if(n<2) return 0;
	if(!(n&1)) return n==2;
	long long u=n-1;
	int t=0;
	// n-1 = u*2^t
	while(!(u&1)) {
		u>>=1;
		t++;
	}
	FOR(i,7) {
		long long a = wit[i];
		if(a > n-2) break;
		if(witness(a,n,u,t)) return 0;
	}
	return 1;
}

int test(long long bits){
	vector<int> dig;
	while(bits){
		dig.pb(bits%2);
		bits>>=1;
	}
	int len = dig.size();
	for(int i=2;i<=10;i++){
		long long now = 0;
		for(int j=len-1;j>=0;j--){
			now = now*i + dig[j];
		}
		if(miller_rabin(now))return false;
	}
	return true;
}

int find_f(long long bits){
	vector<int> dig;
	while(bits){
		dig.pb(bits%2);
		bits>>=1;
	}
	int len = dig.size();
	for(int i=2;i<=10;i++){
		long long now = 0;
		for(int j=len-1;j>=0;j--){
			now = now*i + dig[j];
		}
		long long factor = pollard_rho(now);
		//printf(" %lld", now);
		printf(" %lld",factor);
		assert(now % factor==0);
		assert(1< factor && factor < now);
	}
	puts("");
	return true;
}
int main(){
	int t = 0;

	scanf("%d",&T);
	int n,j;
	bool db = false;
	while(t++ < T){
		printf("Case #%d:\n", t);
		scanf("%d %d",&n,&j);
		if(n == 32) db = true, n /= 2;
		int start = (1<<(n-1))+1;
		int end = (1<<n);
		for(int i=start;i<end && j>0; i+=2){
			if(test(i)){
				int tmp = i;
				vector<int> dig;
				while(tmp){
					dig.pb(tmp%2);
					tmp>>=1;
				}
				
				for(int k = (int)dig.size()-1;k>=0;k--)
					printf("%d",dig[k]);
				if(db){
					for(int k = (int)dig.size()-1;k>=0;k--)
					printf("%d",dig[k]);
				}
				find_f(i);
				j--;
			}
		}
	}
}
