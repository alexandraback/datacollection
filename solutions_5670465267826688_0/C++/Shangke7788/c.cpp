#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 10101;
char s[MAX_N];
int l;
lint x;

struct Node {
	char c;
	int f;
	Node() {
	}
	Node(char c, int f = 1): c(c), f(f) {
	}
	Node operator * (const Node& o) {
		Node ans;
		ans.f = f * o.f;
		if (c == '1') {
			ans.c = o.c;
		} else if (o.c == '1') {
			ans.c = c;
		} else if (c == o.c) {
			ans.c = '1';
			ans.f *= -1;
		} else if (c == 'i') {
			if (o.c == 'j') {
				ans.c = 'k';
			} else {
				ans.c = 'j';
				ans.f *= -1;
			}
		} else if (c == 'j') {
			if (o.c == 'i') {
				ans.c = 'k';
				ans.f *= -1;
			} else {
				ans.c = 'i';
			}
		} else {
			if (o.c == 'i') {
				ans.c = 'j';
			} else {
				ans.c = 'i';
				ans.f *= -1;
			}
		}
		return ans;
	}
};

bool all(int b, int e) {
	for (int i = b; i <= e; i++) {
		if (s[i] != s[b]) {
			return false;
		}
	}
	return true;
}

bool judge() {
	for (int i = 0; i < l * x; i++) {
		s[i] = s[i % l];
	}
	s[l * x] = '\0';
	int n = strlen(s);
	int b = 0, e = n - 1, f = 1;
	while (s[b] != 'i' || f != 1) {
		Node x = Node(s[b]) * Node(s[b + 1]);
		s[++b] = x.c, f *= x.f;
		if (b == e - 1) {
			return false;
		}
	}
	while (s[e] != 'k' || f != 1) {
		Node x = Node(s[e - 1]) * Node(s[e]);
		s[--e] = x.c, f *= x.f;
		if (b == e - 1) {
			return false;
		}
	}
	Node cur = Node('1');
	for (int i = b + 1; i <= e - 1; i++) {
		cur = cur * Node(s[i]);
	}
	return cur.c == 'j' && cur.f == 1;
}

int main() {
#ifdef _SHANGKE_
	time_t _t1 = clock();
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d%lld%s", &l, &x, s);
		printf("Case #%d: %s\n", ca, judge() ? "YES" : "NO");
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
