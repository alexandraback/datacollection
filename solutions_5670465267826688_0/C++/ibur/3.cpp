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

struct quat {
	int val;
	int sign;

	quat(char c) {
		switch(c) {
		case 'i': val = 1; break;
		case 'j': val = 2; break;
		case 'k': val = 3; break;
		default: val = 0; break;
		}
		sign = 1;
	}

	quat(int v, int s) : val(v), sign(s) {}

	quat operator*(const quat &o) const {
		if(val == 0) {
			return quat(o.val, o.sign * sign);
		}
		if(o.val == 0) {
			return quat(val, o.sign * sign);
		}
		if(val == o.val) {
			return quat(0, -1 * o.sign * sign);
		}

		int v;
		int s = 1;
		switch(val) {
		case 1:
			switch(o.val) {
			case 2:
				v = 3; break;
			case 3:
				v = 2; s = -1; break;
			}
			break;
		case 2:
			switch(o.val) {
			case 1:
				v = 3; s = -1; break;
			case 3:
				v = 1; break;
			}
			break;
		case 3:
			switch(o.val) {
			case 1:
				v = 2; break;
			case 2:
				v = 1; s = -1; break;
			}
			break;
		}

		return quat(v, s * sign * o.sign);
	}

	bool operator==(const quat &o) const {
		return val == o.val && sign == o.sign;
	}
};

string code() {
	intt L, X;
	cin >> L >> X;
	string s;
	cin >> s;

	quat I('i');
	quat J('j');
	quat K('k');

	vector<quat> vals(L, quat(0,1));
	for(int i = 0; i < L; i++) {
		vals[i] = quat(s[i]);
	}

	quat cumul(0,1);
	vector<quat> cb(L, quat(0,1));
	quat cur = quat(0, 1);

	for(int i = 0; i < L; i++) {
		cur = cur * vals[i];
	}
	cumul = cur;

	cur = quat(0, 1);
	for(int i = L - 1; i >= 0; i--) {
		cur = vals[i] * cur;
		cb[i] = cur;
	}

	int ix, il;
	cur = quat(0, 1);
	for(ix = 0; ix < 4; ix++) {
		for(il = 0; il < L; il++) {
			cur = cur * vals[il];
			if(cur == I) goto iend;
		}
	}
	return "NO";
	iend:;
	if(ix >= X) {
		return "NO";
	}

	cur = quat(0, 1);
	int jx, jl;
	jl = il + 1;
	jx = ix;
	for(; jl < L; jl++) {
		cur = cur * vals[jl];
		if(cur == J) goto jend;
	}
	for(jx = ix + 1; jx < ix + 4; jx++) {
		for(jl = 0; jl < L; jl++) {
			cur = cur *vals[jl];
			if(cur == J) goto jend;
		}
	}
	for(jl = 0; jl <= il; jl++) {
		cur = cur * vals[jl];
		if(cur == J) goto jend;
	}
	return "NO";
	jend:;
	if(jx >= X) {
		return "NO";
	}

	cur = jl == L-1 ? quat(0, 1) : cb[jl + 1];
	for(int i = 0; i < (X - jx - 1) % 4; i++) {
		cur = cur * cumul;
	}

	return cur == K ? "YES" : "NO";
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		cout << "Case #" << (t + 1) << ": " << code() << endl;
	}
}

