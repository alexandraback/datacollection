#include <iostream>
#include <vector>
using namespace std;

int testcases;
int n;

int main() {
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		cin >> n;
		vector<int> a;
		int o = 0; 
		for (int i = 0; i < n; i ++) {
			int num;
			cin >> num;
			if (num > o) o = num;
			a.push_back(num);
		}
		for (int i = 1; i < o; i ++) {
			int now = 0;
			for (int j = 0; j < n; j ++) {
				now += (a[j] - 1) / i;
			}
			now += i;
			if (now < o) o = now;
		}
		cout << "Case #" << testcase + 1 << ": " << o << endl;
	}

	return 0;
}