#include <cstdio>
#include <cstdlib>
#include <list>
#include <queue>
#include <set>
using namespace std;

struct E {
	int d, c;
	const bool operator<(const E& e) const {
		return this->c > e.c;
	}
};

typedef list<int> ilist;
typedef priority_queue<E> pqueue;
typedef set<int> iset;

ilist l[52];
iset v;
ilist r;
int c[52];

void nav(int d) {
	pqueue pq;
	E e;
	if (v.find(d) != v.end()) {
		return;
	}
	v.insert(d);
	r.push_back(c[d]);
	for (ilist::iterator jt = l[d].begin(); jt != l[d].end(); jt++) {
		if (v.find(*jt) == v.end()) {
			e.d = *jt;
			e.c = c[*jt];
			pq.push(e);
		}
	}
	while (!pq.empty()) {
		e = pq.top();
		pq.pop();
		nav(e.d);
	}
}

int main() {
	int d;
	int t, T;
	int n, m;
	int a, b;
	pqueue pq;
	E e;
	int i;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		r.clear();
		v.clear();
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) {
			scanf("%d", &c[i]);
			l[i].clear();
		}
		e.c = c[1];
		e.d = 1;
		for (i = 1; i <= n; i++) {
			if (c[i] < e.c) {
				e.c = c[i];
				e.d = i;
			}
		}
		for (i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			l[a].push_back(b);
			l[b].push_back(a);
		}
		nav(e.d);
		printf("Case #%d: ", t);
		for (ilist::iterator it = r.begin(); it != r.end(); it++) {
			printf("%d", *it);
		}
		puts("");
	}
	return EXIT_SUCCESS;
}
