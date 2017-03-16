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
	int N;
	int M;
	long long a[101];
	int A[101];
	long long b[101];
	int B[101];

	cin >> case_num;
	for (int cn = 0; cn < case_num; cn++) {
		cin >> N;
		cin >> M;
		for (int i = 1; i <= N; i++) {
			cin >> a[i];
			cin >> A[i];
		}
		for (int i = 1; i <= M; i++) {
			cin >> b[i];
			cin >> B[i];
		}

		long long ans = 0;
		if (N == 1) {
			long long cnt = 0;
			long long remain = a[1];
			for (int i = 1; i <= M; i++) {
				if (A[1] == B[i]) {
					long long temp = min(remain, b[i]);
					cnt += temp;
					remain -= temp;
				}
			}
			ans = max(ans, cnt);
		} else if (N == 2) {
			for (int k = 0; k <= M; k++) {
				long long cnt = 0;
				int index = 1;
				long long remain = a[index];
				long long lastRemain = 0;
				for (int i = 1; i <= k; i++) {
					if (A[index] == B[i]) {
						long long temp = min(remain, b[i]);
						cnt += temp;
						remain -= temp;
						lastRemain = b[i] - temp;
					} else
						lastRemain = 0;
				}
				index++;
				remain = a[index];

				if (k > 0 && A[index] == B[k]) {
					long long temp = min(remain, lastRemain);
					cnt += temp;
					remain -= temp;
				}

				for (int i = k + 1; i <= M; i++) {
					if (A[index] == B[i]) {
						long long temp = min(remain, b[i]);
						cnt += temp;
						remain -= temp;
					}
				}
				ans = max(ans, cnt);
			}			
		} else if (N == 3) {
			for (int k = 0; k <= M; k++)
			for (int z = k; z <= M; z++) {
				long long cnt = 0;
				int index = 1;
				long long remain = a[index];
				long long lastRemain = 0;
				for (int i = 1; i <= k; i++) {
					if (A[index] == B[i]) {
						long long temp = min(remain, b[i]);
						cnt += temp;
						remain -= temp;
						lastRemain = b[i] - temp;
					} //else
					//	lastRemain = 0;
				}
				index++;
				remain = a[index];

				if ((k > 0) && (A[index] == B[k])) {
					long long temp = min(remain, lastRemain);
					cnt += temp;
					remain -= temp;
				}

				lastRemain = 0;
				for (int i = k+1; i <= z; i++) {
					if (A[index] == B[i]) {
						long long temp = min(remain, b[i]);
						cnt += temp;
						remain -= temp;
						lastRemain = b[i] - temp;
					} //else
						// lastRemain = 0;
				}
				index++;
				remain = a[index];

				if ((z > 0) && (A[index] == B[z])) {
					long long temp = min(remain, lastRemain);
					cnt += temp;
					remain -= temp;
				}

				for (int i = z+1; i <= M; i++) {
					if (A[index] == B[i]) {
						long long temp = min(remain, b[i]);
						cnt += temp;
						remain -= temp;
					}
				}
				ans = max(ans, cnt);
			}
		}

		cout << "Case #" << cn + 1 << ": " << ans << endl;
	}
}

