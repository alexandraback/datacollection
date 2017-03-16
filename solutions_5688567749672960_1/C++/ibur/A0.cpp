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

intt pow10(int e) {
	intt a = 1;
	for(int i = 0; i < e; i++) {
		a *= 10;
	}
	return a;
}

intt m[1000001];

void populate() {

	for(int i = 1; i < 1000001; i++) {
		m[i] = INT_MAX;
	}
	m[1] = 1;
	for(int i = 1; i <= 1000000; i++) {
		m[i + 1] = min(m[i] + 1, m[i+1]);
		if(reverse(i) <= 1000000)
			m[reverse(i)] = min(m[i]+1, m[reverse(i)]);
	}
}

void code() {
	intt N;
	cin >> N;
	intt steps = 0;
	if(N % 10 == 0) {
		N--;
		steps++;
	}
	while(N > 1000000) {
		int size = to_string(N).size() - 1;
		intt target = N - N % pow10((size + 1) / 2) + 1;
		if((size + 1) % 2 == 1 && ((N - N % pow10((size + 2) / 2)) == pow10(size))) {
			steps += N - pow10(size);
			steps++;
			N = pow10(size) - 1;
		} else {
		steps += N - target;
		if(target != pow10(size) + 1) {
			steps++;
			N = reverse(target);
			target = pow10(size);
			steps += N - target;
			steps++;
			N = target - 1;
		} else {
			steps+=2;
			N = target - 2;
		}
		}
	}

	cout << steps + m[N] << endl;
}

int main(int argc, char **argv) {
	populate();
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		code();
	}
}

