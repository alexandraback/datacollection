#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef unsigned long long uint64;

int main()
{
	ios_base::sync_with_stdio(0);
	int test_cases;
	cin >> test_cases;
	for (int test_num = 1; test_num <= test_cases; ++test_num) {
		cout << "Case #" << test_num << ": ";
		int x, y;
		cin >> x >> y;
		string path;
		const vector<char> n = {'N', 'E', 'S', 'W'};
		const vector<int> di = {0, 1, 0, -1};
		const vector<int> dj = {1, 0, -1, 0};
		int curx = 0;
		int cury = 0;
		int k = (x > 0) ? 3 : 1;
		int jump = 0;
		while (curx != x) {
			jump++;
			path += n[k];
			curx += di[k] * jump;
			k = (k + 2) % 4;
		}
		k = (y > 0) ? 2 : 0;
		while (cury != y) {
			jump++;
			path += n[k];
			cury += dj[k] * jump;
			k = (k + 2) % 4;
		}
		cout << path << endl;
	}
	return 0;
}