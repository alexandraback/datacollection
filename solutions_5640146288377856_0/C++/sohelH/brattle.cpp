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

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int r, c, w;
		cin >> r >> c >> w;

		printf("Case #%d: ", cases);

		if (c == w) {
			cout << c << endl;
			continue;
		}

		int res = w;

		while(c > w) {
			c -= w;
			res++;
		}
		cout << res << endl;
	}
	return 0;
}
