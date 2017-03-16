#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;


int N, M;
long long a[101];
long long b[101];
int A[101];
int B[101];

void solve()
{
/*
	for (int i=0; i<N; i++) cout << a[i] << " ";	
	cout << endl;
	for (int i=0; i<N; i++) cout << A[i] << " ";	
	cout << endl;
	for (int i=0; i<N; i++) cout << b[i] << " ";	
	cout << endl;
	for (int i=0; i<N; i++) cout << B[i] << " ";	
	cout << endl;
	*/
	long long ans = 0;
	if (N==1) {
		for (int i=0; i<M; i++) {
			if (a[0] == 0) break;
			if (A[0] == B[i]) {
				long long tmp = min(a[0], b[i]);
				a[0] -= tmp;
				b[i] -= tmp;
				ans += tmp;
			}
		}
	}
	else if (N==2) {
		for (int i=0; i<=M; i++) {
			for (int j=i; j<=M; j++) {
					int cur = 0;
					long long sum = 0;
					long long aa[100];
					long long bb[100];
					for (int y=0; y<N; i++) aa[y] = a[y];
					for (int y=0; y<M; i++) bb[y] = b[y];

					for (int x=0; x<M; ) {
						if (cur >= 2) break;
						if (x >= M) break;

						if (A[cur] == B[x]) {
							long long tmp = min(aa[cur], bb[x]);
							sum += tmp;
							aa[cur] -= tmp;
							bb[x] -= tmp;
							if (aa[cur] == 0) cur += 1;
							if (bb[x] == 0) x += 1;
							continue;
						}
						else {
							if (x == i) cur += 1;	
							else if (x == j) cur += 1;	
							else x++;
						}
					}
					//cout << i << " " << j << " " << k << " " << sum << endl;
					ans = max(sum, ans);
			}
		}

	}
	else if (N==3) {
		for (int i=0; i<=M; i++) {
			for (int j=i; j<=M; j++) {
				for (int k=j; k<=M; k++) {
					int cur = 0;
					long long sum = 0;
					long long aa[100];
					long long bb[100];
					for (int y=0; y<N; y++) aa[y] = a[y];
					for (int y=0; y<M; y++) bb[y] = b[y];

					for (int x=0; x<M; ) {
						if (cur >= 3) break;
						if (x >= M) break;

						if (A[cur] == B[x]) {
							long long tmp = min(aa[cur], bb[x]);
							sum += tmp;
							aa[cur] -= tmp;
							bb[x] -= tmp;
							if (aa[cur] == 0) cur += 1;
							if (bb[x] == 0) x += 1;
							continue;
						}
						else {
							if (x == i) cur += 1;	
							else if (x == j) cur += 1;	
							else if (x == k) cur += 1;	
							else x++;
						}
					}
					//cout << i << " " << j << " " << k << " " << sum << endl;
					ans = max(sum, ans);
				}
			}
		}
	}
	cout << ans << endl;
}



int main()
{
	int case_num;
	cin >> case_num;

	for (int t=1; t<=case_num; t++) {
		// initialization, IO
		cin >> N >> M;
		for (int i=0; i<N; i++) {
			long long tmpa;
			int tmpA;
			cin >> tmpa >> tmpA;
			a[i] = tmpa;
			A[i] = tmpA-1;
		}
		for (int i=0; i<M; i++) {
			long long tmpa;
			int tmpA;
			cin >> tmpa >> tmpA;
			b[i] = tmpa;
			B[i] = tmpA-1;
		}

		cout << "Case #" << t << ": ";
		solve();

	}
}
