#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,n)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e4 + 5;

int l;
ll x;
bool bylo[nax];
char s[nax];
int m[5][5], numer[300];

int mnoz(int a, int b) {
	int razy = 1;
	if (a < 0) {
		a = -a;
		razy *= -1;
	}
	
	if (b < 0) {
		b = -b;
		razy *= -1;
	}
	
	return razy*m[a][b];
}

int pot(int a, ll b) {
	int res = 1;
	while (b) {
		if (b&1)
			res = mnoz(res,a);
		a = mnoz(a,a);
		b /= 2;
	}
	return res;
}

int kiedy(int val, bool kupa = true) {
	FOR(i,0,8) bylo[i] = false;
	
	int res = 1;
	int dl = 0;
	while (!bylo[res+4]) {	
		bylo[res+4] = true;
		REP(i,l) {
			++dl;
			//printf("%d %d\n",res,numer[(int)s[i]]);
			if (kupa)
				res = mnoz(res, numer[(int)s[i]]);
			else
				res = mnoz(numer[(int)s[i]], res);
			
			//printf("%d\n",res);
			if (res == val)
				return dl;
		}
	}
	return -1;
}

void solve(int g) {
	scanf("%d%lld",&l,&x);
	scanf(" %s",s);
	
	int res = 1;
	REP(i,l)
		res = mnoz(res, numer[(int)s[i]]);
		
	if (pot(res, x) != -1) {
		puts("NO");
		return;
	}
	
	int le = kiedy(2);
	reverse(s,s+l);
	int pr = kiedy(4,false);
	
	/*if (g == 43) {
		reverse(s,s+l);
		printf("%d %lld\n%s\n",l,x,s);
		printf("%d %d\n",le,pr);
	}*/
		
	
	if (le == -1 || pr == -1 || ll(le + pr) > x*l) 
		puts("NO");
	else
		puts("YES");
}

void init() {
	numer['i'] = 2;
	numer['j'] = 3;
	numer['k'] = 4;
	m[1][1] = 1;
	m[1][2] = 2;
	m[1][3] = 3;
	m[1][4] = 4;
	
	m[2][1] = 2;
	m[2][2] = -1;
	m[2][3] = 4;
	m[2][4] = -3;
	
	m[3][1] = 3;
	m[3][2] = -4;
	m[3][3] = -1;
	m[3][4] = 2;
	
	m[4][1] = 4;
	m[4][2] = 3;
	m[4][3] = -2;
	m[4][4] = -1;	
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	init();
	int test;
	scanf("%d",&test);
	FOR(g,1,test) {
		printf("Case #%d: ",g);
		solve(g);
	}
	return 0;
}
