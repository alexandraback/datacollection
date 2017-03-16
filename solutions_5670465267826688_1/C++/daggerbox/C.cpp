

#if 1

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;
typedef int64_t int64;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define mp make_pair
#define X first
#define Y second

static void solve();

int main() {
	freopen("C.in.txt","r",stdin);
	freopen("C.out.txt","w",stdout);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << '\n';
	}
	return 0;
}

class Q {
public:
	int v;
	Q() : v(1) {}
	Q(char c) : v(c - 'i' + 2) {}
	Q(int k) : v(k) {}
	Q(Q const &q) = default;
	Q(Q && q) = default;
	Q& operator =(Q const & q) = default;
	bool operator ==(Q const & q) const { return v == q.v; }
	bool operator <(Q const & q) const { return v < q.v; }
	
	enum { i = 2, j, k};
	
	Q operator *(Q q) const {
		if (abs(v) == 1 || abs(q.v) == 1)
			return Q(v * q.v);
		int s = ((v < 0) != (q.v < 0)) ? -1 : 1;
		int qv = abs(q.v);
		switch (abs(v)) {
			case 2:	// i
				switch (qv) {
					case 2:	// i
						return Q(s * -1);	// i*i
						break;
					case 3:	// j
						return Q(s * k);	// i*j
						break;
					case 4:	// k
						return Q(s * -j);	// i*k
						break;
					default:
						throw 1;	// bug
				}
				break;
			case 3:	// j
				switch (qv) {
					case 2:	// i
						return Q(s * -k);	// j*i
						break;
					case 3:	// j
						return Q(s * -1);	// j*j
						break;
					case 4:	// k
						return Q(s * i);	// j*k
						break;
					default:
						throw 1;	// bug
				}
				break;
			case 4:	// k
				switch (qv) {
					case 2:	// i
						return Q(s * j);	// k*i
						break;
					case 3:	// j
						return Q(s * -i);	// k*j
						break;
					case 4:	// k
						return Q(s * -1);	// k*k
						break;
					default:
						throw 1;	// bug
				}
				break;
			default:
				throw 1;	// bug
		}
		throw 1;	// bug
	}
};

static void solve() {

	int64 len, x;
	cin >> len >> x;
	string s;
	cin >> s;
	
	bool possible = false;
	vector<Q> q;
	vector<Q> leading;
	vector<Q> trailing;
	
	if (x > 16)
		x -= (x - 16) / 4 * 4;
	for (int i = 0; i < x; i++) {
		for (auto c : s) {
			q.push_back(Q(c));
		}
	}
	leading.push_back(q[0]);
	for (int i = 1; i < q.size(); i++) {
		leading.push_back(leading[i - 1] * q[i]);
	}

	trailing.push_back(q.back());
	for (int i = 1; i < q.size(); i++) {
		trailing.push_back(q[q.size() - i - 1] * trailing[i - 1]);
	}
	reverse(trailing.begin(), trailing.end());

	auto ipos = find(leading.begin(), leading.end(), Q(Q::i));
	auto krpos = find(trailing.rbegin(), trailing.rend(), Q(Q::k));
	if (ipos != leading.end() && krpos != trailing.rend()) {
		auto kpos = krpos.base();
		auto ii = ipos - leading.begin();
		auto kk = kpos - trailing.begin() - 1;
		// found i and k
		if (ii < kk) {
			Q jj;
			for (auto pos = ii + 1; pos != kk; ++pos) {
				jj = jj * q[pos];
			}
			if (jj == Q(Q::j))
				possible = true;
		}
		else {
		}
	}
	
	cout << (possible ? "YES" : "NO");
}

#endif

