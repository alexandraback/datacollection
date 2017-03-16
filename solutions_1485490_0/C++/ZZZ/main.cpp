#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

#include <iomanip>
#include <algorithm>

using namespace std;

#define N 101
#define M 101

double a[N], A[N], b[N], B[N];

int n, m;

double min(double a, double b) {
	return a < b ? a: b;
}
double max(double a, double b) {
	return a < b ? b: a;
}
double dp(int c, int cn, int cm) {
	if(cn < 0 || cm < 0)
		return 0;
	if(c == 1) {
		for(int i = cm; i >= 0; --i) {
			if(A[cn] == B[i]) {	
		//		cout << c << ":" << cn << " " << i << endl;
		//		cout << min(a[cn], b[i]) << endl;
				return min(a[cn], b[i]) + max(max(dp(0, cn-1, i-1), dp(1, cn-1, i-1)), max(dp(2, cn-1, i-1), dp(3, cn-1, i-1)));
			}
		}
	}
	else if(c == 0){
		for(int i = cn; i >= 0; --i) {
			if(B[cm] == A[i]) {
			//	cout << c << ":" <<  i << " " << cm << endl;
				//cout << min(a[i], b[cm]) << endl;
				return min(a[i], b[cm]) + max(max(dp(0, i-1, cm-1), dp(1, i-1, cm-1)), max(dp(2, i-1, cm-1), dp(3, i-1, cm-1)));
			}
		}
	}
	else if(c == 2) {
	//	cout << "HI" << endl;
		return max(max(dp(0, cn-1, cm), dp(1, cn-1, cm)), max(dp(2, cn-1, cm), dp(3, cn-1, cm)));
	}
	else if(c == 3) {
	//	cout << "hELL" << endl;
		return max(max(dp(0, cn, cm-1), dp(1, cn, cm-1)), max(dp(2, cn, cm-1), dp(3, cn, cm-1)));
	}
	return 0;
}


int main() {
	int i, j, k;
	int t;
	freopen("D://data.in", "r", stdin);
	freopen("D://data.out", "w", stdout);

	cin >> t;
	int c;
	for(c = 0; c < t; ++c)
	{
		cin >> n >> m;
		
		for(i = 0; i < n; ++i) {
			cin >> a[i] >> A[i];
		}
		for(i = 0; i < m; ++i) {
			cin >> b[i] >> B[i];
		}

		double mm = max(max(dp(0, n-1, m-1), dp(1, n-1, m-1)), max(dp(2, n-1, m-1), dp(3, n-1, m-1)));

		printf("Case #%d: %.0f\n", c+1, mm);
	}

	return 0;
}