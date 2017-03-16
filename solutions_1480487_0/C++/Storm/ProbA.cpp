#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q=0;q<z;q++) {

		int n;
		cin >> n;
		cout << "Case #" << (q+1) << ": ";

		vector<pair<int, int>> vals;
		int sum = 0;
		for (int i=0;i<n;i++) {
			int temp;
			cin >> temp;
			vals.push_back(make_pair(temp, i));
			sum += temp;
		}

		sort(vals.begin(), vals.end());
		vector<int> res(n,0);
		for (int i=0;i<n;i++) {
			for (int votes=0;votes <=sum; votes++) {
				int used = 0;
				for (int j=0;j<n;j++) {
					if (j == i) continue;
					int need = vals[i].first + votes - vals[j].first + 1;
					if (need > 0)
						used += need;
				}

				if (used + votes > sum) {
					res[vals[i].second] = votes;
					break;
				}
			}
		}

		cout.precision(6);
		cout.setf(ios::fixed, ios::floatfield);
		for (int i=0;i<n;i++) {
			cout << ((double) res[i] * 100) / sum;
			if (i+1 != n) cout << " ";
		}

		cout << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}