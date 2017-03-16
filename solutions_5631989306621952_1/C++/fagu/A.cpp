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

char line[5000];
char res[5000];

void docase() {
	scanf("%s ", line);
	int N = strlen(line);
	res[N] = 0;
	int a = 0, b = N-1, t = N;
	while(t) {
		pair<char,int> ma(0, -1);
		REP(i,0,t)
			setmax(ma, make_pair(line[i], i));
		for (int i = t-1; i > ma.second; i--) {
			res[b] = line[i];
			b--;
		}
		res[a] = line[ma.second];
		a++;
		t = ma.second;
	}
	printf("%s\n", res);
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
