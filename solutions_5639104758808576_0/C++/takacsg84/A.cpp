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

bool test(int sum, const vector<int> &cnt) {
	int idx = 0;
	while (idx <= sum && idx < cnt.size()) sum += cnt[idx], ++idx;
	return idx == cnt.size();
}

void dostuff() {
	int A, result = 0;
	char s[1005];
	scanf("%i%s", &A, s);
	vector<int> cnt(A + 1);
	REP(i, A + 1) cnt[i] = s[i] - '0';
	while (!test(result, cnt)) ++result;
	printf("%i\n", result);
}

int main() {
	int T;
	scanf("%i", &T);
	REP(t, T) printf("Case #%i: ", t + 1), dostuff();
}