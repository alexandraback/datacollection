#include <iostream>

using namespace std;

int main() {
	int test_num;
	cin >> test_num;
	for(int Case = 1;Case <= test_num;Case++) {
		int n;
		cin >> n;

		cout << "Case #" << Case << ": ";
		if(n == 0) {
			cout << "INSOMNIA" << "\n";
			continue;
		}

		int found[10];
		for(int i = 0;i < 10;i++) {
			found[i] = 0;
		}

		for(int i = n;true;i += n) {
			for(int val = i;val > 0;val /= 10) {
				found[val % 10] = 1;
			}
			int err = false;
			for(int i = 0;i < 10;i++) {
				if(not found[i]) {
					err = true;
				}
			}
			if(not err) {
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}