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

		cin >> a >> b;

		req_digits = 0;
		int temp = a;
		int first = 0;
		while (temp > 0) {
			first = temp;
			temp /= 10;
			req_digits++;
		}

		res = 0;

		//vector<int> digits;
		//rec(digits);

		res = 0;
		set<pair<int, int> > s;
		for (int i=a;i<b;i++) {
			int mask = 10;
			int rmask = pow(10.0, req_digits - 1);
			for (int j=1;j<req_digits;j++) {
				int sep = i % mask;
				int dcount=0;
				while (sep > 0) {
					sep /= 10;
					dcount++;
				}

				if (dcount >= j) {
					int m = (i % mask) * rmask + (i / mask);
					if (i < m && m >= a && m <= b) {
						pair<int, int> p = make_pair(i, m);
						s.insert(p);
					}
				}

				mask *= 10;
				rmask /= 10;
			}
		}

		//cout << s.size() << endl;
		cout << "Case #" << (q+1) << ": " << s.size() << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}