#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T, X;
  cin >> T;
  for (int t=1;t<=T;t++) {
		int N;
		cin >> N;

		vector<double> A, B;
		double x;
		for (int i=0;i<N;i++) {
			cin >> x;
			A.push_back(x);
		}
		for (int i=0;i<N;i++) {
			cin >> x;
			B.push_back(x);
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());

		int WAR=0, DWR=0;

		// war, whatever Naomi chooses, Ken chooses the next largest, or otherwise smallest
		int mn=0, mx=N-1;
		for (int i=N-1;i>=0;i--) {
			if (B[mx]>A[i]) mx--;
			else {
				mn++;
				WAR++;
			}
		}

		mn=0, mx=N-1;
		for (int i=0;i<N;i++) {
			if (A[i]<B[mn]) {
				// Naomi loses
				mx--;
			}
			else { // wins
				mn++;
				DWR++;
			}
		}
		
		printf("Case #%d: ", t);
		printf("%d %d\n", DWR, WAR);
	}

  return 0;
}
