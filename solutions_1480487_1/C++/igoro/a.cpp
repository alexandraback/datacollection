#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>


using namespace std;


void main()
{
	//freopen("A.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);

    int cases;
    cin >> cases;

    for(int c=0; c<cases; c++) {
		int N;
		cin >> N;
		cout.precision(10);

		vector<double> v(N);
		double sum = 0;
		for(int i=0; i<N; i++) { cin >> v[i]; sum += v[i]; }
		for(int i=0; i<N; i++) { v[i] = v[i] / sum; }

		cout << "Case #" <<(c+1) << ":";

		int max = 0;
		for(int i=0; i<N; i++) {
			double lo = 0, hi = 1;
			for(int it=0; it<300; it++) {
				double mid = (lo+hi) / 2.0;

				double thisScore = v[i] + mid;
				double rem = 1.0 - mid;
				for(int j = 0; j < N; j++) if (j != i) {
					if (v[j] < thisScore) rem -= (thisScore - v[j]);
				}
				if (rem >= 0) lo = mid;
				else hi = mid;
			}
			printf(" %.10f", 100.0*lo);
		}

		cout << endl;
    }
}

