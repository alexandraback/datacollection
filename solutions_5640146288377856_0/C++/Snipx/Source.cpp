#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {

		int r, c, w;
		cin >> r >> c >> w;
		int firstGuess = c / w * r;
		int rest = (c % w) + w;
		int ans = firstGuess;
		ans += w - 1;
		if (rest != w)
			ans++;


		cout << "Case #" << test << ": " << ans << endl;
	}


	//system("pause");
	return 0;
}