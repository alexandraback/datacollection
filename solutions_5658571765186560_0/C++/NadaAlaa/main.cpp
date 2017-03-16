#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++){
		int r, c, x;
		cin >> x >> r >> c;
		cout << "Case #" << tc << ": ";
		if (x == 1) cout << "GABRIEL" << endl;
		else if (x == 2 && (c*r) % 2 == 0) cout << "GABRIEL" << endl;
		else if (x == 3 && min(r, c) > 1 && (r*c) % 3 == 0) cout << "GABRIEL" << endl;
		else if (x == 4 && min(r, c) > 2 && (r*c) % 4 == 0) cout << "GABRIEL" << endl;
		else cout << "RICHARD" << endl;
	}
	return 0;
}