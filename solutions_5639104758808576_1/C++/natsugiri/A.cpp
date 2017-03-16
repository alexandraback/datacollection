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

int X;
char S[11111];
int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	scanf("%d%s", &X, S);
	int ans = 0, cnt = 0;
	REP (i, X+1) {
	    int c = S[i] - '0';
	    if (cnt < i) {
		ans += i-cnt;
		cnt += i-cnt;
	    }
	    cnt += c;
	}
	printf("Case #%d: ", tc);
	printf("%d\n", ans);
    }
    return 0;
}
