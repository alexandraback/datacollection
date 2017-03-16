#include <bits/stdc++.h>

using namespace std;

using entry = tuple<int, int, int>;

template <int X, int Y>
bool check(vector<entry> const& V, int K) {
	map<pair<int, int>, int> P;

	for(auto v : V) {
		pair<int, int> pp(get<X>(v), get<Y>(v));
		if(P[pp] >= K) return false;
		P[pp]++;
	}
	return true;
}

void test(int TT) {
	int a, b, c, k;
	vector<entry> sol;

	cin >> a >> b >> c >> k;

	if(a*b*c < a*b*k) {
		for(int i=1; i<=a; i++)
			for(int j=1; j<=b; j++)
				for(int l=1; l<=c; l++)
					sol.emplace_back(i, j, l);
	} else {
		for(int i=1; i<=a; i++) {
			for(int j=1; j<=b; j++) {
				for(int x=1; x<=k; x++) {
					sol.emplace_back(i, j, (x+j+i)%c+1);
				}
			}
		}
	}

	cout << "Case #" << TT << ": " << sol.size() << endl;
	for(auto e : sol) {
		cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
	}

	assert((check<0, 1>(sol, k)));
	assert((check<1, 2>(sol, k)));
	assert((check<2, 0>(sol, k)));
}

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) test(i);
}
