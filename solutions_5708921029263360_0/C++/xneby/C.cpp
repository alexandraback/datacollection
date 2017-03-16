#include <bits/stdc++.h>

using namespace std;

using entry = tuple<int, int, int>;

struct Case {
	int A, B, C, K;
	set<entry> best, curr;
	map<entry, int> P;

	Case() {
		cin >> A >> B >> C >> K;
	}

	bool can(int a, int b, int c) {
		//cout << "CAN? " << a << b << c << endl;
		if(curr.find(make_tuple(a,b,c)) != curr.end()) return false;

		if(P[make_tuple(a,b,0)] >= K) return false;
		if(P[make_tuple(a,0,c)] >= K) return false;
		if(P[make_tuple(0,b,c)] >= K) return false;

		//cout << "CAN! " << a << b << c << endl;
		return true;
	}
	
	void go(int a, int b, int c) {
		if(best.size() == min(A * B * K, A * B * C)) return;
		if(a>A) {
	//		cout << curr.size() << " " << best.size() << endl;
			if(curr.size() > best.size()) {
				best = curr;
			}
			return;
		}
		if(b>B) {
			go(a+1, 1, c); return;
		}
		if(c>C) {
			go(a,b+1,1); return;
		}

		if(can(a, b, c)) {
			P[make_tuple(a, b, 0)] ++;
			P[make_tuple(a, 0, c)] ++;
			P[make_tuple(0, b, c)] ++;

			curr.emplace(a,b,c);

			go(a,b,c+1);

			curr.erase(make_tuple(a,b,c));

			P[make_tuple(a, b, 0)] --;
			P[make_tuple(a, 0, c)] --;
			P[make_tuple(0, b, c)] --;
		}
		go(a,b,c+1);
	}

	set<entry> solve() {
		go(1, 1, 1);
		return best;
	}
};

void test(int TT) {
	Case c;
	auto v = c.solve();

	cout << "Case #" << TT<< ": " << v.size() <<endl;
	for(auto x : v) {
		cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
	}
}

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) test(i);
}
