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
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++){
		int arr[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 }, { 0, 2, -1, 4, -3 }, { 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };
		int l, x, val = 1, c = 2;
		cin >> l >> x;
		string s, s1;
		cin >> s1;
		for (int i = 0; i < x; i++) s += s1;
		for (int i = 0; i < l*x; i++){
			if (val < 0) val = -arr[-val][s[i] - 'i' + 2];
			else val = arr[val][s[i] - 'i' + 2];
			if (val == c) {
				c++;
				val = 1;
			}
		}
		if (c == 5 && val == 1) cout << "Case #" << tc << ": YES" << endl;
		else cout << "Case #" << tc << ": NO" << endl;
	}
	return 0;
}