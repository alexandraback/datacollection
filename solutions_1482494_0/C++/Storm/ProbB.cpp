#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
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

		vector<pair<int, int> > vals;
		for (int i=0;i<n;i++) {
			int x,y;
			cin >> x >> y;
			vals.push_back(make_pair(x,y));
		}

		sort(vals.begin(), vals.end());

		int lcount = 0;
		int stars = 0;
		vector<int> v1(n, false);
		vector<int> v2(n, false);
		int v2count = 0;
		while (v2count < n) {
			bool l2flag = false;
			for (int i=0;i<vals.size();i++) {
				if (!v2[i] && stars >= vals[i].second) {
					v2[i] = true;
					lcount++;
					stars += (2 - (v1[i] == true ? 1 : 0));
					l2flag = true;
					v2count++;
					break;
				}
			}

			if (l2flag) continue;

			int pos = -1;
			int lowl2 = -1;
			for (int i=0;i<n;i++) {
				if (!v1[i] && stars >= vals[i].first) {
					if (vals[i].second - vals[i].first > lowl2) {
						pos = i;
						lowl2 = vals[i].second - vals[i].first;
					}
				}
			}

			if (pos == -1) {
				break;
			}

			stars++;
			v1[pos] = true;
			lcount++;
		}

		cout << "Case #" << (q+1) << ": ";
		if (v2count < n) {
			cout << "Too bad" << endl;
		}
		else {
			cout << lcount << endl;
		}
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}