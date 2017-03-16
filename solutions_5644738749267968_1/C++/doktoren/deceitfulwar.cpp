
#include <iostream>
#include <valarray>

using namespace std;


int solve(const valarray<float> a, const valarray<float> b) {
	int count=0;
	int j=0;
	for (int i=0; i<a.size() && j<b.size(); i++) {
		while (a[i] < b[j++])
			if (j == b.size())
				return count;
		count++;
	}
	return count;
}

int main() {
	int t;
	cin >> t;
	for (int ti=1; ti<=t; ti++) {
		int n;
		cin >> n;
		valarray<float> naomi(n);
		for (int i=0; i<n; i++)
			cin >> naomi[i];
		sort(begin(naomi), end(naomi), std::greater<float>());
		valarray<float> ken(n);
		for (int i=0; i<n; i++)
			cin >> ken[i];
		sort(begin(ken), end(ken), std::greater<float>());
		cout << "Case #" << ti << ": " << solve(naomi, ken) << " " << (n - solve(ken, naomi)) << endl;
	}
	return 0;
}
