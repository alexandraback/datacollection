#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

string s1, s2;
int n;

struct Node {
	long long a, b;
	Node() {}
	Node(long long a, long long b) : a(a), b(b) {}
};

Node dpf[19], dpg[19], dph[19];

long long absl(long long a) {
	return (a >= 0 ? a : -a);
}

Node betterf(Node n1, Node n2) {
	if (absl(n1.a - n1.b) <= absl(n2.a - n2.b))
		return n1;
	return n2;
}

Node betterg(Node n1, Node n2) {
	if (n1.b - n1.a >= n2.b - n2.a)
		return n1;
	return n2;
}

Node betterh(Node n1, Node n2) {
	if (n1.a - n1.b >= n2.a - n2.b)
		return n1;
	return n2;
}

void solve() {
	n = s1.size();
	dpf[n] = dpg[n] = dph[n] = Node(0, 0);
	long long base = 1;
	for (int pos = n - 1; pos >= 0; pos--) {
		int n1 = s1[pos], n2 = s2[pos];
		if (n1 != '?' && n2 != '?') {
			n1 -= '0';
			n2 -= '0';
			if (n1 == n2) {
				dpf[pos] = Node(n1 * base + dpf[pos + 1].a, n2 * base + dpf[pos + 1].b);
				dpg[pos] = Node(n1 * base + dpg[pos + 1].a, n2 * base + dpg[pos + 1].b);
				dph[pos] = Node(n1 * base + dph[pos + 1].a, n2 * base + dph[pos + 1].b);
			} else if (n1 < n2) {
				dpf[pos] = Node(n1 * base + dph[pos + 1].a, n2 * base + dph[pos + 1].b);
				dpg[pos] = Node(n1 * base + dpg[pos + 1].a, n2 * base + dpg[pos + 1].b);
				dph[pos] = Node(n1 * base + dph[pos + 1].a, n2 * base + dph[pos + 1].b);
			} else {
				dpf[pos] = Node(n1 * base + dpg[pos + 1].a, n2 * base + dpg[pos + 1].b);
				dpg[pos] = Node(n1 * base + dpg[pos + 1].a, n2 * base + dpg[pos + 1].b);
				dph[pos] = Node(n1 * base + dph[pos + 1].a, n2 * base + dph[pos + 1].b);
			}
		} else if (n1 != '?') {
			n1 -= '0';
			dpf[pos] = Node(n1 * base + dpf[pos + 1].a, n1 * base + dpf[pos + 1].b);
			dpg[pos] = Node(n1 * base + dpg[pos + 1].a, 9 * base + dpg[pos + 1].b);
			dph[pos] = Node(n1 * base + dph[pos + 1].a, 0 * base + dph[pos + 1].b);
			Node tmp;
			if (n1 > 0) {
				tmp = Node(n1 * base + dpg[pos + 1].a, (n1 - 1) * base + dpg[pos + 1].b);
				dpf[pos] = betterf(tmp, dpf[pos]);
			}
			if (n1 < 9) {
				tmp = Node(n1 * base + dph[pos + 1].a, (n1 + 1) * base + dph[pos + 1].b);
				dpf[pos] = betterf(dpf[pos], tmp);
			}
		} else if (n2 != '?') {
			n2 -= '0';
			dpf[pos] = Node(n2 * base + dpf[pos + 1].a, n2 * base + dpf[pos + 1].b);
			dpg[pos] = Node(0 * base + dpg[pos + 1].a, n2 * base + dpg[pos + 1].b);
			dph[pos] = Node(9 * base + dph[pos + 1].a, n2 * base + dph[pos + 1].b);
			Node tmp;
			if (n2 > 0) {
				tmp = Node((n2 - 1) * base + dph[pos + 1].a, n2 * base + dph[pos + 1].b);
				dpf[pos] = betterf(tmp, dpf[pos]);
			}
			if (n2 < 9) {
				tmp = Node((n2 + 1) * base + dpg[pos + 1].a, n2 * base + dpg[pos + 1].b);
				dpf[pos] = betterf(dpf[pos], tmp);
			}
		} else {
			dpf[pos] = Node(0 * base + dpf[pos + 1].a, 0 * base + dpf[pos + 1].b);
			dpg[pos] = Node(0 * base + dpg[pos + 1].a, 9 * base + dpg[pos + 1].b);
			dph[pos] = Node(9 * base + dph[pos + 1].a, 0 * base + dph[pos + 1].b);
			
			Node tmp;

			tmp = Node(0 * base + dph[pos + 1].a, 1 * base + dph[pos + 1].b);
			dpf[pos] = betterf(dpf[pos], tmp);

			tmp = Node(1 * base + dpg[pos + 1].a, 0 * base + dpg[pos + 1].b);
			dpf[pos] = betterf(dpf[pos], tmp);
		}
		//cout << dpf[pos].a << " " << dpf[pos].b << ", ";
		//cout << dpg[pos].a << " " << dpg[pos].b << ", ";
		//cout << dph[pos].a << " " << dph[pos].b << endl;
		base *= 10;
	}
	cout << setfill('0') << setw(n) << dpf[0].a << " ";
	cout << setfill('0') << setw(n) << dpf[0].b << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		cin >> s1 >> s2;
		solve();
	}
	return 0;
}
