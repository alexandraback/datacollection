#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int case_nr, T;

	cin >> T;

	for (case_nr=1; case_nr<=T; case_nr++) {
		cout << "Case #" << case_nr << ": ";
		
		int N;
		cin >> N;
		vector<int> s(N), s_sorted;
		for (int i=0; i<N; i++)
			cin >> s[i];
		
		s_sorted = s;
		sort(s_sorted.begin(), s_sorted.end());
		int X = accumulate(s.begin(), s.end(), 0);
		
		vector<double> res(N);
		for (int i=0; i<N; i++)
			res[i] = 100.0 * (2.0*X/N - s[i]) / X;
			
		for (int i=0; i<N; i++)
			if (res[i] < 0) {
				int ile=0;
				for (int j=0; j<N; j++)
					if (res[j] > 0)
						ile++;
				
				for (int j=0; j<N; j++)
					if (res[j] > 0)
						res[j]+=res[i]/ile;
				
				res[i] = 0;
			}
		
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(6);
		for (int i=0; i<N; i++)
			cout << res[i] << " ";
		cout << endl;
	}
}
