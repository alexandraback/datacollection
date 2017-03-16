#include <iostream>
#include <stdio.h>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;

const int nmax = 32;

int A[nmax], B[nmax], K[nmax];

LL F[nmax][2][2][2];

LL recurs(int i, int a, int b, int k) {
	if (i == nmax)
		return 1;
	//if (a + b + k == 0)
		//return 1LL << (nmax - i);

	if (F[i][a][b][k] != -1)
		return F[i][a][b][k]; 
	
	LL &ans = F[i][a][b][k];
	ans = 0;

	ans += recurs(i + 1, min(a, 1 - int(0 < A[i])), min(b, 1 - int(0 < B[i])), min(k, 1 - int(0 < K[i])));
	if (a == 0 || A[i] == 1) 
		ans += recurs(i + 1, a, min(b, 1 - int(0 < B[i])), min(k, 1 - int(0 < K[i])));
	if (b == 0 || B[i] == 1) 
		ans += recurs(i + 1, min(a, 1 - int(0 < A[i])), b, min(k, 1 - int(0 < K[i])));
	if (a == 0 || A[i] == 1)
		if (b == 0 || B[i] == 1)
			if (k == 0 || K[i] == 1)
				ans += recurs(i + 1, a, b, k);
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int a, b, k;
		cin >> a >> b >> k;
		/*
		LL ans2 = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				if ((i & j) < k)
					++ans2;
			}
		}
		*/
		--a;
		--b;
		--k;
		memset(F, -1, sizeof(F));
		for (int i = nmax - 1; i >= 0; --i) {
			A[i] = a % 2;
			a /= 2;
			B[i] = b % 2;
			b /= 2;
			K[i] = k % 2;
			k /= 2;
		}
		

		LL ans = recurs(0,1,1,1);
		//assert(ans == ans2);
		/*if (ans != ans2 ) {
			cout << ans << " " << ans2 << endl;
			cout << test << endl;
			return 0;
		}*/
		cout << "Case #" << test <<	": ";
		
		cout << ans << endl;
		
    }
    return 0;
}

//C:\Users\Mykola\Documents\Visual Studio 2010\Projects\acm\acm