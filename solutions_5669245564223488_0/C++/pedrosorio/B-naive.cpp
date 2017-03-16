#include <vector>
#include <iostream>

using namespace std;

int last[256];

int is_valid(vector<int> &perm, vector<string> &cars) {
	for(int i = 'a'; i <= 'z'; i++) {
		last[i] = -1;
	}
	int ct = 0;
	int N = perm.size();
	for (int car = 0; car < N; car++) {
		int carp = perm[car];
		for (int i = 0; i < cars[carp].size(); i++) {
			int c = cars[carp][i];
			if (last[c] != -1 && last[c] != ct-1) {
				return 0;
			}
			last[c] = ct++;
		}
	}
	return 1;
}

int main() {
	int T;
	cin >> T;
	for (int cs = 1; cs <= T; cs++) {
		int N;
		cin >> N;
		vector<int> perm(N);
		vector<string> cars(N);
		for (int i = 0; i < N; i++) {
			perm[i] = i;
			cin >> cars[i];
		}
		int ct = 0;
		do {
			ct += is_valid(perm, cars);
		} while(next_permutation(perm.begin(), perm.end()));
		cout << "Case #" << cs << ": " << ct << endl;
	}
	return 0;
}