#include <fstream>

using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("out.txt");

bool used[10];

bool allDigits() {
	for (int i = 0; i < 10; ++i) {
		if (!used[i]) {
			return false;
		}
	}

	return true;
}

void addNewDigits(int x) {
	while (x > 0) {
		used[x % 10] = true;
		x /= 10;
	}
}

int main() {
	int tests;
	fin >> tests;

	int ans = 0;
	for(int test = 0; test < tests; ++test) {
		bool isPossible = true;
		
		int n, x;
		fin >> n;
		if (n == 0) {
			isPossible = false;
		} else {
			for (int i = 0; i < 10; ++i) {
		    	used[i] = false;
		    }

			x = n;
			addNewDigits(x);
			while (!allDigits()) {
				x = x + n;
				addNewDigits(x);
			}
		}

		if (isPossible) {
		    fout << "Case #" << test + 1 << ": " << x << endl;
		} else {
			fout << "Case #" << test + 1 << ": INSOMNIA" << endl;
		}
	}

	return 0;
}
