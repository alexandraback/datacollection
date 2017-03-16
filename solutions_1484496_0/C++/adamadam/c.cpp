#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
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

const int MXN = 2000010;
const int C = 1048576;
const int INF = 1000000001;

int czy[MXN];
int set[MXN];

int te;
int n;
int a[30];
int sum[C + 10];
int t;
int setA, setB;

void test() {
	scanf("%d", &n);
	FOR(i, 1, n)
		scanf("%d", &a[i]);
	bool decy = 0;
	FOR(i, 1, C - 1) {
		int x = i;
		int o = x - (x & ~(x - 1) );
		int bit = x & ~(x - 1);
		int ile = 1;

		while(bit % 2 == 0) {
			ile++;
			bit /= 2;
		}

		sum[i] = a[ile] + sum[o];

		if(czy[sum[i]] == t) {
			decy = 1;

			setA = set[sum[i]];
			setB = i;
			break;
		}
		else {
			czy[sum[i]] = t;
			set[sum[i]] = i;
		}
	}

	printf("Case #%d:\n", t);

	if(decy) {
		FOR(i, 1, 20)
			if(setA & (1 << (i - 1) ) )
				printf("%d ", a[i]);
		printf("\n");
		FOR(i, 1, 20)
			if(setB & (1 << (i - 1) ) )
				printf("%d ", a[i]);
		printf("\n");
	}
	else
		printf("Impossible\n");
}

int main() {
	scanf("%d", &te);
	for(t = 1; t <= te; t++)
		test();
	return 0;
}
