#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	
	for (int q=0;q<z;q++) {
		int r, n, m, k;
		cin >> r >> n >> m >> k;

		cout << "Case #" << (q+1) << ": " << endl;

		for (int p=0;p<r;p++) {
			vector<int> count(6, 0);
			vector<int> prob(6, 0);
			vector<int> vals(k);
			for (int i=0;i<k;i++) {
				cin >> vals[i];
			}

			for (int i=0;i<vals.size();i++) {
				int v = vals[i];
				if (v % 125 == 0) {
					count[5] = 3;
					prob[5]++;
				}
				else if (v % 25 == 0) {
					count[5] = 2;
					prob[5]++;
				}
				else if (v % 5 == 0) {
					count[5] = 1;
					prob[5]++;
				}				

				if (v % 27 == 0) {
					count[3] = 3;
					prob[3]++;
				}
				else if (v % 9 == 0) {
					count[3] = 2;
					prob[3]++;
				}
				else if (v % 3 == 0) {
					count[3] = 1;
					prob[3]++;
				}

				if (v % 64 == 0) {
					count[4] = 3;
					prob[4]++;
				}
				else if (v % 16 == 0) {
					count[4] = 2;
					prob[4]++;
				}
				else if (v % 4 == 0) {
					prob[4]+=2;
					prob[2]++;
				}

				if (v == 2) {
					count[2] = 1;
					prob[2]++;
				}
				if (v == 8) {
					count[2] = 1;
					prob[2]++;
				}
			}

			vector<int> res;
			for (int i=0;i<count.size();i++) {
				for (int j=0;j<count[i];j++) {
					res.push_back(i);
				}
			}

			while (res.size() < 3) {
				vector<int>::iterator max_prob = max_element(prob.begin(), prob.end());
				if (*max_prob == 0) {
					res.push_back(2 + rand() % 4);
					continue;
				}
				int num = max_prob - prob.begin();
				if (num == 2 && prob[2] <= prob[4]) {
					prob[2]--;
					continue;
				}

				int val = *max_prob - 2 * count[num];
					count[num]++;
					res.push_back(num);
					prob[num] = max(1, val / 2);
				
			}

			for (int i=0;i<res.size();i++) {
				cout << res[i];
			}
			cout << endl;
		}
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}