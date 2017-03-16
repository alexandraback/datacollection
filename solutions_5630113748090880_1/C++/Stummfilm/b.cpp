#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string solve(int n, int array[]){
	int var;
	int cur = 0;
	int count = 0;
	int ret[n];

	sort(array, array + (2 * n - 1) * n);

	var = array[0];

	for(int i = 0; i < (2 * n - 1) * n; i++) {
		if(array[i] == var) {
			count++;
		}
		else {
			if(count % 2 == 1) {
				ret[cur++] = var;
			}
			var = array[i];
			count = 1;
		}
	}

	if(count % 2 == 1) {
		ret[cur++] = var;
	}


	ostringstream oss("");
	for(int i = 0; i < n; i++) {
		oss <<  ret[i];
		if(i != n - 1)
		 	oss << " ";
	}
	return oss.str();
}

int main() {
	int t;
	int n;
	int x;

	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> n;
		int array[(2 * n - 1) * n];
		for(int k = 0; k < (2 * n - 1) * n; k++) {
			cin >> x;
			array[k] = x;
		}
		cout << "Case #" << (i + 1) << ": " << solve(n, array) << endl;
	}

	return EXIT_SUCCESS;
}
