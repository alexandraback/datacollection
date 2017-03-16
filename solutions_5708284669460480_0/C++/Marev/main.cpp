#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int worst;

int find_string(string full, string part) {
	int start = 0;
	int times = 0;
	while ((start = full.find(part, start)) != string::npos) {
		++times;
		start++;
	}
	if (times > worst) {
		worst = times;
	}
	return times;
}

string keyboard;
string to_find;

double generate_string(string a, int nLetters, int currentLetter) {
	if (nLetters == currentLetter) {
		return find_string(a, to_find);
	}
	double sum = 0.0;
	for (int i = 0; i < keyboard.length(); i++) {
		sum += generate_string(a + keyboard[i], nLetters, currentLetter + 1);
	}
	return sum;
}

double run() {
	int k, l;
	int s;
	cin >> k >> l >> s;
	cin >> keyboard >> to_find;
	worst = 0;
	double total = pow(k, s);
	double sum = generate_string("", s, 0);
	return (double)worst - (sum / total);
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << fixed;
		cout << "Case #" << i << ": " << setprecision(7) << run() << endl;
	}
	return 0;
}