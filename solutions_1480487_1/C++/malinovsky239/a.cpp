#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef long double LD;

#define pb push_back
#define mp make_pair
#define sz(A) (int)(A).size()

const int N = 205;

int s[N];

int main() {
	int t;
	cout.precision(5);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, sum = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> s[j];
			sum += s[j];
		}

		printf("Case #%d: ", i + 1);

		for (int j = 0; j < n; j++) {
			double l = 0, r = 1;
			for (int k = 0; k < 1000; k++) {
				double mid = (l + r) / 2, tot = 0;
				double score = mid * sum + s[j];

				for (int p = 0; p < n; p++) {	
					if (p != j) {	
						if (s[p] < score)
							tot += (score - s[p]) / sum;						
					}										
				}

				if (tot + mid > 1) 
					r = mid;
				else
					l = mid;
			}
			cout << fixed << l * 100 << " ";
		}	
		cout << endl;
	}	
	return 0;
}