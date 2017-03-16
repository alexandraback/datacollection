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

int k, n, m;

bool every(){
	if(n < m) swap(n, m);
	if(k > 6) return 0;
	if(n*m%k) return 0;
	if(k < 3) return 1;
	if(k == 3) return m > 1;
	if(k == 4){
		if(m < 3) return 0;
		if(n < 4) return 0;
		return 1;
	}
	assert(false);
	return 0;
}

int main(){
	int z; scanf("%d", &z);
	FWD(c,1,z+1){
		scanf("%d %d %d", &k, &n, &m);
		printf("Case #%d: %s\n", c, every()?"GABRIEL":"RICHARD");
	}
	return 0;
}
