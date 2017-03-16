#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 550;
int n, limit, size;
long long a[N], ans[N], res[N];
int ch[N];

void shuffle(long long a[], int n) {
	for (int i = 0; i < n; i++) {
		int x = rand() % n;
		int y = rand() % n;
		swap(a[x], a[y]);
	}
}

bool solve() {
	if (size != limit) return true;
	sort(res, res + n);
	for (int i = 0; i < limit; i++)
		if (res[i] != ans[i]) return true;
	return false;
}

void print(long long a[], int n) {
	cout << a[0];
	for (int i = 1; i < n; i++)
		cout << ' ' << a[i];
	cout << endl;
}

int find(long long sum) {
	for (int rp = 0; rp < 1000; rp++) {
		shuffle(a, n);
		long long s = 0;
		for (int i = 0; i < n; i++) {
			ch[i] = rand() & 1;
			if (ch[i]) s += a[i];
		}
		int update = true;
		while (s != sum && update) {
			update = false;
			for (int i = 0; i < n; i++) {
				long long ss = s;
				if (ch[i] == 0)
					ss += a[i];
				else ss -= a[i];
				long long A = abs(ss - sum);
				long long B = abs(s - sum);
				if (A <= B) {
					s = ss;
					ch[i] = 1 - ch[i];
					update = (A < B);
				}
			}
			cout << abs(s - sum) << endl;
		}
		if (s != sum) continue;
		int size = 0;
		for (int i = 0; i < n; i++)
			if (ch[i] == 1)
				res[size++] = a[i];
		return size;
	}
	return 0;
}

int main() {
	srand(32057);
	int tt;
	cin >> tt;
	for (int cas = 1; cas <= tt; cas++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		limit = n >> 1;
		while (true) {
			shuffle(a, n);
			int sum = 0;
			for (int i = 0; i < limit; i++)
				sum += a[i];
			memcpy(ans, a, sizeof(a));
			sort(ans, ans + limit);
			size = find(sum);
			if (size == 0) continue;
			if (solve()) break;
		}
		printf("Case #%d:\n", cas);
		print(ans, limit);
		print(res, size);
	}
	return 0;
}
