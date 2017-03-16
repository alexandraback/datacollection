#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

int qsort(double* a, int s, int t) {
	int i,j;
	double k,m;
	i = s; j = t; k = a[(i+j)/2];
	do {
		while (a[i] < k) i++;
		while (a[j] > k) j--;
		if (i<=j) {
			m = a[i];
			a[i] = a[j];
			a[j] = m;
			i++;
			j--;
		}
	} while (i<=j);
	if (s<j) qsort(a,s,j);
	if (i<t) qsort(a,i,t);
	return 0;
}

int main() {
	ifstream input("D-large.in");
	ofstream output("ans.out");
	int t, n;
	double a[1000], b[1000];
	input >> t;
	for (int tt=0; tt<t; tt++) {
		input >> n;
		for (int i=0; i<n; i++) 
			input >> a[i];
		for (int i=0; i<n; i++)	
			input >> b[i];

		int ua[n], ub[n];
		for (int i=0; i<n; i++) {
			ua[i] = 0;
			ub[i] = 0;
		}
		qsort(a, 0, n-1);
		qsort(b, 0, n-1);

		int ans1 = 0, ans2 = 0;

		for (int i=0; i<n; i++) {
			bool flag = false;
			for (int j=0; j<n; j++) {
				if (a[i]<b[j] && ub[j]==0) {
					ub[j] = 1;
					ans2++;
					flag = true;
					break;
				}
			}
			if (!flag) {
				for (int j=0; j<n; j++) {
					if (ub[j]==0) {
						ub[j] = 1;
						break;
					}
				}
			}
		}

		for (int i=0; i<n; i++) {
			ua[i] = 0;
			ub[i] = 0;
		}

		for (int i=n-1; i>=0; i--) {
			bool flag = false;
			for (int j=n-1; j>=0; j--) {
				if (a[i]>b[j] && ub[j]==0) {
					ub[j] = 1;
					ans1++;
					flag = true;
					break;
				}
			}
			if (!flag)
				break;
		}

		output << "Case #" << tt+1 << ": " << ans1 << " " << n-ans2 << endl;
	}
}