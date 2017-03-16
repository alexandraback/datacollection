// #pragma comment(linker, "/STACK:10240000")

#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define Pow2(x) (1 << (x))
#define Contain(a, x) (((a) >> (x)) & 1)
#define Rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define Foru(i, a, b) for(int i = (a); i < (b); ++i)
#define Debug(x) (cerr << #x << " = " << (x) << endl)
#define Debug2(x, y) (cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl)

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

const int INF = 1000000000;
const double EPS = 1e-7;

template <class T> inline bool cMin(T &a, const T &b) {
	return (a > b) ? (a = b, true) : (false);
}

template <class T> inline bool cMax(T &a, const T &b) {
	return (a < b) ? (a = b, true) : (false);
}

const int MAX_NODE = 1033;

struct node {
	bool isEnd;
	node *fail, *next[26];
} base[MAX_NODE], *top = NULL, *root;
typedef node *tree;

tree newNode() {
	tree ret = top++;
	memset(ret, 0, sizeof(node));
	return ret;
}

void insertTrie(char *s) {
	tree t = root;
	for ( ; *s; ++s) {
		int d = *s - 'A';
//		printf("d = %d\n", d);
		if (!t->next[d])
			t->next[d] = newNode();
		t = t->next[d];
	}
	t->isEnd = true;
}

void construct() {
	static tree Q[MAX_NODE];
	int head = 0, tail = 0;
	for (root->fail = root, Q[++tail] = root; head < tail; ) {
		tree x = Q[++head];
		Rep(d, 0, 25)
			if (!x->next[d])
				x->next[d] = (x == root) ? (root) : (x->fail->next[d]);
			else {
				x->next[d]->fail = (x == root) ? (root) : (x->fail->next[d]);
				Q[++tail] = x->next[d];
			}
	}
}

int K, L, S;
char keys[133], expect[133];

int dpMax[133][133];
double dpExpected[133][133][133];

void solve() {
	top = base;
	root = newNode();
	scanf("%d %d %d", &K, &L, &S);
	scanf("%s", keys);
	scanf("%s", expect + 1);
	insertTrie(expect + 1);
	construct();

	int totalNode = (int)(top - base);
//	printf("%d\n", totalNode);
	for (int n = 0; n <= S; ++n)
		for (int k = 0; k <= totalNode; ++k)
			dpMax[n][k] = -1;
	dpMax[0][0] = 0;
	for (int n = 0; n < S; ++n)
		for (int k = 0; k < totalNode; ++k) {
			int v = dpMax[n][k];
			if (v == -1) continue;
			for (int d = 0; d < K; ++d) {
				int nextNode = base[k].next[keys[d] - 'A'] - base;
//				printf("k = %d, d = %d, nextNode = %d\n", k, keys[d] - 'A', nextNode);
				if (base[nextNode].isEnd)
					cMax(dpMax[n + 1][nextNode], v + 1);
				else
					cMax(dpMax[n + 1][nextNode], v);
			}
		}
	memset(dpExpected, 0, sizeof(dpExpected));
	dpExpected[0][0][0] = 1.0;
	for (int n = 0; n < S; ++n)
		for (int k = 0; k < totalNode; ++k)
			for (int p = 0; p <= S; ++p) {
				double v = dpExpected[n][k][p];
				if (v == 0.0)
					continue;
				for (int d = 0; d < K; ++d) {
					int nextNode = base[k].next[keys[d] - 'A'] - base;
					if (base[nextNode].isEnd)
						dpExpected[n + 1][nextNode][p + 1] += v / K;
					else
						dpExpected[n + 1][nextNode][p] += v / K;
				}
			}
	int globalMax = 0;
	for (int k = 0; k < totalNode; ++k)
		cMax(globalMax, dpMax[S][k]);
	double expected = 0.0;
	for (int k = 0; k < totalNode; ++k)
		for (int p = 0; p <= S; ++p)
			expected += dpExpected[S][k][p] * p;
//	printf("%d %.10f\n", globalMax, expected);
	printf("%.10f\n", globalMax - expected);
}

int main() {
	int T;
	scanf("%d", &T);
	Rep(Case, 1, T) {
		printf("Case #%d: ", Case);
		solve();
	}
	return 0;
}
