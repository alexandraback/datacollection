#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

bool check(vector<double> &J, int idx, double x)
{
	double y = J[idx] + x;
	
	double s = 0;
	for (int i = 0; i < J.size(); ++i) {
		if (i == idx) continue;
		if (J[i] < y) s += y - J[i];
	}
	
	if (s + x >= 100.0f) return true;
	else return false;
}

void solve(int case_no)
{
	int N;
	cin >> N;
	
	vector<double> J(N);
	int sj = 0;
	
	for (int i = 0; i < N; ++i) {
		cin >> J[i];
		sj += J[i];
	}
	for (int i = 0; i < N; ++i) {
		J[i] /= sj / 100.0f;
		//printf("J[%d] = %f\n", i, J[i]);
	}
	
	vector<double> ans(N);
	
	for (int i = 0; i < N; ++i) {
		double a = 0, b = 100;
		double c;
		
		while (b - a > 1e-10) {
			c = (a + b) / 2.0f;
			if (check(J, i, c) ) b = c;
			else a = c;
		}
		ans[i] = b;
	}
	
	printf("Case #%d:", case_no);
	for (int i = 0; i < N; ++i) {
		printf(" %.10f", ans[i]);
	}
	printf("\n");
	fflush(stdout);
	
	return;
	
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int i = 1; i <= T; ++i) {
		solve(i);
	}
	
	return 0;
}
