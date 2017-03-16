#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w+", stdout);
	
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		long long A = 0, B = 0;
		long long K = 0;

		cin >> A >> B >> K;

		int res = 0;
		for (long long i = 0; i < A; i++) {
			for (long long j = 0; j < B; j++) {
				long long num = (i & j);
				if (num < K) {
					res++;
				}
			}
		}

		cout << "Case #" << cas << ": " << res << endl;
	}
    return 0;
}
