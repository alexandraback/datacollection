#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>

using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) (int)(x).size()
#define SORT(x) sort((x).begin(),(x).end())
#define CLEAR(tab) memset(tab, 0, sizeof(tab))
#define REP(x, n) for(int x = 0; x < (n); x++)
#define FOR(x, b, e) for(int x = (b); x <= (e); x++)
#define FORD(x, b, e) for(int x = (b); x >= (e); x--)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define DEBUG(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

const int MAX_BUF_SIZE = 16384;
char BUFOR[MAX_BUF_SIZE];
int BUF_SIZE, BUF_POS;
char ZZZ;
#define GET(ZZZ){ZZZ='a';if(BUF_POS<BUF_SIZE)ZZZ=BUFOR[BUF_POS++];\
else if(!feof(stdin)){BUF_SIZE=fread(BUFOR,1,MAX_BUF_SIZE,stdin);\
ZZZ=BUFOR[0];BUF_POS=1;}}
#define GI(WW){do{GET(ZZZ);}while(!isdigit(ZZZ));WW=ZZZ-'0';\
while(1){GET(ZZZ);if(!isdigit(ZZZ))break;WW=WW*10+(ZZZ-'0');}}
#define GC(WW){do{GET(ZZZ);}while(!isalpha(ZZZ));WW=ZZZ;}

//FAST IO

typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MXN = 210;
const int C = 262144;
const int INF = 1000000001;
const double EPS = 0.00000001;

int te;
int s[MXN];
int n;
double res[MXN];
int sum;
int mniejsze;
int ileM;
int q;

inline double abso(double x) {
	if(x < 0)
		return -x;
	return x;
}

bool czyOdpada(double t) {
	mniejsze = 0;
	ileM = 0;
	FOR(j, 1, n)
		if(j != q && s[j] <= s[q] + (t / 100) * sum) {
			mniejsze += s[j];
			ileM++;
		}
	double zost = ileM * (s[q] + (t / 100) * sum) - mniejsze;
	//cout<<mniejsze<<" "<<ileM<<" "<<zost<<" "<<t<<" "<<sum * (100 - t)<<endl;
	if(zost <= sum * (100 - t) / 100 )
		return 1;
	//cout<<"ASD"<<endl;
	return 0;
}

void test() {
	sum = 0;
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", &s[i]);
		sum += s[i];
	}
	FOR(i, 1, n) {
		double L = 0, R = 100;
		double WYN = R;
		while( abso(L - R) > EPS) {
			double S = (L + R) / 2;
			q = i;
			if(czyOdpada(S) )
				L = S;
			else {
				R = S;
				if(WYN > S)
					WYN = S;
			}
		}

		res[i] = WYN;
	}

	printf("Case #%d: ", te);
	FOR(i, 1, n)
		printf("%.8lf ", res[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for(te = 1; te <= t; te++)
		test();
	return 0;
}
