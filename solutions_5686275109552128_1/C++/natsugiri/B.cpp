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

int D, P[1111];
int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	scanf("%d", &D);
	REP (i, D) scanf("%d", P+i);
	int ans = 1e9;
	for (int p=1; p<=1000; p++) {
	    int tmp = p;
	    REP (i, D) tmp += (P[i]-1)/p;
	    amin(ans, tmp);
	}
	
	printf("Case #%d: ", tc);
	printf("%d\n", ans);
    }
    return 0;
}
