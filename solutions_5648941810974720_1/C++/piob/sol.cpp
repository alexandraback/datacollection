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

string digits[] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
// Z              W      R        U       F       X      V        G
};

// Z0 W2 U4 F5 V7 G8 X6 R3

int cnt[256];
int n;
char buff[2010];
int res[10];

void solve(){
	scanf("%s", buff);
	n = strlen(buff);
	FWD(c,'A','Z'+1) cnt[c] = 0;
	FWD(i,0,n) cnt[buff[i]]++;
	res[0] = cnt['Z'];
	res[2] = cnt['W'];
	res[4] = cnt['U'];
	res[5] = cnt['F'] - res[4];
	res[7] = cnt['V'] - res[5];
	res[8] = cnt['G'];
	res[6] = cnt['X'];
	res[3] = cnt['R'] - res[0] - res[4];
	res[1] = cnt['O'] - res[0] - res[2] - res[4];
	res[9] = (cnt['N'] - res[1] - res[7]) / 2;
	FWD(i,0,10)
		FWD(r,0,res[i])
			printf("%c", '0'+i);
	printf("\n");
}

int main(){
	int zzz;
	scanf("%d", &zzz);
	FWD(zz,1,zzz+1){
		printf("Case #%d: ", zz);
		solve();
	}
	return 0;
}
