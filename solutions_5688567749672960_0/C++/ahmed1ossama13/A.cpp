#include<bits/stdc++.h>
using namespace std;


map<int, int> mem;

int rev(int x) {
	int res = 0;
	while (x != 0) {
		int d = x % 10;
		res = res * 10 + d;
		x /= 10;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	freopen("/home/ahmed_ossama/Desktop/Code jam/A/Small/A-small-attempt0.in", "r", stdin);
	freopen("/home/ahmed_ossama/Desktop/Code jam/A/Small/A-small-attempt0.out", "w", stdout);
	int t;
	cin >> t;
	int id = 1;
	mem.clear();
	mem[1] = 1;
	queue<int> q;
	q.push(1);
	int cnt = 0;
	while (cnt < 1000005) {
		int x = q.front();
		q.pop();
		if (x == 1000000)
			break;
		if (mem.find(x + 1) == mem.end())
			q.push(x + 1), mem[x + 1] = mem[x] + 1;
		int y = rev(x);
		if (mem.find(y) == mem.end())
			q.push(y), mem[y] = mem[x] + 1;
		cnt++;
	}
	while (t--) {
		long long n;
		cin >> n;

		cout << "Case #" << id++ << ": " << mem[n] << endl;
	}

	return 0;
}


