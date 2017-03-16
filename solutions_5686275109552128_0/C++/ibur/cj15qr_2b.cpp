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

int mintime[1001][1001];
int m[1001];

void code(int t) {
	int D;
	cin >> D;
	vector<int> diners(D, 0);
	for(int i = 0; i < D; i++) {
		cin >> diners[i];
	}

	sort(diners.begin(), diners.end(), greater<int>());
	int best = INT_MAX;
	for(int j = diners[0]; j >= 1; j--) {
		int time = 0;
		for(int i = 0; i < D; i++) {
			time += mintime[diners[i]][j];
		}
		best = MIN(best, time + j);
	}

	cout << "Case #" << t << ": " << best << endl;
}

int main(int argc, char **argv) {
	for(int i = 1; i <= 1000; i++) {
		m[i] = INT_MAX;
		for(int j = 1; j <= i; j++) {
			mintime[i][j] = (i + j - 1) / j - 1;
			m[i] = MIN(m[i], mintime[i][j] + j);
		}
		for(int j = i + 1; j <= 1000; j++) {
			mintime[i][j] = 0;
		}
	}
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		code(t + 1);
	}
}

