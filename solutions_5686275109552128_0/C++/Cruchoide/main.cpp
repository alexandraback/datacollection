#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ostream& operator<<(ostream& out, vector<int> v) {
	out << "[";
	if(v.size()) {
		out << v.front();
		for(auto i = v.begin()+1, e = v.end(); i != e; ++i)
			out << ", " << *i;
	}
	return out << "]";
}

int split(vector<int> &P, int n) {
	auto Pmax = max_element(P.begin(), P.end());
	if(*Pmax >= n) {
		int tmp = *Pmax / n;
		*Pmax -= (n-1) * tmp;
		for(--n; n; --n)
			P.push_back(tmp);
	}
	return *(max_element(P.begin(), P.end()));
}

int solve(vector<int>::const_iterator begin, vector<int>::const_iterator end,
		int goal, int lost, int offset) {
	clog << "Try goal " << goal << " with " << lost << " loss and offset " << offset
	     << " on " << vector<int>(begin, end) << endl;
	if(goal < offset+lost) {
		offset = max(offset, *begin);
		return offset+lost;
	}
	if(begin == end)
		return offset+lost;
	for(int n = 0; n <= goal-lost-offset; ++n) { // We split *begin n times
		int splited = ((*begin)+n)/(n+1); // Max value once splitted
		int new_offset = max(offset, splited); // New offset
		int new_lost = lost + n; // Time spent splitting
		if(new_offset+new_lost <= goal) { // If splitting n times reaches the goal...
			int partial = solve(begin+1, end, goal, new_lost, new_offset); // ...try it
			if(partial <= goal)
				return partial;
		}
	}
	offset = max(offset, *begin);
	return offset+lost;
}

int solve(vector<int> P) {
	sort(P.begin(), P.end(), std::greater<int>());
	for(int k = 0; k < P.front(); ++k)
		if(solve(P.begin(), P.end(), k, 0, 0) <= k)
			return k;
	return P.front();
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;

	for(int t = 0; t < T; t++) {
		int D;
		vector<int> P;

		cin >> D;
		for(int d = 0; d < D; ++d) {
			int p;
			cin >> p;
			P.push_back(p);
		}

		cout << "Case #" << t+1 << ": " << solve(P) << endl;
	}
	return 0;
}
