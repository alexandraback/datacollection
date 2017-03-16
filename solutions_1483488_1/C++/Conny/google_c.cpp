#include <iostream>
#include <cmath>
using namespace std;

int power10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int lower, upper;
long long visited[2000001];
long long TRUE = 0;

int shift1(int n, int digits) {
	int l = n % 10;
	n /= 10;
	n += l * power10[digits];
	
	return n;
}

int isValid(int n, int m) {
	if (n > m && n <= upper && visited[n] != TRUE) {
		visited[n] = TRUE;
		return 1;
	} else {
		return 0;
	}
}

int getResult(int n) {
	int m = n;
	int digits = log10(double(n) + 0.5);
	int result = 0;
	TRUE++;
	
	for (int i = 0; i < digits; i++) {
		n = shift1(n, digits);
		if (isValid(n, m)) {
			result++;
		}
	}
	
	return result;
}

int main() {
	int cases;
	cin >> cases;
	for (int cnt = 1; cnt <= cases; cnt++) {
		cin >> lower >> upper;
		
		int result = 0;
		for (int i = lower; i < upper; i++) {
			result += getResult(i);
		}
		
		cout << "Case #" << cnt << ": " << result << endl;
	}
	
	return 0;
}
