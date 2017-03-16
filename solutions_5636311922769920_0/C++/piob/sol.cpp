#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long int64;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int k, c, s;

void solve(){
	if(k == 1){
		printf("1\n");
		return;
	}
	if(c == 1){
		if(k == s){
			FWD(i,1,k+1) printf("%d ", i);
			printf("\n");
		}else{
			printf("IMPOSSIBLE\n");
		}
	}else{
		if(k <= 2*s){
			int64 p = 1;
			FWD(i,1,c) p *= k;
			FWD(i,0,s){
				if(2+2*i+2*i*p <= p*k)
					printf("%lld ", 2+2*i+2*i*p);
				else if(1+2*i+2*i*p <= p*k)
					printf("%lld ", 1+2*i+2*i*p);
			}
			printf("\n");
		}else{
			printf("IMPOSSIBLE\n");			
		}
	}
}

int main(){
	int zzz;
	scanf("%d", &zzz);
	FWD(zz,1,zzz+1){
		printf("Case #%d: ", zz);
		scanf("%d %d %d", &k, &c, &s);
		solve();
	}
	return 0;
}
