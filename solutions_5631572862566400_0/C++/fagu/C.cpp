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


int N;
int f[2000];

int t;
int tim[2000];
bool instack[2000];
int predist[2000];
int term[2000];
int best[2000];
int maxcycle;

void visit(int i) {
	if (tim[i] != -1) {
		if (instack[i])
			setmax(maxcycle, t-tim[i]);
		return;
	}
	tim[i] = t;
	t++;
	instack[i] = true;
	visit(f[i]);
	instack[i] = false;
	if (predist[f[i]]) {
		predist[i] = predist[f[i]]+1;
		term[i] = term[f[i]];
	}
	if (f[f[i]] == i) {
		term[i] = i;
		predist[i] = 1;
	}
}

void docase() {
	scanf("%d", &N);
	REP(i,0,N) {
		scanf("%d", f+i);
		f[i]--;
	}
	REP(i,0,N) {
		tim[i] = -1;
		instack[i] = false;
		predist[i] = 0;
		best[i] = -1;
	}
	t = 0;
	maxcycle = 0;
	REP(i,0,N)
		visit(i);
	fprintf(stderr, "max cycle = %d\n", maxcycle);
	REP(i,0,N) {
		if (predist[i])
			setmax(best[term[i]], predist[i]);
	}
	int su = 0;
	REP(a,0,N) {
		int b = f[a];
		if (a < b && f[b] == a) {
// 			printf("suat
			su += best[a]+best[b];
		}
	}
	fprintf(stderr, "su = %d\n", su);
	printf("%d\n", max(maxcycle, su));
}

int main() {
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
