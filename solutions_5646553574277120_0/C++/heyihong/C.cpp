#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

typedef priority_queue<LL, vector<LL>, greater<LL> > small_heap;

void add(small_heap & heap, LL x, LL c) {
	for (int y = 1; y <= c; c -= y, y = y * 2) {
		heap.push(x * y);
	}
	if (c)
		heap.push(x * c);
}

int main() {
	freopen("in.txt", "r", stdin);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; ++tc) {
		LL c, d, v;
		cin >> c >> d >> v;
		small_heap heap;
		for (; d; --d) {
			LL x; 
			cin >> x;
			add(heap, x, c);
		}
		LL money = 0, ans = 0;
		while (money < v) {
			if (heap.empty() || heap.top() > money + 1) {
				add(heap, money + 1, c);
				++ans;
			}
			else {
				money += heap.top();
				heap.pop();
			}
		}
		cout << "Case #" << tc << ": " << ans << endl;	
	}
	return 0;
}
