#include <iostream>
#include <cstdio>
using namespace std;

const long long MAXN = 101;
long long cap;
long long values[MAXN];
long long nCoins;
long long maxValue;

long long getResult() {
	long long result = 0;
	long long currOverlap = 0;
	
	for (long long i = 0; i < nCoins; i++) {
		while (currOverlap + 1 < values[i]) {
			result++;
			currOverlap += (currOverlap + 1) * cap; //Add currOverlap + 1 to set of coins
		}
		
		currOverlap += values[i] * cap;
		
		if (currOverlap >= maxValue)
			return result;
	}
	
	while (currOverlap < maxValue) {
		result++;
		currOverlap += (currOverlap + 1) * cap; //Add currOverlap + 1 to set of coins
	}
	
	return result;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);
	long long nCases;
	cin >> nCases;
	
	for (long long cnt = 1; cnt <= nCases; cnt++) {
		cin >> cap >> nCoins >> maxValue;
		
		for (long long i = 0; i < nCoins; i++) {
			cin >> values[i];
		}
		
		cout << "Case #" << cnt << ": " << getResult() << endl;
	}
	return 0;
}
