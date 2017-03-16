#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

typedef long long int64;
vector<int64> fs;

bool isfair(int64 n) {
	string x = "";
	while (n > 0) {
		x += n % 10;
		n /= 10;
	}
	int i = 0, j = x.size() - 1;
	while (i <= j && x[i] == x[j]) {
		i++; j--;
	}
	return i > j;
}

int main() {
	int64 root;
	for (int64 i = 1; i <= 10000000; i++) {
		if (isfair(i) && isfair(i * i)) {
			fs.push_back(i * i);
		}
	}
	//cout << fs.size() << endl;

	//for (int i = 0; i < fs.size(); i++)
	//	cout << fs[i] << endl;
	int T, n;
	int64 A, B;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%lld%lld", &A, &B);
		n = 0;
		for (int i = 0; i < fs.size(); i++) {
			if (fs[i] < A) continue;
			if (fs[i] > B) break;
			++n;
		}
		cout << "Case #" << t << ": " << n << endl;
	}
}