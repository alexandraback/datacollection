#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <deque>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

double tot_dist;
double t[10];
double x[10];
int N, A;

double speed;

void getInput();
double getResult(double n);

int main() {
	cout << fixed << setprecision(7);
	//freopen("B-small-attempt0.in", "r", stdin); freopen("b-small0.out", "w", stdout);
	freopen("B-small-attempt1.in", "r", stdin); freopen("b-small1.out", "w", stdout);
	//freopen("B-small-attempt2.in", "r", stdin); freopen("b-small2.out", "w", stdout);
	//freopen("B-small-attempt3.in", "r", stdin); freopen("b-small3.out", "w", stdout);
	//freopen("B-large.in", "r", stdin); freopen("b-large.out", "w", stdout);

	int cases;
	cin >> cases;
	cin.ignore();
	for (int cnt = 1; cnt <= cases; cnt++) {		
		cout << "Case #" << cnt << ":" << endl;
		getInput();
	}

	return 0;
}

void getInput() {
	cin >> tot_dist >> N >> A;

	for (int i = 0; i < N; i++)
		cin >> t[i] >> x[i];

	while (A--) {
		double x;
		cin >> x;
		cout << getResult(x) << endl;
	}
}

double getResult(double n) {
	double temp = sqrt(tot_dist * 2 / n);

	if (N == 1)
		return temp;

	double speed = (x[1] - x[0]) / (t[1] - t[0]);
	double dist = x[0] + speed * temp;

	if (dist >= tot_dist)
		return temp;

	return (tot_dist - x[0]) / speed;
}
