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

const long long MIL = 1000*1000*1000;

int n;
char A[23];
char B[23];

long long eq[23], mx[23], mi[23];
int eqa[23], eqb[23], eqt[23];
int mxa[23], mxb[23], mxt[23];
int mia[23], mib[23], mit[23];

void check(int i, int a, int b, long long d, int t){
	if(abs(eq[i]) > abs(d)){
		eq[i] = d;
		eqa[i] = a;
		eqb[i] = b;
		eqt[i] = t;
	}
	if(mx[i] < d){
		mx[i] = d;
		mxa[i] = a;
		mxb[i] = b;
		mxt[i] = t;
	}
	if(mi[i] > d){
		mi[i] = d;
		mia[i] = a;
		mib[i] = b;
		mit[i] = t;
	}
}

void solve(){
	scanf("%s %s", A, B);
	//printf("%s %s\n", A, B);
	n = strlen(A);
	eq[n] = mx[n] = mi[n] = 0;
	long long p10 = 1;
	BCK(i,n-1,-1){
		eq[i] = mi[i] = 4*MIL*MIL;
		mx[i] = -4*MIL*MIL;
		FWD(a,0,10)
			if(A[i] == a + '0' || A[i] == '?')
				FWD(b,0,10)
					if(B[i] == b + '0' || B[i] == '?'){
						check(i, a, b, (a-b)*p10 + eq[i+1], 0);
						check(i, a, b, (a-b)*p10 + mx[i+1], 1);
						check(i, a, b, (a-b)*p10 + mi[i+1], 2);
					}
		//printf("%d(%d %d) %d(%d %d) %d(%d %d)\n", mx[i], mxa[i], mxb[i], eq[i], eqa[i], eqb[i],mi[i], mia[i], mib[i]);
		p10 *= 10;
	}
	int t = 0;
	FWD(i,0,n){
		if(t == 0){
			A[i] = eqa[i] + '0';
			B[i] = eqb[i] + '0';
			t = eqt[i];
		}else if(t == 1){
			A[i] = mxa[i] + '0';
			B[i] = mxb[i] + '0';
			t = mxt[i];
		}else if(t == 2){
			A[i] = mia[i] + '0';
			B[i] = mib[i] + '0';
			t = mit[i];
		}
	}
	printf("%s %s\n", A, B);
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
