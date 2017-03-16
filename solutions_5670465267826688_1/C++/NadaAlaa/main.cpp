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
	freopen("C-large.in", "r", stdin);
	freopen("out1.txt", "w", stdout);
	long long test;
	cin >> test;
	for (long long tc = 1; tc <= test; tc++){
		long long arr[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 }, { 0, 2, -1, 4, -3 }, { 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };
		long long l, x, tmp, val = 1, c = 2;
		bool flag = 0;
		cin >> l >> x;
		string s, s1;
		cin >> s1;
		if (x >= 64) tmp = 50;
		else tmp = x;
		for (long long i = 0; i < tmp; i++) s += s1;
		for (long long i = 0; i < s.size(); i++){
			if (val < 0) val = -arr[-val][s[i] - 'i' + 2];
			else val = arr[val][s[i] - 'i' + 2];
			if (val == c) {
				c++;
				val = 1;
			}
			if (c == 5 && tmp != x){
				for (long long j = i+1; j%l != 0 || ((x*l - j) / l) % 4 != 0; j++){
					if (val < 0) val = -arr[-val][s[j] - 'i' + 2];
					else val = arr[val][s[j] - 'i' + 2];
				}
				if (val == 1) {
					flag = 1;
					cout << "Case #" << tc << ": YES" << endl;
				}
				break;
			}
		}
		if (c == 5 && val == 1 && !flag) cout << "Case #" << tc << ": YES" << endl;
		else if (!flag) cout << "Case #" << tc << ": NO" << endl;
	}
	return 0;
}