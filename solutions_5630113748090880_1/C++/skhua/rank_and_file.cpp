#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int N, tmp;
int cnt[2501];

void run_case(int tc) {
    cin >> N;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < 2*N - 1; i++)
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			cnt[tmp]++;
		}

	cout << "Case #" << tc << ":";
	for (int i = 1; i <=2500; i++) {
		if (cnt[i] % 2 == 1) {
			cout << " " << i;
			if (--N == 0)
				break;
		}
	}
	cout << endl;
}

int main() {
	int num = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i) {
		run_case(i);
	}
	return 0;
}