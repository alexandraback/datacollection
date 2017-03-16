#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int mem[2000005];

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int A, B;
		cin >> A >> B;
		set< pair<int, int> > S;
		for (int i = A; i <= B; i++) {
			int sz = 1;
			int tmp = i;
			while (tmp / 10 > 0) { sz++; tmp /= 10; }
			int c = 1; for (int j = 0; j < sz-1; j++, c *= 10) ;
			for (int j = 0, tt = 10; j < sz-1; j++, tt *= 10, c /= 10) {
				tmp = ((i%tt)*c) + i/tt;
				if (tmp > i && tmp <= B) S.insert(make_pair(i, tmp));
			}
		}

		printf("Case #%d: %d\n", t, S.size());
	}
}