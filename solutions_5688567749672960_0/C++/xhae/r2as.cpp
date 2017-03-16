#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int dist[1000001];

int main(void) {
	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		int next = cur + 1;
		if(next >= 1 && next <= 1000000 && dist[next] == 0) {
			dist[next] = dist[cur] + 1;
			q.push(next);
		}

		stringstream it;
		it << cur;
		string res;
		it >> res;
		reverse(res.begin(), res.end());

		stringstream it2(res);
		it2 >> next;
		if(next >= 1 && next <= 1000000 && dist[next] == 0) {
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}

	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		int n;
		cin >> n;
		cout << "Case #" << kase << ": " << dist[n] << "\n";
	}

	return 0;
}
