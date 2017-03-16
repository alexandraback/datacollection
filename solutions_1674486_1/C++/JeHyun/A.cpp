#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cfloat>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <queue>

#define REP(i,a) for(i=0;i<a;++i)
#define FOR(i,a,b) for(i=a;i<=b;++i)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
using namespace std;

void main() {
	int T;
	int i;

	cin >> T;

	REP(i,T) {
		int N;
		int j,k;
		cin >> N;
		int nums[1001];
		int* con[1001];

		REP(j,N) {
			cin >> nums[j];
			con[j] = new int[nums[j]];

			REP(k,nums[j]) {
				cin >> con[j][k];
				--con[j][k];
			}
		}

		bool found = false;

		REP(j,N) {
			queue<int> qu;
			qu.push(j);
			bool visited[1001];
			memset(visited,0x00, sizeof(visited));
			visited[j] = true;

			while (!qu.empty()) {
				int el = qu.front();
				qu.pop();

				REP(k,nums[el]) {
					if (visited[con[el][k]]) {
						if (con[el][k] == j)
							continue;
						//cout << "oh!!! " << j << " " << con[el][k] << endl;
						break;
					}
					qu.push(con[el][k]);
					visited[con[el][k]] = true;
				}

				if (k != nums[el]) {
					//cout << j << " haha " << el << " " << k << " " << con[el][k] << endl;
					while (!qu.empty())
						qu.pop();

					cout << "Case #" << (i+1) << ": Yes" << endl;
					found = true;
					break;
				}
			}

			if (found)
				break;
		}

		if (!found)
			cout << "Case #" << (i+1) << ": No" << endl;
	}
}