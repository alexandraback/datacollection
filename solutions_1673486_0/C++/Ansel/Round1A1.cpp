#include <assert.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int 	A, B;
vector<double> probs;


double doit()
{
	vector<double> q(A+1, 1);
	for (int i = 1; i <= A; i++) {
		q[i] = q[i-1] * probs[i-1];
	}

	double cur_min = B + 2;

	double cur_e;
	for (int i = 0; i <= A; i++) {
		cur_e = 2*i;
		cur_e +=  B - A + 1;
		cur_e += (1- q[A-i]) * (B + 1);
		cur_min = min(cur_min, cur_e);
	}
	return cur_min;
}



int main() {
	int 	T;

	cin >> T;
	assert(T > 0 && T <= 100);

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		assert(A > 0 && B >= A);

		probs.resize(A);
		for (int j = 0; j < A; j++) {
			cin >> probs[j];
		}

		cout << "Case #" << i+1 << ": " ;
		printf ("%.6f\n", doit());
	}

	return 0;
}
