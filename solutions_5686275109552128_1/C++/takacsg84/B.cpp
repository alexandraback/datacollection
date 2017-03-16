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

int test(int top, const map<int, int> &Q) {
	int special = 0;
	for (const auto& kvp : Q)
		if (kvp.first > top)
			special += (((kvp.first + top - 1) / top) - 1) * kvp.second;
	// fprintf(stderr, "With top %i special is %i\n", top, special);
	return special + top;
}

void dostuff() {
	int D, result = 0, top = 0;
	scanf("%i", &D);
	map<int, int> Q;
	REP(i, D) {
		int aux;
		scanf("%i", &aux);
		top = max(top, aux), Q[aux]++;
	}
	result = top;
	RREP(i, top) result = min(result, test(i + 1, Q));
	printf("%i\n", result);
}

int main() {
	int T;
	scanf("%i", &T);
	REP(t, T) printf("Case #%i: ", t + 1), dostuff();
}