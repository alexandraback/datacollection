#include <bits/stdc++.h>
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define FOR(x,m,n) for(int x=(int)m;x<(int)(n);x++)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))

using namespace std;
typedef long long LL;

char dot(int a, int b) {
	// assert(b != 1 && b != -1);
	if (a == 1 || a == -1 || b == 1 || b == -1) return a * b;
	bool positive = ((a > 0 && b > 0) || (a < 0 && b < 0));
	a = abs(a), b = abs(b);
	int result = 0;
	if (a == 'i') {
		if (b == 'i') result = -1;
		if (b == 'j') result = 'k';
		if (b == 'k') result = 'j', positive = !positive;
	}
	if (a == 'j') {
		if (b == 'i') result = 'k', positive = !positive;
		if (b == 'j') result = -1;
		if (b == 'k') result = 'i';
	}
	if (a == 'k') {
		if (b == 'i') result = 'j';
		if (b == 'j') result = 'i', positive = !positive;
		if (b == 'k') result = -1;
	}
	return positive ? result : -result;
}

void dostuff() {
	int L, X, k = 0;
	scanf("%i%i", &L, &X);
	string s, target = "ijk";
	cin >> s;
	char state;
	state = 1;

	REP(i, min(60000, L * X)) {
		state = dot(state, s[i % L]);
		if (state == target[k] && k < 2) ++k, state = 1;
	}
	printf("%s\n", (state == 'k' && k == 2) ? "YES" : "NO");
}

int main() {
	int T;
	scanf("%i", &T);
	REP(t, T) printf("Case #%i: ", t + 1), dostuff();
}