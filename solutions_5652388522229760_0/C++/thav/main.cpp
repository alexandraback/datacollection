#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

bool proc(bool* dig, long long x, int& count) {
	while(x) {
		if(dig[x % 10] == false)
			count++;
		dig[x % 10] = true;
		x /= 10;
	}
	return count == 10;
}

int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++) {
		long long n;
		cin >> n;

		bool dig[10];
		memset(dig, 0, sizeof dig);
		int count = 0;

		if(n == 0)
			cout << "Case #" << cas << ": INSOMNIA\n";
		else {
			long long y = n;
			while(!proc(dig, y, count))
				y += n;
			cout << "Case #" << cas << ": " << y << '\n';
		}
	}
}