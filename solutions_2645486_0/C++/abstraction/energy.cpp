#include <iostream>
#include <string.h>

using namespace std;

int solve(int E, int R, int N, int v[])
{
	int maxE = 0;
	int *gain, *tmp;
	int result;
	for (int i = 0; i < N; i++)
		maxE += v[i] * E;

	gain = new int[maxE+1];
	tmp = new int[maxE+1];
	for (int i = 0; i <= maxE; i++)
		gain[i] = -1;
	gain[0] = E;

	for (int i = 0; i < N; i++) {
		memset(tmp, 0, sizeof(int) * (maxE+1));
		for (int j = 0; j <= maxE; j++) {
			int max_re = -1;
			for (int k = 0; k <= j; k++) {
				if (gain[k] != -1) {
					int remain = j - k;
					if ((remain % v[i]) == 0 && (remain / v[i]) <= gain[k]) {
						int t = min(E, gain[k] - (remain / v[i]) + R);
						max_re = max(t, max_re);
					}
				}
			}
			tmp[j] = max_re;
		}
		memcpy(gain, tmp, (maxE+1) * sizeof(int));
	}

	for (int i = maxE; i >=0; i--)
		if (gain[i] >= 0) {
			result = i;
			break;
		}
	delete [] gain;
	delete [] tmp;
	return result;
			
}
int main()
{
	int T, E, R, N;
	int *v;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> E >> R >> N;
		v = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}
		cout << "Case #" << i << ": " << solve(E, R, N, v) << endl;
		delete [] v;
	}

}

