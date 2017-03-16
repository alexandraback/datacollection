#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 10240
int n,a[N];
LL rep;

#define I 2
#define J 3
#define K 4
char*let = "?1ijk";

string print(int x) {
	string r(2,let[abs(x)]);
	r[0] = x<0?'-':' ';
	return r;
}

int read(char c) { return strchr(let,c)-let; }

int mul(int x, int y)
{
	int r = 1;
	if (x<0) r=-r,x=-x;
	if (y<0) r=-r,y=-y;
	if (x==1) return r*y;
	if (y==1) return r*x;
	if (x==y) return -r;
	r *= I+J+K-x-y;
	if ((x-I+1)%3 != (y-I)) r=-r;
	return r;
}

int lookfor(int val)
{
	int pos = 0;
	int x = 1;
	REP(ii,min(4LL,rep)) {
		REP(jj,n) {
			x = mul(x,a[jj]);
			++pos;
			if (x==val) return pos;
		}
	}
	return -1;
}

int lookfor2(int val)
{
	int pos = 0;
	int x = 1;
	REP(ii,min(4LL,rep)) {
		REPD(jj,n) {
			x = mul(a[jj],x);
			++pos;
			if (x==val) return pos;
		}
	}
	return -1;
}

bool solve() {
	int pass = 1;
	REP(i,n) pass = mul(pass,a[i]);
	int total = 1;
	REP(i,rep%4) total=mul(total,pass);
	if (total != mul(I,mul(J,K))) return false;
	int mn1 = lookfor(I);
	int mn2 = lookfor2(K);
	fprintf(stderr, "== %d %d\n", mn1, mn2);
	if (mn1!=-1 && mn2!=-1 && mn1+mn2 < n*rep){
		int x=1,y=1,z=1;
		REP(i,mn1) x=mul(x,a[i]);
		for (int i = mn1; i < n-mn2; ++i) y=mul(y,a[i]);
		REP(i,mn2) z=mul(z,a[n-mn2+i]);
		fprintf(stderr,"%s%s%s\n",print(x).data(),print(y).data(),print(z).data());
		return true;
	}
	return false;
}

bool stupid() {
	int x = 1;
	int look = I;
	REP(ii,rep) REP(i,n)
	{
		x = mul(x,a[i]);
		if (x==look) {
			if (look == I) look = J;
			else if (look == J) look = -123;
			else fprintf(stderr,"WTF\n");
			x=1;
		}
	}
	return look==-123 && x==K;
}

int main(int argc, char **argv)
{
	//FOR(i,1,4) FOR(j,1,4) printf("%s\t",print(mul(i,j)).data()); printf("\n");
	FOR(i,1,4) FOR(j,1,4) {
		int t=mul(i,j);
		assert(t==mul(-i,-j));
		assert(-t==mul(i,-j));
		assert(-t==mul(-i,j));
	}

	string FN = "C-large";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d%lld",&n,&rep);
		REP(i,n) {
			char c;
			do c=getc(stdin); while(!isalpha(c));
			a[i] = read(c);
		}
		printf("%s\n",solve()?"YES":"NO");
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}