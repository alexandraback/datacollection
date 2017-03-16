#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long int64;

int number_of_tests;
int test_number;

#define MAX 12

int j, p, s, k;

void read() {
	scanf("%d %d %d %d", &j, &p, &s, &k);
}

struct Triple {
	int a, b, c;
	Triple(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	bool operator<(const Triple &t) const {
		if (a != t.a) return a < t.a;
		if (b != t.b) return b < t.b;
		return c < t.c;
	}
};

struct Node {
	vector <vector <int>> q12;
	vector <vector <int>> q23;
	vector <vector <int>> q13;
	
	Node() {
		q12.resize(10);
		q23.resize(10);
		q13.resize(10);
		fi(0, 9) {
			q12[i].resize(10);
			q23[i].resize(10);
			q13[i].resize(10);
		}
	}

	bool operator<(const Node &x) const {
		if (q12 != x.q12) return q12 < x.q12;
		if (q23 != x.q23) return q23 < x.q23;
		return q13 < x.q13;
	}
};

map <Node, int> h;
vector <Triple> cur, ans;
set <Triple> u;

int q12[MAX][MAX];
int q23[MAX][MAX];
int q13[MAX][MAX];

Node to_node() {
	Node node;
	fi(1, 10) {
		fj(1, 10) {
			node.q12[i - 1][j - 1] = q12[i][j];
			node.q23[i - 1][j - 1] = q23[i][j];
			node.q13[i - 1][j - 1] = q13[i][j];
		}
	}
	return node;
}

void fun(Triple t, int d) {
	if (cur.size() > ans.size()) {
		ans = cur;
	}
	int q = 0;
	fi(1, j) {
		fj(1, p) {
			fo(1, s) {
				if (Triple(i, j, o) < t) continue;
				q++;
			}
		}
	}

	if (SIZE(cur) + q <= SIZE(ans)) {
		return;
	}

	fi(1, j) {
		fj(1, p) {
			fo(1, s) {
				if (Triple(i, j, o) < t) continue;
				if (u.find(Triple(i, j, o)) == u.end()) {
					u.insert(Triple(i, j, o));
					q12[i][j]++;
					q13[i][o]++;
					q23[j][o]++;
					//map <Node, int>::iterator it = h.find(to_node());
					//if ((it == h.end() || it->second < d) && q12[i][j] <= k && q13[i][o] <= k && q23[j][o] <= k) {
					if (q12[i][j] <= k && q13[i][o] <= k && q23[j][o] <= k) {
						//h[to_node()] = d + 1;
						cur.push_back(Triple(i, j, o));
						fun(Triple(i, j, o), d + 1);
						cur.pop_back();
					}
					q12[i][j]--;
					q13[i][o]--;
					q23[j][o]--;
					u.erase(Triple(i, j, o));
				}
			}
		}
	}
}

void solve() {
	h.clear();
	u.clear();
	ans.clear();
	fun(Triple(0, 0, 0), 0);
	printf("%d\n", SIZE(ans));
	fi(0, SIZE(ans) - 1) {
		printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%d", &number_of_tests);
	for (test_number = 1; test_number <= number_of_tests; test_number++) {
		read();
		printf("Case #%d: ", test_number);
		solve();
		fflush(stdout);
	}
	return 0;
}
