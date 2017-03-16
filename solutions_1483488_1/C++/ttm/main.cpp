#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

/*int irot(int a, int b) {
	int dig = (int)floor(log10(a) + 1);
	if (dig != (int)floor(log10(b) + 1)) return false;
	int m = (int)pow(10, dig - 1);
	int num = 0;
	int n = b;
	for (int r = 0; r < dig - 1; ++r) {
		n = m * (n % 10) + n / 10;
		if (n == a && found.find(b) == found.end()) {
			found.insert(b);
			num++;
		}
		else if (n == a) num++;
	}
	return num;
}*/

#define maxbound 2223

int main (int argc, char *argv[]) {

	vector<int> v(maxbound);
	vector<bool> c(maxbound);
	
	/*for (int i = 0; i < maxbound; ++i) {
		v[i] = 0;
		c[i] = false;
	}

	for (int i = 0; i < maxbound; ++i) {
		int j = i;
		c[i] = true;
		if (i > 0) v[i] += v[i - 1];
		int p = (int)floor(log10(i)) + 1;
		int m = (int)pow(10, p - 1);
		for (int r = 0; r < p - 1; ++r) {
			j = m * (j % 10) + j / 10;
			if (j < maxbound && !c[j]) {
				v[j]++;
			}
		}
	}*/
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int cases;
	cin >> cases;

	for (int cas = 1; cas <= cases; ++cas) {
		int a, b;
		cin >> a >> b;

		v[a] = 0;
		for (int i = a + 1; i <= b; ++i) {
			v[i] += v[i - 1];
			int p = (int)floor(log10(i)) + 1;
			int m = (int)pow(10, p - 1);
			int j = i;
			for (int r = 0; r < p - 1; ++r) {
				j = m * (j % 10) + j / 10;
				if (j < maxbound && j > i) {
					v[j]++;
					//cout << j << endl;
				}
			}
		}

		cout << "Case #" << cas << ": " << v[b] - v[max(0, a)] << endl;
	}

	return 0;
}