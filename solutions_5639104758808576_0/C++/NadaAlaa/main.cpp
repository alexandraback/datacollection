#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	/*freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++){
		int smax, tmp = 0, ans = 0;
		string s;
		cin >> smax >> s;
		for (int i = 0; i < s.size(); i++){
			if (i > tmp && (s[i] - '0')){
				ans += i - tmp;
				tmp += i - tmp;
			}
			tmp += s[i] - '0';
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}
//int r, c, x, y;
//while (cin >> r >> c >> x >> y){
//	char arr[1001][1001];
//	int dash[1002] = { 0 }, dot[1002] = { 0 }, ans = 0;
//	for (int i = 0; i < r; i++) cin >> arr[i];
//	for (int i = 0; i < c; i++){
//		for (int j = 0; j < r; j++){
//			dash[i] += (arr[j][i] == '#');
//			dot[i] += (arr[j][i] == '.');
//		}
//	}
//	for (int i = 0; i < c;){
//		int x = 0, y = 0;
//		for (int j = i; j < i + x; j++, i++){
//			x += r - dash[i];
//			y += r - dot[i];
//		}
//		ans += min(x, y);
//	}
//}