#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>

int main() {
    int numcases;
    std::cin >> numcases;
    for (int casenum = 1; casenum <= numcases; ++casenum) {
	int a, b;
	std::cin >> a >> b;

	std::vector<double> v;
	for (int i = 0; i < a; ++i) {
	    double x;
	    std::cin >> x;
	    v.push_back(x);
	}

	// cumprods[i] is probability that the first i are correct.
	std::vector<double> cumprods(v.size() + 1);
	cumprods[0] = 1.0;
	for (int i = 0; i < a; ++i) {
	    cumprods[i + 1] = cumprods[i] * v[i];
	}

	double min_expected_keystrokes = b + 2;
	for (int i = 0; i <= a; ++i) {
	    int success_keystrokes = (b - i) + (a - i) + 1;
	    int failure_keystrokes = success_keystrokes + b + 1;

	    double expected_keystrokes = cumprods[i] * success_keystrokes
		+ (1 - cumprods[i]) * failure_keystrokes;

	    if (expected_keystrokes < min_expected_keystrokes) {
		min_expected_keystrokes = expected_keystrokes;
	    }
	}

	std::cout << "Case #" << casenum << ": ";
	printf("%.7f", min_expected_keystrokes);
	std::cout << std::endl;
    }

}
