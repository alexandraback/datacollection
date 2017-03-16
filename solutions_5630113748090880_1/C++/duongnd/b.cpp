#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long int ll;
long a[55][2555];
long cnt[2555] = {};

long solve() {
    long n,t ;
    cin >> n;
    for (int i = 0; i < 2501; i ++) cnt[i] = 0;
    for (int i = 0; i < 2 * n -1; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            cin >> t;
            cnt[t] ++;
        }
    }
    for (int i = 0; i < 2501; i ++)
        if (cnt[i] % 2 == 1)
            cout << i << " ";
}

int main() {
	long t = 0;
	freopen("B-large.in","r",stdin);
	freopen("B-l.out","w",stdout);
	cin >> t;
	for (int i = 0; i < t; i ++) {
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}
