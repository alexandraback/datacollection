#include <deque>
#include <unordered_set>
#include <iostream>

using namespace std;
typedef long long lint;

struct Node {
	lint p;
	lint dist;
};
typedef deque<Node> Queue;
typedef unordered_set<lint> Set;

lint reverse(const lint nn) {
	lint rev = 0;
	lint n = nn;
	while (n > 0) {
		int d = n % 10;
		rev = 10 * rev + d;
		n = n / 10;
	}
	// cout << __func__ << ": " << nn << ", " << rev << endl;
	return rev;
}

lint lesser(const lint n) {
	lint p = n;
	int w = 0;
	while (p > 0) {
		++w;
		p /= 10;
	}

	lint res = 0;
	p = n;
	int i = 0;
	lint base = 1;
	while (p > 0) {
		int d = p % 10;
		p /= 10;
		int new_d = d;
		if (i < w / 2) {
			new_d = (i==0) ? 1 : 0;
		}
		res += base* new_d;
		base *= 10;
		++i;
	}
	return res < n ? res : n;
}

bool reversable(const lint n) {
	return n % 10 > 0;
}

lint search(lint N) {
	lint n = N;
	lint len = 0;

	while (n > 0) {
		lint p = lesser(n);
		len += (n-p);
		//cout << n << ", " << p << ", " << endl;
		bool dec = false;
		while (!reversable(p) || reverse(p) == p) {
			dec = true;
			--p;
			++len;
			if (p == 0) break;
		}
		if (!dec) {
			if (p > 0) ++len;
			n = reverse(p);
		} else {
			n = p;
		}
	}
	return len;
}


int main(int argc, char *argv[]) {
	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		lint N;
		cin >> N;

		auto res = search(N);
		cout << "Case #" << (t+1) << ": " << res << endl;
	}
	return 0;
}
