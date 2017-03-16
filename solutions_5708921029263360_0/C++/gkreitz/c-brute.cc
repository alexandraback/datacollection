#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;
#define dprintf debug && printf
#define F(x,y) for(typeof((y).begin()) x = (y).begin(); x != (y).end(); ++x) 
#define CHECKREAD(x, ...) if(scanf(__VA_ARGS__) != x) { fprintf(stderr, "Failed to read on %s, %d\n", __FILE__, __LINE__); exit(1); }

typedef pair<int, int> pii;



const enum {SIMPLE, FOR, WHILE} mode = FOR;
bool debug = false;

void init() {
}

vector<int> ans;

int next_c(int J, int P, int S, int j, int p, int s) {
	++s;
	if(s == S) {
		s = 0;
		++p;
		if(p == P) {
			p = 0;
			++j;
			if(j == J) {
				return -1;
			}
		}
	}
	return 10000 * j + 100 * p + s;
}

void rec(const int J, const int P, const int S, const int K, const int c, map<pii, int> &seen, vector<int> &pick) {
	if (c == -1) {
		if(pick.size() > ans.size()) {
			dprintf("Updating ans to size %zu", pick.size());
			ans = pick;
		}
		return;
	}
	int j = c / 10000;
	int p = (c / 100) % 100;
	int s = c % 100;

	//dprintf("Looking at %d, %d, %d\n", j, p, s);

	int nextc = next_c(J, P, S, j, p, s);

	rec(J, P, S, K, nextc, seen, pick);


	if(seen[make_pair((j+1)*10000, (p+1) * 100)] < K && seen[make_pair((j+1)*10000, s+1)] < K && seen[make_pair((p+1)*100, s+1)] < K) {
		seen[make_pair((j+1)*10000, (p+1) * 100)]++;
	  	seen[make_pair((j+1)*10000, s+1)]++;
	  	seen[make_pair((p+1)*100, s+1)]++;
		pick.push_back(c);
		rec(J, P, S, K, nextc, seen, pick);
		pick.pop_back();
		seen[make_pair((j+1)*10000, (p+1) * 100)]--;
	  	seen[make_pair((j+1)*10000, s+1)]--;
	  	seen[make_pair((p+1)*100, s+1)]--;
	}
}

bool solve(int PP) {
	printf("Case #%d: ", PP+1);
	int J, P, S, K;
	map<pii, int> seen;
	vector<int> pick;
	ans = vector<int> ();
	scanf("%d%d%d%d", &J, &P, &S, &K);
	int c = 0;
	while(c != -1) {
		dprintf("%d\n", c);
		int j = c / 10000;
		int p = (c / 100) % 100;
		int s = c % 100;
		c = next_c(J, P, S, j,p,s);
	}
	rec(J, P, S, K, 0, seen, pick);
	printf("%lu\n", ans.size());
	for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
		const int c = *it;
		int j = c / 10000;
		int p = (c / 100) % 100;
		int s = c % 100;
		printf("%d %d %d\n", j+1, p+1, s+1);
	}
	return true;
}

int main() {
  init();
  int n = mode == SIMPLE ? 1 : 1<<30;
  if (mode == FOR) scanf("%d", &n);
  for (int i = 0; i < n && solve(i); ++i);
  return 0;
}
