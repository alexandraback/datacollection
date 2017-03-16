//#include <cstdio>
//#include <cstring>
//#include <string>
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <set>
//#include <map>
//#include <cmath>
//#include <algorithm>
//
//typedef long long LL;
//
//using namespace std;
//
//#define N 102
//
//const int box = 0, toy = 1;
//
//struct Node {
//	LL p, sum;
//	void update(LL _p, LL _sum) {
//		if(_sum > sum || sum == _sum && p < _p) {
//			sum = _sum, p = _p;
//		}
//	}
//}f[N][N][N][2];
//
//struct Point {
//	int c;
//	int type;
//}line_box[N], line_toy[N];
//
//void update(int i, int j, int k) {
//	LL box_sum = f[i][j][k][box].sum, toy_sum = f[i][j][k][toy].sum;
//	LL box_p = f[i][j][k][box].p, toy_p = f[i][j][k][toy].p;
//	
//	来的都丢弃
//	f[i + 1][j][k][box].update(box_p, box_sum);
//	f[i + 1][j][k][toy].update(toy_p, toy_sum);
//
//	f[i][j + 1][k][box].update(box_p, box_sum);
//	f[i][j + 1][k][toy].update(toy_p, toy_sum);
//
//	考虑来了一个箱子，并且不丢弃
//	if(line_box[i + 1].type == k) { //和前面用一个类型
//		f[i + 1][j][k][box].update(box_p + line_box[i + 1].c, box_sum);
//		if(toy_p <= line_box[i + 1].c) {
//			f[i + 1][j][k][box].update(line_box[i + 1].c - toy_p, toy_sum + toy_p);
//		} else {
//			f[i + 1][j][k][toy].update(toy_p - line_box[i + 1].c, toy_sum + line_box[i + 1].c);
//		}
//	} else {
//		f[i + 1][j][line_box[i + 1].type][box].update(line_box[i + 1].c, max(toy_sum, box_sum));
//	}
//
//	考虑来了一玩具，并且不丢弃
//	if(line_toy[j + 1].type == k) {
//		f[i][j + 1][k][toy].update(toy_p + line_toy[j + 1].c, toy_sum);
//		if(box_p <= line_toy[j + 1].c) {
//			f[i][j + 1][k][toy].update(line_toy[j + 1].c - box_p, box_sum + box_p);
//		} else {
//			f[i][j + 1][k][box].update(box_p - line_toy[j + 1].c, box_sum + line_toy[j + 1].c);
//		}
//	} else {
//		f[i][j + 1][line_toy[j + 1].type][toy].update(line_toy[j + 1].c, max(toy_sum, box_sum));
//	}
//}
//
//int main()
//{
//	int T;
//	freopen("A-large.in", "r", stdin);
//	freopen("a.out", "w", stdout);
//	cin >> T;
//	for(int test = 1; test <= T; ++test) {
//		cout << "Case #" << test << ": ";
//		int n, m, x;
//		cin >> n >> m;
//		for(int i = 1; i <= n; ++i) {
//			cin >> line_box[i].c >> line_box[i].type;
//		}
//		for(int i = 1; i <= m; ++i) {
//			cin >> line_toy[i].c >> line_toy[i].type;
//		}
//		memset(f, 0, sizeof(f));
//		for(int i = 0; i <= n; ++i) {
//			for(int j = 0; j <= m; ++j) {
//				for(int k = 1; k <= 100; ++k) {
//					update(i, j, k);
//				}
//			}
//		}
//		LL ans = 0;
//		for(int i = 1; i <= 100; ++i) {
//			ans = max(ans, f[n][m][i][box].sum);
//			ans = max(ans, f[n][m][i][toy].sum);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

typedef long long LL;

using namespace std;

#define N 102

struct Point {
	LL c;
	int type;
}line_box[N], line_toy[N];

const int box = 0, toy = 1;

LL check(int left, int right, LL boxes, int type) {
	LL sum = 0, inc;
	for(int k = left; k < right && boxes; ++k) {
		if(line_toy[k].type == type) {
			inc = min(line_toy[k].c, boxes);
			boxes -= inc;
			sum += inc;
		}
	}
	return sum;
}

int main()
{
	int T;
	freopen("C-small-attempt4.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin >> T;
	for(int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
		int n, m, x;
		cin >> n >> m;
		memset(line_box, 0, sizeof line_box);
		for(int i = 1, k = 1; i <= n; ++i) {
			cin >> line_box[k].c >> line_box[k].type;
			if(line_box[k].type != line_box[k - 1].type) {
				++k;
			} else {
				line_box[k - 1].c += line_box[k].c;
				line_box[k].type = line_box[k].c = 0;
			}
		}
		for(int i = 1; i <= m; ++i) {
			cin >> line_toy[i].c >> line_toy[i].type;
		}

		LL ans = 0;
		for(int i = 1; i <= m; ++i) {
			for(int j = i; j <= m; ++j) {
				LL sum = check(1, i, line_box[1].c, line_box[1].type) \
					+ check(i, j, line_box[2].c, line_box[2].type) \
					+ check(j, m, line_box[3].c, line_box[3].type);
				ans = max(ans, sum);
			}
		}
		if(line_box[1].type == line_box[3].type) {
			LL sum = 0;
			for(int i = 1; i <= m; ++i) {
				sum += (line_toy[i].type == line_box[1].type? line_toy[i].c: 0);
			}
			ans = max(ans, min(sum, line_box[1].c + line_box[3].c));
		}
		cout << ans << endl;
	}
	return 0;
}
