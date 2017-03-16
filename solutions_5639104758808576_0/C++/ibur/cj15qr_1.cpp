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
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((y) > (x) ? (x) : (y))
template <typename T>
void printvec(vector<T> v) {
	for(typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
}

void code(int t) {
	int Sm;
	cin >> Sm;
	string s;
	cin >> s;
	vector<int> shy(Sm+1, 0);
	for(int i = 0; i < s.size(); i++) {
		shy[i] = s[i] - '0';
	}

	int total = 0;
	int added = 0;
	for(int i = 0; i < Sm + 1; i++) {
		if(total < i && shy[i] != 0) {
			added += i - total;
			total += i - total;
		}
		total += shy[i];
	}

	cout << "Case #" << t << ": " << added << endl;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		code(t + 1);
	}
}

