#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

#define next qwertyusdfgh
#define read(x) scanf("%d", &x)
#define write(x) printf("%d ", x)
#define writeln(x) printf("%d\n", x)

const int maxKy = 210;
const int maxN = 25;
const int maxMs = 1 << 22;

int us[maxMs], ans[maxMs];
int kl[maxMs];
int nd[maxN], an[maxN];
int ky[maxN][500];
int n, k;

//-------------------------------------------------------------------------------------------------

void cl(int x) {
	for (int i = 1; i <= ky[x][0]; i++)
		kl[ky[x][i]]--;
}

bool make(int mask, int kol) {
	if (us[mask] == 2) {
		return true;
	}

	if (us[mask] == 0) {
	//	cout << "lol" << endl;
	//	cout << (0 & 1) << endl;
	
		for (int i = 0; i < n; i++)
			if ((mask & (1 << i)) == 0 && kl[nd[i]] > 0) {
				int mask2 = mask | (1 << i);
				//cout << mask2 << endl;
				for (int j = 1; j <= ky[i][0]; j++)
					kl[ky[i][j]]++;
				kl[nd[i]]--;
				if (make(mask2, kol + 1)) {
					kl[nd[i]]++;
					ans[mask] = true;
					an[kol] = i + 1;
					us[mask] = 1;
					cl(i);
					return true;
				}	
				kl[nd[i]]++;
		        cl(i);                
			}

		us[mask] = 1;
		ans[mask] = false;
	
	}
	return ans[mask];
}

void solve(int test) {
	scanf("%d %d", &k, &n);

    for (int mask = 0; mask < 1 << n; mask++) 
		us[mask] = 0;
	us[(1 << n) - 1] = 2;
	
	for (int i = 1; i < maxKy; i++)
		kl[i] = 0;

	for (int i = 1; i <= k; i++) {
		int x;
		read(x);
		kl[x]++;
	}

	for (int i = 0; i < n; i++) {
		cin >> nd[i] >> ky[i][0];
		for (int j = 1; j <= ky[i][0]; j++)
			cin >> ky[i][j];
	}	
	//cout << nd[0] << ' ' << kl[1] << endl;


	if (make(0, 1)) {
		printf("Case #%d: ", test);
		for (int i = 1; i < n; i++)
			cout << an[i] << ' ';
		cout << an[n] << endl;
	}
	else {
		printf("Case #%d: IMPOSSIBLE\n", test);	
	}

	
}

int main() {

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		solve(test);
	}
	
	return 0;
}