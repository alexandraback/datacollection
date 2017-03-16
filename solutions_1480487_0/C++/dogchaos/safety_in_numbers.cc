#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>
#include<algorithm>

using namespace std;
int N;
double s[201];


void solve()
{
	double total = 0;
	for (int i=0; i<N; i++) total += s[i];

	double rest = total;
	double p[201];
	for (int i=0; i<N; i++) p[i] = s[i];
	double average = total / N;
	sort(p, p+N);
	double av;
	if (p[N-1] <= 2*average) {
		av = 2*average;
	}
	else {
		for (int i=1; i<N; i++) {
			double d = p[i] - p[i-1];
			//cout << p[0] << " " << rest << endl;
			if (rest >= d*i) {
				for (int j=0; j<i; j++)
					p[j] = p[i];
				rest -= d*i;
				av = p[0];
			}
			else {
				av = p[0] + rest/(i);
				break;
			}
		}
	}
	//cout << av << endl;


	for (int i=0; i<N; i++) {
		if (s[i] < av) printf("%.6f ", (av - s[i])*100/total);
		else printf("%.6f ", 0.0);
	}


	cout << endl;
}


int main()
{
	int case_num;
	cin >> case_num;

	for (int t=1; t<=case_num; t++) {
		// initialization, IO
		cin >> N;
		for (int i=0; i<N; i++) cin >> s[i];

		cout << "Case #" << t << ": ";
		solve();

	}
}
