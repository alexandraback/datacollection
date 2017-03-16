#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int case_num = 0;
	double D;
	double a;
	int N;
	int A;
	double t[3001];
	double x[3001];	
	double speed[3001];

	cout.precision(12);

	cin >> case_num;
	for (int cn = 0; cn < case_num; cn++) {
		cin >> D;
		cin >> N;
		cin >> A;

		for (int i = 0; i < N; i++) {
			cin >> t[i];
			cin >> x[i];
		}
	
		for (int i = 0; i < N - 1; i++) {
			speed[i] = (x[i+1] -x[i]) / (t[i+1] - t[i]);
		}

		cout << "Case #" << cn + 1 << ":" << endl;
		for (int i = 0; i < A; i++) {
			cin >> a;
			double maxTime = sqrt(2.0 * D / a);
			if (N == 1) {
				cout << maxTime << endl;
			} else if (N >= 2) {
				double otherTime = (D - x[0]) / speed[0];
				cout << max(maxTime, otherTime) << endl;				
			}			
		}

	}
}

