#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool hasSeen[10];

void markDigits(int n) {
	while(n > 0) {
		int digit = n % 10;
		hasSeen[digit] = true;
		n /= 10;
	}
}

bool seenAllDigits() {
	for(int i = 0; i < 10; i++) {
		if(hasSeen[i] == false)
			return false;
	}
	return true;
}

int main()
{
	freopen("sheep.in", "r", stdin);
	freopen("sheep.out", "w", stdout);
	int t;
	cin >> t;
	for(int caseNum = 1; caseNum <= t; caseNum++) {
		for(int i = 0; i < 10; i++) {
			hasSeen[i] = false;
		}
		int n;
		cin >> n;
		if(n == 0) {
			cout << "Case #" << caseNum << ": INSOMNIA" << endl;
			continue;
		}
		int i = 0;
		while(!seenAllDigits()) {
			i++;
			markDigits(i*n);
		}
		cout << "Case #" << caseNum << ": " << i*n << endl;
	}
	return 0;
}