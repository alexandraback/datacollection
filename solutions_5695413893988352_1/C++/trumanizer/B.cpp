#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <climits>
#include <sstream>
#define abs_diff(a, b) ((a > b) ? (a - b) : (b - a))
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

unsigned long eval(const vector<int> & num) {
	unsigned long res = 0, mag = 1;
	for (int i = num.size() - 1; i >= 0; i--) {
		res += mag * num[i];
		mag *= 10;
	}
	return res;
}

char C[20], J[20];

class NumPair {
public:
	vector<int> first;
	vector<int> second;
	int tag;

	NumPair() : tag(0) {}
};

void solve(int test)
{
	cin >> C >> J;
	int n = strlen(C);

	deque<NumPair> frontier(1);
	for (int i = 0; i < n; i++) {
		int m = frontier.size();
		for (int j = 0; j < m; j++) {
			NumPair pair = frontier.front();
			frontier.pop_front();
			pair.first.push_back(0);
			pair.second.push_back(0);
			if (C[i] == '?' && J[i] == '?') {
				if (pair.tag == 1) {
					pair.first[i] = 0; pair.second[i] = 9; frontier.push_back(pair);
				}
				else if (pair.tag == 2) {
					pair.first[i] = 9; pair.second[i] = 0; frontier.push_back(pair);
				}
				else {
					pair.first[i] = pair.second[i] = 0; frontier.push_back(pair);
					pair.first[i] = 0; pair.second[i] = 1; pair.tag = 2; frontier.push_back(pair);
					pair.first[i] = 1; pair.second[i] = 0; pair.tag = 1; frontier.push_back(pair);
				}
			} else if (C[i] == '?') {
				pair.second[i] = J[i] - '0';
				if (pair.tag == 1) {
					pair.first[i] = 0; frontier.push_back(pair);
				} else if (pair.tag == 2) {
					pair.first[i] = 9; frontier.push_back(pair);
				} else {
					pair.first[i] = J[i] - '0'; frontier.push_back(pair);
					if (J[i] == '9') {
						pair.first[i] = 8; pair.tag = 2; frontier.push_back(pair);
					} else if (J[i] == '0') {
						pair.first[i] = 1; pair.tag = 1; frontier.push_back(pair);
					} else {
						pair.first[i] = (J[i] - '0' - 1); pair.tag = 2; frontier.push_back(pair);
						pair.first[i] = (J[i] - '0' + 1); pair.tag = 1; frontier.push_back(pair);
					}
				}
			} else if (J[i] == '?') {
				pair.first[i] = C[i] - '0';
				if (pair.tag == 1) {
					pair.second[i] = 9; frontier.push_back(pair);
				} else if (pair.tag == 2) {
					pair.second[i] = 0; frontier.push_back(pair);
				} else {
					pair.second[i] = C[i] - '0'; frontier.push_back(pair);
					if (C[i] == '9') {
						pair.second[i] = 8; pair.tag = 1; frontier.push_back(pair);
					} else if (C[i] == '0') {
						pair.second[i] = 1; pair.tag = 2; frontier.push_back(pair);
					} else {
						pair.second[i] = (C[i] - '0' - 1); pair.tag = 1; frontier.push_back(pair);
						pair.second[i] = (C[i] - '0' + 1); pair.tag = 2; frontier.push_back(pair);
					}
				}
			} else {
				pair.first[i] = C[i] - '0'; pair.second[i] = J[i] - '0';
				if (pair.tag == 0) {
					if (pair.first[i] > pair.second[i]) pair.tag = 1;
					else if (pair.first[i] < pair.second[i]) pair.tag = 2;
				}
				frontier.push_back(pair);
			}
		}
	}

	unsigned long delta = ULONG_MAX;
	unsigned long A, B;
	int remainA, remainB;
	for (NumPair pair : frontier) {
		unsigned long a = eval(pair.first);
		unsigned long b = eval(pair.second);
		unsigned long d = abs_diff(a, b);
		if (d < delta) {
			delta = d;
			A = a; B = b;
		} else if (d == delta) {
			if (a < A) {
				A = a;
				B = b;
			} else if (a == A && b < B) {
				A = a;
				B = b;
			}
		}
	}

	string a = SSTR(A);
	string b = SSTR(B);
	cout << "Case #" << test << ": ";
	for (int i = 0; i < n - a.size(); i++) cout << "0";
	cout << a << " ";
	for (int i = 0; i < n - b.size(); i++) cout << "0";
	cout << b << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++)
		solve(i + 1);	
}