#include <iostream>
#include "Debug.h"
using namespace std;

#define ABS(x) (((x)>0)?(x):(-x))
#define MAX(x, y) (((x)>(y))?(x):(y))
#define MIN(x, y) (((x)<(y))?(x):(y))

typedef long long integer;

int I, T;
integer E, R;
int N;
integer* value;
integer* maxes;
integer gain;

void clean() {
	delete [] value;
	delete [] maxes;
}

void print() {
	cout << "Case #" << I << ": " << gain << endl;
	cerr << "\r" << I << "/" << T << endl;
}

void read() {
	cin >> E >> R >> N;
	value = new integer [N];
	maxes = new integer [N];
	for (int i = 0; i<N; i++) {
		cin >> value[i];
		maxes[i] = -1;
	}
}

integer solve_aux_2(int s, integer e) {
	if (s==N) return 0;
	integer max = -1;
	for (int i = 0; i<=e; i++) {
		integer c = MIN(E, i+R);
		integer t = solve_aux_2(s+1, c)+(e-i)*value[s];;
		if (t>max) {
			max = t;
		}
	}
	return max;
}


integer solve_aux(int s, integer e) {
	if (s==N) return 0;
	integer c;
	if (value[s]==maxes[s]) {
		c = MIN(E, R);
		return solve_aux(s+1, c)+e*value[s];
	} else {
		if (e>=R) {
			c = MIN(E, e);
			return solve_aux(s+1, c)+R*value[s];
		} else {
			c = MIN(E, R);
			return solve_aux(s+1, c)+e*value[s];
		}
	}
	return 0;
}

void compute_maxes() {
	for (int i = 0; i<N; i++) {
		integer m = -1;
		for (int j = i; j<N; j++) {
			if (value[j]>m) {
				m = value[j];
			}
		}
		maxes[i] = m;
	}
}

void solve() {
	compute_maxes();
	gain = solve_aux_2(0, E);
}

void main() {
	cin >> T;
	I = 0;
	while (I++<T) {
		read();
		solve();
		print();
		clean();
	}
}