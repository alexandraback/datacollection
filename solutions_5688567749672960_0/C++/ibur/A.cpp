#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <climits>
#include <stdint.h>
#include <utility>
#include <set>
#include <stack>
#define DEBUG 0
#define LOG if(DEBUG)
using namespace std;
typedef int64_t intt;
#define MAX_VAL	LLONG_MAX 
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((y) > (x) ? (x) : (y))
template <typename T>
void printvec(vector<T> v) {
	for(typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
}

intt reverse(intt a) {
	string s = to_string(a);
	reverse(s.begin(), s.end());
	return atol(s.c_str());
}

void code() {
	int N;
	cin >> N;
	vector<int> m(N + 1, INT_MAX);
	m[1] = 1;
	for(int i = 1; i <= N; i++) {
		m[i + 1] = min(m[i] + 1, m[i+1]);
		if(reverse(i) <= N)
			m[reverse(i)] = min(m[i]+1, m[reverse(i)]);
	}
	cout << m[N] << endl;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		code();
	}
}

