#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <string.h>

using namespace std;

#define pb pus_back
#define sz(v) ((int)v.size())
#define mp make_pair

vector <double> score;
double sum = 0;
int N;

int isok(int n, double proc) {
	double p = 0;
	for (int i = 0; i < N; ++i) {
		if (i == n)
			continue;
		p += max((score[n] + sum * proc - score[i]) / sum, 0.);
	}
	return (p + proc) > 1.;
}
		

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cout.precision(9);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d:",t);
		score.clear();
		
		cin >> N;
		score.resize(N);
		sum = 0;
		for (int i = 0; i < N; ++i) {
			cin >> score[i];
			sum += score[i];
		}
		for (int i = 0; i < N; ++i) {
			double a = 0,
				b = 1;
			for (int tr = 0; tr < 50; ++tr) {
				double m = (a + b) / 2;
				if (isok(i, m))
					b = m;
				else
					a = m;
			}
			cout << " " << 100 * a;
		}
		cout << "\n";
	}

	return 0;
}