#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, A, B, K;
	vector<string> v;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		
		int ans = 0;

		cin >> A >> B >> K;

		for(int a = 0; a < A; ++a) {
			for(int b = 0; b < B; ++b) {
				int c = a & b;
				if(c >= 0 && c < K)
					ans++;
			}
		}

		cout << "Case #" << t <<": "<<ans << endl;
	}

	return 0;
}