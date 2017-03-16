#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

const int SIZE = 10000;
const int OFFSET = SIZE / 2;
int wall[SIZE];
int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	
	for (int q=0;q<z;q++) {
		for (int i=0;i<SIZE;i++) {
			wall[i] = 0;
		}

		int n;
		cin >> n;

		vector<pair<int, int> > attacks;
		vector<int> west(n, 0);
		vector<int> east(n, 0);
		vector<int> d_dir(n, 0);
		vector<int> strength(n, 0);
		vector<int> d_strength(n, 0);
		for (int i=0;i<n;i++) {
			int d, n, w, e, dd, dp;
			cin >> d >> n >> west[i] >> east[i] >> strength[i] >> dd >> d_dir[i] >> d_strength[i];
			for (int j=0;j<n;j++) {
				attacks.push_back(make_pair(d + dd * j, i));
			}
		}

		sort(attacks.begin(), attacks.end());
		int count = 0;
		for (int i=0;i<attacks.size();i++) {
			int j = 0;
			do {
				int tribe = attacks[i+j].second;
				for (int pos = 2 * west[tribe];pos<=2 *east[tribe];pos++) {
					if (wall[pos + OFFSET] < strength[tribe]) {
						count++;
						break;
					}
				}
				j++;
			} while (i + j < attacks.size() && attacks[i+j].first == attacks[i].first);

			for (int k=0;k<j;k++) {
				int tribe = attacks[i+k].second;
				for (int pos = 2 * west[tribe];pos<=2 * east[tribe];pos++) {
					if (wall[pos + OFFSET] < strength[tribe])
						wall[pos + OFFSET] = strength[tribe];
				}

				strength[tribe] += d_strength[tribe];
				west[tribe] += d_dir[tribe];
				east[tribe] += d_dir[tribe];
			}
			i += j - 1;
		}

		cout << "Case #" << (q+1) << ": " << count << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}