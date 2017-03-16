#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int N;
long long S[501];

#define TOTAL (20LL*100001)
void solve()
{
	long long ans[TOTAL];	
	for (int i=0; i<TOTAL; i++) ans[i] = -1;

	for (int i=0; i<(2<<N-1); i++) {
		long long sum = 0;
		int n = i;
		int count = 0;
		while (n>0) {
			if (n%2 == 1) {
				sum += S[count];
			}
			count ++;
			n /= 2;
		}
		//cout << sum << endl;
		if (ans[sum] == -1)
			ans[sum] = i;
		else {
			cout << endl;
			count = 0;
			n = i;
			while (n>0) {
				if (n%2 == 1) {
					cout << S[count] << " ";
				}
				count ++;
				n /= 2;
			}
			cout << endl;
			n = ans[sum];
			count = 0;
			while (n>0) {
				if (n%2 == 1) {
					cout << S[count] << " ";
				}
				count ++;
				n /= 2;
			}
			cout << endl;
			return;
		}
	}

}


int main()
{
	int case_num;
	cin >> case_num;

	for (int t=1; t<=case_num; t++) {
		// initialization, IO
		cin >> N;
		for (int i=0; i<N; i++) cin >> S[i];

		cout << "Case #" << t << ": ";
		solve();

	}
}
