#include <bits/stdc++.h>

using namespace std;

int reverseNum(int i)
{
    int res = 0;
    while (i) {
	res = res * 10 + i % 10;
	i /= 10;
    }
    return res;
}

const int MAXN = 1000 * 1000 + 100;
int res[MAXN];

void solve(int testnum)
{
    int n;
    cin >> n;
    for (int i = 0 ;i < n + 1; i++) {
	res[i] = n;
    }
    res[1] = 1;
    for (int i = 1; i <= n; i++) {
	int rev = reverseNum(i);
	res[rev] = min(res[rev], res[i] + 1);
	res[i + 1] = min(res[i + 1], res[i] + 1);
    }
    cout << "Case #" << testnum + 1 << ": " << res[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
	solve(q);
    }
}
