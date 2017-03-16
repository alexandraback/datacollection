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

int n;
bool d[10];

void solve(){
	if(n == 0){
		printf("INSOMNIA\n");
		return;
	}
	FWD(i,0,10) d[i] = 0;
	int64 m = n;
	for(;;){
		int64 c = m;
		while(c){
			d[c%10] = 1;
			c /= 10;
		}
		bool ok = 1;
		FWD(i,0,10) if(!d[i]) ok = 0;
		if(ok) break;
		m += n;
	}
	printf("%lld\n", m);
}

int main(){
	int zzz;
	scanf("%d", &zzz);
	FWD(zz,1,zzz+1){
		scanf("%d", &n);
		printf("Case #%d: ", zz);
		solve();
	}
	return 0;
}
