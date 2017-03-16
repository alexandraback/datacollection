#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int A, B, K;
struct Node {
	int num;
	int free; // free bits
	Node(int a, int b) {
		num = a; free = b;
	}

	string tos() {
		static char buf[100];
		int t = num;
		for (int i = 31; i >= 0; i --) {
			if (32 - i <= free) buf[i] = 'x';
			else buf[i] = '0' + t % 2;
			t /= 2;
		}
		return buf;
	}
};

vector<Node> decomp(int n) {
	vector<Node> ret;
//	ret.push_back(Node(n, 0));

	while (n) {
		int i = 0;
		while ( (n & (1 << i)) == 0) {
			i ++;
		}
		ret.push_back(Node(n ^ (1<<i), i));
		n ^= (1<<i);
	}
	return ret;
}

long long f(Node _a, Node _b, Node _c) {
	string a = _a.tos();
	string b = _b.tos();
	string c = _c.tos();
	long long ret = 1;
	for (int i = 0; i < 32; i ++) {
		char p = a[i];
		char q = b[i];
		if (p > q) swap(p, q);  // 0 1 x
		char r = c[i];
		if (p != 'x' && q != 'x') {
			int x = p - '0', y = q - '0';
			if (r == 'x') ret *= 1;
			else if ( (x & y) != (r - '0') ) return 0;
		}
		else if (p == '0' && q == 'x') {
			if (r == '1') return 0;
			if (r == '0' || r == 'x') ret *= 2;
		}
		else if (p == '1' && q == 'x') {
			if (r == 'x') ret *= 2;
		}
		else if (p == 'x' && q == 'x') {
			if (r == 'x') ret *= 4;
			if (r == '1') ret *= 1;
			if (r == '0') ret *= 3;
		} else {
			printf("BUG\n");
		}
	}
//	printf("%s\n%s\n%s\n===%d===\n", a.c_str(), b.c_str(), c.c_str(), ret);
	return ret;
}

int main() {
	int tn;
	freopen("blg.in", "r", stdin);
	freopen("blg.out", "w", stdout);
	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ti ++) {
		scanf("%d%d%d", &A, &B, &K);
		vector<Node> p = decomp(A);
		vector<Node> q = decomp(B);
		vector<Node> r = decomp(K);
		long long ans = 0;
		for (int i = 0; i < p.size(); i ++)
			for (int j = 0; j < q.size(); j ++)
				for (int k = 0; k < r.size(); k ++) {
					ans += f(p[i], q[j], r[k]);
				}
		printf("Case #%d: %lld\n", ti + 1, ans);
//		break;
	}
	return 0;
}
