#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<ll> vll;

int main()
{	
	

	int t;
	cin >> t;
	int cas = 1;

	while (t--) {
		cout << "Case #" << cas << ":";
		cas++;

		int h[2501];
		for (int i = 0; i < 2501; i++) {
			h[i] = 0;
		}

		vi missing;

		int n;
		cin >> n;

		int total = (2 * n - 1) * n;

		for (int i = 0; i < total; i++) {
			int temp;
			cin >> temp;
			h[temp]++;
		}

		for (int i = 1; i <= 2500; i++) {
			if (h[i] % 2)
				missing.push_back(i);
		}

		sort(missing.begin(), missing.end());

		for (int i = 0; i < missing.size(); i++) {
			cout << " " << missing[i];
		}
		cout << endl;

	}
    return 0;
}
