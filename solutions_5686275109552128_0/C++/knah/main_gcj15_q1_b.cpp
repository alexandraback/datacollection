//compiler: MSVC 2010 (C++ obviously)
//one template to rule them all

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <queue>

typedef unsigned long long ull;
typedef long long ll;

#define FN "gcj_b"

using namespace std;

int main() {
	//freopen("in.in", "r", stdin);
    //freopen("in.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int t;
	in >> t;

	std::priority_queue<int, vector<int>, std::less<int>> pq;

	for(int tn = 0; tn < t; tn++) {
		int d;
		in >> d;
		pq = std::priority_queue<int, vector<int>, std::less<int>>();
		for(int i = 0; i < d; i++) {
			int cc;
			in >> cc;
			pq.push(cc);
		}
		int ba = pq.top();
		int addcost = 0;
		while(pq.top() > 1) {
			int ptop = pq.top();
			pq.pop();
			addcost++;
			int half = ptop / 2;
			pq.push(half);
			pq.push(ptop - half);
			ba = min(ba, (int) pq.top() + addcost);
		}
		out << "Case #" << tn + 1 << ": " << ba << "\n";
	}

	return 0;
}