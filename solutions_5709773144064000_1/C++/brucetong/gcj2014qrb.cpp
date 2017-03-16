//Problem: Google Code Jam 2014 Qualification Round B
//Name: Cookie Clicker Alpha
//Author: Bruce K. B. Tong
//Tag: Greedy

#include <cstdio>
#include <iostream>

using namespace std;

//#define SMALL
#define LARGE

double solve(double C, double F, double X) {
	double rate = 2.0, time = 0.0, time1, time2;
	do {
		time1 = X/rate;
		time2 = C/rate + X/(rate+F);
		if (time1 < time2) {
			time += time1;
			break;
		}
		time += C/rate;
		rate += F;
	} while (1);
	return time;
}

int main() {
	freopen("B-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("B-small-attempt0.in", "rt", stdin);
		freopen("B-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("B-large.in", "rt", stdin);
		freopen("B-large.out", "wt", stdout);
	#endif

	int T;		//1 <= T <= 100
	double C;	//1 <= C <= 500 (or 10,000)
	double F;	//1 <= F <= 4 (or 100)
	double X;	//1 <= X <= 2,000 (or 100,000)
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> C >> F >> X;
		cout << "Case #" << i << ": ";
		printf("%f", solve(C, F, X));
		cout << endl;
	}
	return 0;
}