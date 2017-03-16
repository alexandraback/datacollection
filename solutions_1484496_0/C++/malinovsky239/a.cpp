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

const int N = 505, M = int(2e6 + 5);

int top, s[N], n, mask[M];

void nums(int m) {
	for (int j = 0, p = 1; j < n; j++, p <<= 1)
		if (p & m)
			cout << s[j] << " ";
	cout << endl;				
}

int main() {
	int t;
	cin >> t;	

	for (int i = 0; i < t; i++) {
		printf("Case #%d:\n", i + 1);

		memset(mask, 0, sizeof(mask));

		n;
		cin >> n;

		for (int j = 0; j < n; j++)
			cin >> s[j];

		top = (1 << n);

		for (int k = 0; k < top; k++) {
			int sum = 0;
			for (int j = 0, p = 1; j < n; j++, p <<= 1) 
				if (p & k) 
					sum += s[j];

			if (mask[sum]) {	
				nums(k);
				nums(mask[sum]);
				break;								
			}
			mask[sum] = k;
		}
	}

	return 0;
}