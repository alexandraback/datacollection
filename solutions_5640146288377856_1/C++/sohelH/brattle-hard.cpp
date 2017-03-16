#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int cal(int r, int c, int w) {
		if (c == w) {
			return c;
		}
		int res = w;
		while(c > w) {
			c -= w;
			res++;
		}
		return res;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int r, c, w;
		cin >> r >> c >> w;

		printf("Case #%d: ", cases);

		int singleRes = cal(r, c, w);

		if (r == 1) {
			cout << singleRes << endl;
			continue;
		}

		int k = 0;
		while (c >= w) {
			k++;
			c -= w;
		}

		cout << (k * (r - 1) + singleRes) << endl;

	}
	return 0;
}
