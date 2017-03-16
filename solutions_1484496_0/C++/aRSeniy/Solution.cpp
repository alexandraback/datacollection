#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

int sum[(1 << 20)];
int val[4000006];

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ":" << endl;
		int n;
        cin >> n;

        for (int i = 0; i < (1 << n); ++i) {
            sum[i] = 0;
        }
        for (int i = 0; i < 4000006; ++i) {
            val[i] = 0;
        }

        vector <long long> S(n);
        for (int i = 0; i < n; ++i)
            cin >> S[i];

        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j)
                if (((1 << j) & i) == (1 << j)) {
                    sum[i] += S[j];
                }
            ++val[sum[i]];
        }
		
        int ans = -1;
        for (int i = 1; i < 200000 * 30; ++i) {
            if (val[i] > 1) {
                ans = i;
                break;
            }
        }
        if (ans == -1) {
            cout << "Impossible" << endl;
            continue;
        }
        int p = 0;
        for (int i = 0; i < (1 << n); ++i) {
            int curs = 0;
            for (int j = 0; j < n; ++j)
                if (((1 << j) & i) == (1 << j)) {
                    curs += S[j];
                }
            if (curs == ans) {
                ++p;
                for (int j = 0; j < n; ++j)
                    if (((1 << j) & i) == (1 << j)) {
                        cout << S[j] << " ";
                    }
                cout << endl;
            }
            if (p == 2)
                break;
        }
	}
	return 0;
}