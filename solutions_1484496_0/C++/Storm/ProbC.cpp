#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int res;
int req_digits;
int a, b;

void rec(vector<int> &digits)
{
	if (digits.size() == req_digits) {
		int val = 0;
		for (int i=0;i<digits.size();i++) {
			val = 10 * val + digits[i];
		}

		if (val < a || val > b) return;
		for (int i=1;i<digits.size();i++) {
			int val2 = 0;
			for (int j=0;j<digits.size();j++) {
				int digit = digits[(i + j) % digits.size()];
				if (val2 == 0 && digit == 0) break;
				val2 = 10 * val2 + digit;
			}

			if (val2 >= a && val2 <= b && val2 != val)
				res++;
		}
	}
	else {
		int start = (digits.empty() ? 1 : digits[digits.size() - 1]);
		digits.push_back(start);
		for (int i = start;i<10;i++) {
			digits[digits.size()-1] = start;
			rec(digits);
		}
	}
}

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		map<long long, long long> m;
		set<long long> used;
		int n;
		cin >> n;
		vector<long long> vals(n);
		for (int i=0;i<n;i++) {
			cin >> vals[i];
		}
		
		cout << "Case #" << (q+1) << ": ";
		bool found = false;
		for (int i=0;i<n;i++) {
			if (used.find(vals[i]) != used.end()) {
				cout << endl << vals[i] << endl;
				long long start = vals[i];
				while (start != 0) {
					cout << start - m[start] << " ";
					start = m[start];
				}

				cout << endl;

				// Found
				found = true;
				break;
			}

			set<long long> newvals;
			for (set<long long>::iterator iter = used.begin();iter!=used.end();iter++) {
				long long pos = *iter + vals[i];
				if (used.find(pos) != used.end()) {
					cout << endl;
					cout << vals[i] << " ";
					long long start = *iter;
					while (start != 0) {
						cout << start - m[start] << " ";
						start = m[start];
					}
					cout << endl;

					start = *iter + vals[i];
					while (start != 0) {
						cout << start - m[start] << " ";
						start = m[start];
					}
					cout << endl;
					found = true;
					break;
				}
				else {
					newvals.insert(pos);
					m[pos] = *iter;
				}
			}

			if (found) break;
			used.insert(vals[i]);
			m[vals[i]] = 0;
			for (set<long long>::iterator iter = newvals.begin();iter!=newvals.end();iter++) {
				used.insert(*iter);
			}
		}

		if (!found) {
			cout << "Impossible" << endl;
		}
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}