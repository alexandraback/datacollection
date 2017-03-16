#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;

long long power(long long b, long long e) {
	if(e == 0) return 1ll;
	return (e % 2 == 0)? power(b*b, e / 2) : b * power(b, e - 1);
}

int main() {
	ios::sync_with_stdio(0);

	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++) {
		long long len, comp, bound;
		cin >> len >> comp >> bound;
		long long totalLen = power(len, comp);

		int curi = 0;
		vector<long long> answer;
		long long l1, x;
		while(curi < len) {
			
			x = totalLen / len;
			l1 = curi * x;
			curi++;
			
			while(x > 1 && curi < len) {
				x = x / len;
				l1 += curi * x;
				curi++;
			}
			answer.push_back(l1);
		}
		cout << "Case #" << cas << ": ";
		if(answer.size() > bound)
			cout << "IMPOSSIBLE\n";
		else {
			for(int i = 0; i < answer.size(); i++)
				cout << answer[i] + 1 << " ";
			cout << '\n';
		}
	}
}
