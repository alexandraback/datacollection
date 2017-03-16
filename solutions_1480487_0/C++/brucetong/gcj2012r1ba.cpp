//Problem: GCJ 2012 Round 1B A
//Name: Safety in Numbers
//Author: Bruce K. B. Tong

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <list>

using namespace std;

#define SMALL
//#define LARGE

#define SIZE 200

#define INF 1.0E+15	//for double
#define a1d(a, n) for(int i=0; i<(int)(n); i++) {cout << a[i]; cout << endl;} cout << endl;
#define a2d(a, h, w) for(int i=0; i<(int)(h); i++) {for(int j=0; j<(int)(w); j++) cout << a[i][j]; cout << endl;}
#define lf(it,l) for(it=l.begin(); it!=l.end(); ++it) {cout << *it << " ";} cout << endl;
#define lr(rit,l) for(rit=l.rbegin(); rit!=l.rend(); ++rit) {cout << *rit << " ";} cout << endl;
#define mem(a,b) memset(a,b,sizeof(a))

void read(int &N, int s[SIZE]) {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i];
}

void compute(int N, int s[SIZE]) {
	int wrong[SIZE] = {0};
	int haswrong = 0;
	double minvotes[SIZE];
	double v = 0;

	int sum = 0;
	double s2[SIZE];
	double s2max = -1;
	for (int i = 0; i < N; i++)
		sum += s[i];
	for (int i = 0; i < N; i++) {
		s2[i] = (double)s[i] / sum;
		if (s2[i] > s2max) s2max = s2[i];
	}
	
	double c = 0;
	for (int i = 0; i < N; i++)
		c += s2max - s2[i];
	double y0 = (1 - c)/N;
	haswrong = 0;
	for (int i = 0; i < N; i++) {
		minvotes[i] = s2max - s2[i] + y0;
		if (minvotes[i] < 0) {
			v += minvotes[i];
			minvotes[i] = 0.0;
			wrong[i] = 1;
			haswrong++;
		}
	}
	if (haswrong > 0) {
		double offset = v / (N - haswrong);
		for (int i = 0; i < N; i++)
			if (!wrong[i])
				minvotes[i] += offset;
	}
	for (int i = 0; i < N; i++)
		printf("%f ", minvotes[i]*100);
}

int main() {
	freopen("A-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("A-small-attempt2.in", "rt", stdin);
		freopen("A-small-attempt2.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("A-large.in", "rt", stdin);
		freopen("A-large.out", "wt", stdout);
	#endif

	int T;					//1 <= T <= 100
	int N;					//2 <= N <= 10 (or 200)
	int s[SIZE];			//0 <= s[i] <= 100
	
	cin >> T;

	for (int i = 1; i <= T; i++) {
		read(N, s);
		cout << "Case #" << i << ": ";
		compute(N, s);
		cout << endl;
	}
	
	return 0;
}