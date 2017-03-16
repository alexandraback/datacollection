#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int computeCase(int initial, vector<int> &weights) {
	if (initial == 1)
		return weights.size();

	sort(weights.begin(), weights.end());

	// maintain table: each number of operations,
	// what is the greatest possible mote size?
	map<int, int> opsToSize;
	opsToSize[0] = initial;

	for(int i=0; i<weights.size(); i++) {
		map<int, int> newOpsToSize;

		int neededSize = weights[i];
		for(map<int, int>::iterator it = opsToSize.begin(); it != opsToSize.end(); it++) {
			int curSize = it->second;
			int extra = max(0, neededSize + 1 - curSize);

			bool easy = (extra == 0);

			int sizeAfterAdd = curSize;
			int numToGrow = 0;
			while (extra > 0) {
				numToGrow++;
				sizeAfterAdd += sizeAfterAdd - 1;
				extra = max(0, neededSize + 1 - sizeAfterAdd);
			}

			// update
			int curOps = it->first;

			if (easy) {
				newOpsToSize[curOps] = max(newOpsToSize[curOps], curSize + neededSize);
			}
			else {
				newOpsToSize[curOps + 1] = max(newOpsToSize[curOps + 1], curSize);
				newOpsToSize[curOps + numToGrow] = max(newOpsToSize[curOps + numToGrow], sizeAfterAdd + neededSize);
			}
		}

		opsToSize = newOpsToSize;

		for(map<int, int>::iterator it = opsToSize.begin(); it != opsToSize.end(); it++) {
			// cout << "ops: " << it->first << " size: " << it->second << endl;
			break;
		}

	}

	for(map<int, int>::iterator it = opsToSize.begin(); it != opsToSize.end(); it++) {
		return it->first;
	}

	return -1;
}

int main() {
	int T;
	cin >> T;

	for(int i=1; i<=T; i++) {
		int initial, N;
		cin >> initial >> N;

		vector<int> moteSizes(N, 0);

		for(int j=0; j<N; j++) {
			cin >> moteSizes[j];
		}

		cout << "Case #" << i << ": " << computeCase(initial, moteSizes) << endl;
	}

	return 0;
}
