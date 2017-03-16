#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>

#define D(x) x

using namespace std;

int main() {
	int numTestCases;
	cin >> numTestCases;
	
	for (int T = 1; T <= numTestCases; T++) {
		int N;
		cin >> N;
		
		vector<int> current = { 1 }, next;
		set<int> visited;
		int iter = 1;
		bool found = false;
		
		while (true) {
			for (int x : current) {
				if (x == N) {
					found = true;
					break;
				}
				
				if (visited.count(x) != 0) continue;
				visited.insert(x);
				
				next.push_back(x+1);
				
				
				int reversed = 0;
				int y = x;
				while (y > 0) {
					reversed *= 10;
					reversed += y%10;
					y /= 10;
				}
				next.push_back(reversed);
			}
			if (found) break;
			swap(current, next);
			next.clear();
			iter++;
		}
		
		cout << "Case #" << T << ": " << iter << endl;
	}
}