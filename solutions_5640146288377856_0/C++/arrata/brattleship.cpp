#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int score(int r, int c, int w) {
	int ret = 0;
	int rowcount = c / w;
	ret += (r * rowcount);
	if((c % w) == 0) {
		ret += w - 1;
	}
	else {
		ret += w;
	}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; ++i) {
		int r, c, w;
		cin >> r >> c >> w;
		cout << "Case #"<< i+1 << ": " << score(r, c, w) << endl;
	}
	return 0;
}