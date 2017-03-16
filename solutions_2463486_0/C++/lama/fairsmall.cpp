#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

bool square_of_pali[1100] = {false};
bool pali[1100] = {false};
int T, A, B;

bool is_pali(int n) {
	int now = n;
	vector<int> digits;
	while(now > 0) {
		digits.push_back(now % 10);
		now /= 10;
	}
	for(int i = 0; i < digits.size(); i++) {
		if(digits[i] != digits[digits.size() - 1 - i]) return false;
	}
	return true;
}

int main() {
	for(int i = 0; i < 1100; i++) {
		if(is_pali(i)) pali[i] = true;
	}
	for(int i = 0; i * i < 1100; i++) {
		if(pali[i]) square_of_pali[i * i] = true;
	}
	cin >> T;
	for(int Ti = 1; Ti <= T; Ti++) {
		cin >> A >> B;
		int res = 0;
		for(int i = A; i <= B; i++) {
			if(pali[i] && square_of_pali[i]) res++;
		}
		cout << "Case #" << Ti << ": " << res << endl;
	}

    return 0;
}