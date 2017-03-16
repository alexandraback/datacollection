#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int A[4][4] = {
    { 0, 1, 2, 3},
    { 1, 0, 3, 2},
    { 2, 3, 0, 1},
    { 3, 2, 1, 0},
};
int S[4][4] = {
    { 1, 1, 1, 1},
    { 1, -1, 1, -1},
    { 1, -1, -1, 1},
    { 1, 1, -1, -1},
};

typedef pair<int, int> PII;
PII operator*(const PII &x, const PII &y) {
    return PII(x.first * y.first * S[x.second][y.second], A[x.second][y.second]);
}
PII power(PII x, LL y) {
    PII r(1, 0);
    for (;y;y>>=1) {
	if (y&1) r=r*x;
	x=x*x;
    }
    return r;
}

int L;
LL X;
char E[10011];
const PII I(1, 1), J(1, 2), K(1, 3);

int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	scanf("%d%lld%s", &L, &X, E);

	int st = 0;
	PII x(1, 0), y;
	for (int i=0, j=0; i<min(320000LL, X*L); i++, j++) {
	    if (j == L) j = 0;

	    if (E[j] == 'i') x = x * I;
	    else if (E[j] == 'j') x = x * J;
	    else if (E[j] == 'k') x = x * K;

	    if (st == 0 && x == I) st++;
	    else if (st == 1 && x == K) st++;

	    if (i==L-1) y = x;
	}

	bool yes = (st == 2 && power(y, X) == PII(-1, 0));
	
	printf("Case #%d: ", tc);
	puts(yes?"YES":"NO");
	
    }
    return 0;
}
