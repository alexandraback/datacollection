#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


long long getNum(int x) {
	bool arr[10] = {};
	long long v = x;
	while (1) {
		for (long long i = v; i; i /= 10) {
			arr[i % 10] = 1;
		}
		int i;
		for (i = 0; i < 10; i++) {
			if (!arr[i])
				break;
		}
		if (i == 10)
			break;
		v += x;
	}
	return v;
	
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, kase = 0;
	cin >> T;
	while (++kase <= T) {
		printf("Case #%d: ", kase);
		int x;
		cin >> x;
		if (x == 0) printf("INSOMNIA\n");
		else printf("%lld\n", getNum(x));
	}

	return 0;
}