#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(int argc, char** argv) {

	int t;

	cin >> t;

	for(int iter = 1; iter <= t; iter++) {
		int n; 
		vector<int> ptr;
		cin >> n;
		ptr.resize(n + 1);
		for(int i = 1; i <= n; i++) {
			cin >> ptr[i];
		}

		set< set<int> > circles;
		set< set<int> > lines;
		vector<int> chain;
		chain.resize(n + 1);

		for(int i = 1; i <= n; i++) {
			set<int> visited;
			int cur = i;
			visited.insert(i);
			while(1) {
				int next = ptr[cur];
				if(visited.count(next)) {
					if(next == i) {
						circles.insert(visited);
					}
					break;
				}
				if(chain[next] < visited.size() && ptr[next] != cur) {
					chain[next] = visited.size();
				}
				visited.insert(next);
				cur = next;
			}
		}

		int answer = 0;
		for(int i = 1; i <= n; i++) {
			if(ptr[i] > i && ptr[ptr[i]] == i) {
				answer += (2 + chain[i] + chain[ptr[i]]);
			}
		}

		for(set< set<int> >::iterator it = circles.begin(); it != circles.end(); it++) {
			if(answer < it->size()) {
				answer = it->size();
			}
		}

		cout << "Case #" << iter << ": " << answer << endl;
	}

	return 0;
}

