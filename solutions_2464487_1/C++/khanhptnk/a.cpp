#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstring>
using namespace std;

int ntest;
long long r, t;

int main() {
	freopen("input_small.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);
	cin >> ntest;
	for (int test = 0; test < ntest; test++) {
		cin >> r >> t;
		long long cur = r;
		long long ans = 0;
		while (true) {
			long long area = ((cur + 1) * (cur + 1) - cur * cur);
			if (t >= area) {
				ans++;
				t -= area;
				cur += 2;
			}
			else break;
		}	
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
}
