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
#pragma warning(disable:4996)

using namespace std;

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tt;
	int R, C, W,ret,k;
		scanf("%d", &tt);
	for (int qq = 1; qq <= tt; qq++) {
		cin >> R >> C >> W;

		k = C / W;

		ret = k*R+W;

		if (C <= k*W)
			ret--;
		
		printf("Case #%d: ", qq);
		cout << ret << endl;

	}
	return 0;
}