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
const LL MAXN = 1000005;
map<LL, LL> memo;

LL flip(LL a) {
	LL result = 0;
	while (a) result = result * 10 + a % 10, a /= 10;
	return result;
}

LL firstDigis(LL a) {
	while (a > 10)a %= 10;
	return a;
}

int numDigits(LL a) {
	int result = 0;
	while (a)a /= 10, result++;
	return result;
}

LL pow10(int p) {
	LL result = 1;
	while (--p)result *= 10;
	return result;
}

LL calc(LL x) {
	if (x < 10)return x;
	if (!memo.count(x)) {
		int p10 = numDigits(x);
		//no 1
		LL aux = pow10(p10) - 1;
		LL result = x - aux + calc(aux);
		int secondHalf = pow10((p10)  / 2 + 1);
		//flip from bot
		LL lower = x - (x % secondHalf) + 1;
		while (lower > x)lower -= secondHalf;
		// fprintf(stderr, "For %lli lower is %lli\n", x, lower);
		LL beforeflip = x - lower + 1;
		lower = flip(lower);
		if (aux <= lower) {
			// fprintf(stderr, "Cost to %lli: %lli\n", lower, beforeflip);
			// fprintf(stderr, "\tconsidering %lli + calc(%lli)\n", beforeflip + lower - aux, aux);
			result = min(result, beforeflip + lower - aux + calc(aux));
		} else result = min(result, beforeflip + calc(aux));
		memo[x] = result;
	}
	return memo[x];
}

LL DP[MAXN];
void prepare() {
	queue<int> Q;
	mem1(DP);
	DP[1] = 1;
	Q.push(1);
	while (Q.size()) {
		int next = Q.front();
		Q.pop();
		if (next + 1 < MAXN && DP[next + 1] < 0) Q.push(next + 1), DP[next + 1] = DP[next] + 1;
		int flip_next = flip(next);
		if (flip_next < MAXN && DP[flip_next] < 0) Q.push(flip_next), DP[flip_next] = DP[next] + 1;
	}
}

void dostuff() {
	LL N;
	scanf("%lli", &N);
	//if (calc(N) != DP[N]) fprintf(stderr, "%lli\n", N);
	printf("%lli\n", calc(N));
}

int main() {
	int T;
	scanf("%i", &T);
	REP(t, T) printf("Case #%i: ", t + 1), dostuff();
}