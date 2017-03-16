#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define mp make_pair
#define st first
#define nd second
#define FOR(i,n) for(int i=0;i<(n);i++)
#define FORO(i,n) for(int i=1;i<=(n);i++)
#define FORS(i,a,n) for(int i=(a);i<(n);i++)
#define FORB(i,a,n) for(int i=(a);i>=(n);i--)
#define FORE(i,v) for(typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define INRANGE(a,b,c,d) ((a)>=0&&(b)>=0&&(a)<(c)&&(b)<(d))
#define pf printf
typedef long long ll;
using namespace std;
typedef pair<ll, int> pli;
typedef pair<pli, pli> state;

int N, M;
pli A[101], B[101];
map<state, ll> Sols;

ll maxmatch(state s) {
	int ai = s.st.nd, bi = s.nd.nd;
	if (ai == N || bi == M)
		return 0;
	if (Sols.count(s))
		return Sols[s];
	if (A[ai].nd == B[bi].nd) { // types match
		//printf("tm\n");
		//printf("[%lld;%d] [%lld;%d] -> ", s.st.st, s.st.nd, s.nd.st, s.nd.nd);
		ll rem = min(s.st.st, s.nd.st);
		state ns = state(pli(s.st.st-rem, ai), pli(s.nd.st-rem, bi));
		if (ns.st.st == 0) ns.st.nd++, ns.st.st = A[ai+1].st;
		if (ns.nd.st == 0) ns.nd.nd++, ns.nd.st = B[bi+1].st;
		//printf("[%lld;%d] [%lld;%d]\n", ns.st.st, ns.st.nd, ns.nd.st, ns.nd.nd);
		ll ans = rem + maxmatch(ns);
		return Sols[s] = ans;
	}
	else {
		state s1 = state(pli(A[s.st.nd+1].st, s.st.nd+1), s.nd);
		state s2 = state(s.st, pli(B[s.nd.nd+1].st, s.nd.nd+1));
		return Sols[s] = max(maxmatch(s1), maxmatch(s2));
	}
}

void testcase() {
	scanf("%d%d", &N, &M);
	FOR(i, N)
		scanf("%lld%d", &A[i].st, &A[i].nd);
	FOR(i, M)
		scanf("%lld%d", &B[i].st, &B[i].nd);
	Sols.clear();
	printf("%lld", maxmatch(state(pli(A[0].st, 0), pli(B[0].st, 0))));
	/*FORE(q, Sols) {
		state s = q->st;
		printf("[%lld;%d] [%lld;%d]  == %lld\n", s.st.st, s.st.nd, s.nd.st, s.nd.nd, q->nd);
	}*/
}

int main() {
	//freopen(".in", "r", stdin); freopen(".out", "w", stdout);
	int tc;
	scanf("%d", &tc);
	FORO(i, tc) {
		fprintf(stderr, "Case %d\n", i);
		printf("Case #%d: ", i);
		testcase();
		printf("\n");
	}
}


