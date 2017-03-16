#include <iostream>
#include "Debug.h"
using namespace std;

#define ABS(x) (((x)>0)?(x):(-x))
#define MAX(x, y) (((x)>(y))?(x):(y))
#define MIN(x, y) (((x)<(y))?(x):(y))

typedef int integer;

int I, T;
int E, R, N;
int* value;
int* plan;
int gain;
int total;

void clean() {
	delete [] value;
	delete [] plan;
}

void print() {
	cout << "Case #" << I << ": " << gain << endl;
}

void read() {
	cin >> E >> R >> N;
	value = new int [N];
	plan = new int [N];
	for (int i = 0; i<N; i++) {
		cin >> value[i];
		plan[i] = 0;
	}
}

int solve_aux(int s, int e) {
	if (s==N) return 0;
	int max = -1;
	for (int i = 0; i<=e; i++) {
		int c = MIN(E, i+R);
		int t = solve_aux(s+1, c)+(e-i)*value[s];;
		if (t>max) {
			max = t;
		}
	}
	return max;
}

void solve() {
	gain = solve_aux(0, E);
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