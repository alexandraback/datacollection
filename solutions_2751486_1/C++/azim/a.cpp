#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define FI first
#define SE second

const int INF = 1000000001;
const double EPS = 10e-9;


const int MAXN = 1000010;
int a,b,n,k,zz,w;
bool t[MAXN];
LL wyn;
char h;


bool isConsonant(char x) {
	return !((x =='a') || (x =='e') || (x =='i') || (x =='o') || (x == 'u'));
}


int main() {

	scanf("%d", &zz);
	FOR(z,1,zz) {
		scanf("%c", &h); n=0;
		while(h!=32) {
			scanf("%c", &h);
			t[n++] = isConsonant(h);
		} n--;
		scanf("%d", &k);

		a=0; b=-1; w=0; wyn=0;

		while(b+1 < n) {
			b++;
			(t[b]) ? w++ : w=0;

			if(w==k) {
				wyn += (LL)((b-k+1)-a+1)*(LL)(n-b);
				a = b-k+2;
				w--;
			}
		}

		printf("Case #%d: %lld\n", z, wyn);
	}

  	return 0;
}
