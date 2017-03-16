#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}

int N, J;

void docase() {
	scanf("%d%d", &N, &J);
	int cnt = 0;
	REP(einsen,1,N/2+1) {
		if (cnt == J)
			break;
		int nullen = N/2-einsen;
		vector<int> v1(N/2-1,0);
		REP(i,nullen,N/2-1)
			v1[i] = 1;
		do {
			vector<int> v2(N/2-1,0);
			REP(i,nullen,N/2-1)
				v2[i] = 1;
			if (cnt == J)
				break;
			do {
				if (cnt == J)
					break;
				vector<int> res(N);
				res[0] = res[N-1] = 1;
				REP(i,0,N/2-1) {
					res[2*i+1] = v1[i];
					res[2*i+2] = v2[i];
				}
				int chk = 0;
				REP(i,0,N)
					chk = res[i]-chk;
				assert(chk == 0);
				REP(i,0,N)
					printf("%d", res[i]);
				REP(b,2,11)
					printf(" %d", b+1);
				printf("\n");
				cnt++;
			} while(next_permutation(v2.begin(), v2.end()) && cnt < J);
		} while(next_permutation(v1.begin(), v1.end()) && cnt < J);
	}
	assert(cnt == J);
}

int main() {
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d:\n", test+1);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
