#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

double PI = acos(-1.0);
double EPS = 1e-9;
int INF = 2000000000;

#define FOR(i, a, b) for (int i = a; i < b; i++)

template <typename Type>
void print_array(Type arr, int start, int end) {
	cout << "[";
	FOR(i, start, end) {
		cout << arr[i] << ", ";
	}
	cout << "]" << endl;
}

template <typename Type>
void print_vector(vector<Type> v) {
	cout << "[";
	FOR(i, 0, v.size()) {
		cout << v[i] << ", ";
	}
	cout << "]" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// END OF HEADER

	freopen("1a-a.in", "r", stdin);
	freopen("1a-a.res", "w", stdout);

	int testcases;
	cin >> testcases;

	for (int cse = 1; cse <= testcases; cse++) {
		// END OF CODE JAM HEADER

		string str;
		cin >> str;

		string res;
		FOR (i, 0, str.length()) {
			if (i == 0) {
				res = str[i];
			} else {
				if ((char) res[0] <= (char) str[i]) {
					res = str[i] + res;
				} else {
					res = res + str[i];
				}
			}
		}

		// START OF CODE JAM FOOTER
		cout << "Case #" << cse << ": " << res << endl;
	}
}
// END OF CODE JAM FOOTER
