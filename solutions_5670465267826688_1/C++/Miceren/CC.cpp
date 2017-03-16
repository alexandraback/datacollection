#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const long long INF = 1e15;
const int N = 18 * 1e5 + 5;

int n;
long long times;
char buffer[N];

struct Node {
	int sign;
	char c;
	Node(string s) {
		if (s.length() == 2) {
			sign = -1;
			c = s[1];
		} else {
			sign = 1;
			c = s[0];
		}
	}

	void show() {
		printf("sign = %d\n", sign);
		printf("c = %c\n", c);

	}

	friend inline bool operator ==(const Node &a, const Node &b) {
		return a.sign == b.sign && a.c == b.c;
	}

	friend inline Node operator *(const Node &a, char x) {
		string tmp;
		tmp += x;
		return a * Node(tmp);
	}

	friend inline Node operator *(const Node &a, const Node &b) {
		Node c = Node("1");
		c.sign = a.sign * b.sign;
		if (a.c == '1') {
			c.c = b.c;
		} else if (b.c == '1') {
			c.c = a.c;
		} else if (a.c == 'i') {
			if (b.c == 'i') {
				c.sign *= -1;
				c.c = '1';
			} else if (b.c == 'j') {
				c.c = 'k';
			} else if (b.c == 'k') {
				c.sign *= -1;
				c.c = 'j';
			}
		} else if (a.c == 'j') {
			if (b.c == 'i') {
				c.sign *= -1;
				c.c = 'k';
			} else if (b.c == 'j') {
				c.sign *= -1;
				c.c = '1';
			} else if (b.c == 'k') {
				c.c = 'i';
			}
		} else {
			if (b.c == 'i') {
				c.c = 'j';
			} else if (b.c == 'j') {
				c.sign *= -1;
				c.c = 'i';
			} else if (b.c == 'k') {
				c.sign *= -1;
				c.c = '1';
			}
		}
		return c;
	}
};

int go(int start, Node target) {
	if (start < 0 || start == n) {
		return start = -1;
	}
	Node base = Node("1");
	for (; start < n; start++) {
		base = base * buffer[start];
		//base.show();
		if (base == target) {
			return ++start;
		}
	}
	return start = -1;
}

int main() {
	int test;
	scanf("%d", &test);
	for (int testCount = 1; testCount <= test; testCount++) {
		cin >> n >> times;
		scanf("%s", buffer);
		if (times > 18) {
			long long remain = times - 18;
			times -= remain / 4 * 4;
		}

		int cnt = 0;
		for (int i = 0; i < times; i++) {
			for (int j = 0; j < n; j++) {
				buffer[cnt++] = buffer[j];
			}
		}
		n = cnt;
		buffer[n] = 0;
		//cout << "n = " << n << endl;
		//cout << buffer << " " << n << endl;
		int s = 0;
		s = go(s, Node("i"));
		//cout << s << endl;
		s = go(s, Node("j"));
		//cout << s << endl;
		s = go(s, Node("k"));
		//cout << s << endl;
		if (s >= 0) {
			Node tmp = Node("1");
			for (int i = s; i < n; i++) {
				tmp = tmp * buffer[i];
			}
			if (tmp == Node("1")) {
				s = n;
			}
		}
		printf("Case #%d: %s\n", testCount, s == n ? "YES" : "NO");
	}
	return 0;
}