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

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
int P[1010];

int ceil(int a, int b){
	return (a + b-1) / b;
}

bool check(int t){
	for(int r = 0; t; --t, ++r){
		int c = 0;
		FWD(i,0,n){
			c += ceil(P[i], t) - 1;
			if(c > r) goto fail;
		}
		return 1;
	fail:
		;
	}
	return 0;
}

int main(){
	int z; scanf("%d", &z);
	FWD(c,1,z+1){
		scanf("%d", &n);
		FWD(i,0,n) scanf("%d", &P[i]);
		int lo = 0, hi = 1010;
		while(hi-lo>1){
			int mi = (lo + hi)/2;
			if(check(mi))
				hi = mi;
			else
				lo = mi;
		}
		printf("Case #%d: %d\n", c, hi);
	}
	return 0;
}
