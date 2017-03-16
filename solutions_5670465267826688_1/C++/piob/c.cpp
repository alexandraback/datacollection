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

bool neg[][4] = {
	{0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 1}
};

struct quat{
	bool neg; int i;
	quat() : neg(0), i(0) {}
	quat(bool n, int j) : neg(n), i(j) {}
	quat(char c) : neg(0), i(c-'h') {}
};

quat operator*(quat a, quat b){
	return quat(a.neg ^ b.neg ^ neg[a.i][b.i], a.i ^ b.i);
}

bool operator==(quat a, quat b){
	return a.neg == b.neg && a.i == b.i;
}

int n;
char buff[23*10000+3];

void read(){
	scanf("%d", &n);
	LL x;
	scanf("%lld", &x);
	x = min(x, (LL)(16+x%4));
	scanf("%s", buff);
	FWD(i,1,(int)x) memcpy(buff+i*n, buff, n);
	n *= (int)x;
}

bool gotill(quat r, int &i){
	quat p;
	while(i < n){
		p = p * quat(buff[i]);
		++i;
		if(p == r) return 1;
	}
	return 0;
}

bool gotillend(quat r, int &i){
	quat p;
	while(i < n){
		p = p * quat(buff[i]);
		++i;
	}
	return p == r;
}

bool solve(){
	int i = 0;
	if(!gotill(quat('i'), i)) return 0;
	if(!gotill(quat('j'), i)) return 0;
	return gotillend(quat('k'), i);
}

bool brut(){
	quat a;
	FWD(i,0,n) a = a * quat(buff[i]);
	if(!(a == quat(1,0))) return 0;
	quat b;
	FWD(i,0,n){
		b = b * quat(buff[i]);
		if(b == quat(0,1)){
			quat c;
			FWD(j,i+1,n){
				c = c * quat(buff[j]);
				if(c == quat(0,2)){
					quat d;
					FWD(k,j+1,n)
						d = d * quat(buff[k]);
					if(d == quat(0,3))
						return 1;
				}
			}
		}
	}
	return 0;
}

int main(){
	int z; scanf("%d", &z);
	FWD(c,1,z+1){
		read();
		assert(solve() == brut());
		printf("Case #%d: %s\n", c, solve()?"YES":"NO");
	}
	return 0;
}
