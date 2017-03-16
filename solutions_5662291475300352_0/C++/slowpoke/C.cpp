#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <array>
#include <string>
#include <deque>
#include <list>
#include <numeric>
#include <limits>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <assert.h>

using namespace std;

struct Hiker{
	int start;
	int revtime;
};

void comp(int tc){
	int N;
	cin >> N;

	vector<Hiker> v;
	for (int i = 0; i < N; ++i){
		int D, H, M;
		cin >> D >> H >> M;
		for (int j = 0; j < H; ++j){
			v.push_back({ D, M + j });
		}
	}

	assert(v.size() <= 2);

	int res = 0;
	if (v.size() == 2){
		if (v[0].revtime > v[1].revtime)
			swap(v[0], v[1]);

		double fast = v[0].revtime * (360.0 + (360.0 - v[0].start));
		double slow = v[1].revtime * (360.0 - v[1].start);
		if (fast <= slow){
			res = 1;
		}
	}

	cout << "Case #" << tc << ": " << res << endl;
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		comp(i);
	}
}