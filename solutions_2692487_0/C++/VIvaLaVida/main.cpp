#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int A;
int N;
long long arr[100 + 1];
int ans[100+1];
int ansN;
int solve()
{
	int cnt = 0;
	ansN = 0;
	long long sum = A;
	sort(arr, arr+N);
	if (A == 1)
		return N;
	bool flag = true;
	for (int i = 0; i < N;) {
		if (sum > arr[i]) {
			sum += arr[i++];
			flag = true;
		} else {
			cnt++;
			if (flag) {
				ans[ansN++] = cnt - 1 + N - i;
				flag = false;
			}
			sum += sum - 1;
		}
	}
	for (int i = 0; i < ansN; i++) {
		if (ans[i] < cnt)
			cnt = ans[i];
	}
	return cnt;

}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		scanf("%d %d", &A, &N);
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}
		cout << "Case #" << i << ": " << solve() <<endl;
	}
	return 0;
}
