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
	freopen("B-large.in", "r", stdin);
	freopen("out1.txt", "w", stdout);
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++){
		int ans = 1e9, d, arr[2000];
		cin >> d;
		for (int i = 0; i < d; i++) cin >> arr[i];
		for (int i = 1; i <= 1000; i++){
			int tmp = 0;
			for (int j = 0; j < d; j++){
				tmp += (arr[j] + i - 1) / i - 1;
			}
			ans = min(ans, i + tmp);
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}