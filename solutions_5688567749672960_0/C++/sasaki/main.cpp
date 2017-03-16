#include <iostream>
#include "Solver.h"
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	long N;
	cin >> N;
	cout << "Case #" << t << ": " << solve(N) << endl;
    }
}
