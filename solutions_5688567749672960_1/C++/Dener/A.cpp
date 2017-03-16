#include <bits/stdc++.h>

using namespace std;

long long reverseNum(long long i)
{
    long long res = 0;
    while (i) {
	res = res * 10 + i % 10;
	i /= 10;
    }
    return res;
}

inline pair<bool, long long> isGood(long long n)
{
    vector< long long > dig;
    while (n) {
	dig.push_back(n % 10);
	n /= 10;
    }

    long long ost = 0;
    for (long long i = (long long)(dig.size()) / 2 - 1; i >= 0; i--) {
	ost = ost * 10 + dig[i];
    }

    if (ost == 0) {
	return make_pair(false, 2);
    }

    return make_pair(ost == 1, ost);
}

const long long MAXN = 1000 * 1000 + 100;
long long res[MAXN];
long long bestans;

void calc(long long n, long long curRes)
{
    if (n == 1) {
	bestans = min(bestans, curRes + 1);
	return;
    }
    if (curRes >= bestans) {
	return;
    }

    long long rev = reverseNum(n);
    pair<bool, long long> p = isGood(n);
    if (p.first) {
	if (rev < n) {
	    calc(rev, curRes + 1);
	} else {
	    calc(n - 1, curRes + 1);
	}
    } else {
	calc(n - (p.second - 1), curRes + (p.second - 1));
    }
}

void solve1(int testnum)
{
    long long n;
    cin >> n;
    for (long long i = 0 ;i < n + 1; i++) {
	res[i] = n;
    }
    res[1] = 1;
    for (long long i = 1; i <= n; i++) {
	long long rev = reverseNum(i);
	res[rev] = min(res[rev], res[i] + 1);
	res[i + 1] = min(res[i + 1], res[i] + 1);
    }
    cout << "Case #" << testnum + 1 << ": " << res[n] << "\n";

    for (long long i = 1000000 - 100; i <= 1000000; i++) {
	bestans = INT_MAX;
	calc(i, 0);
	cout << i << " : " << res[i] << ' ' << bestans << '\n';
	cout.flush();
	assert(res[i] == bestans);
    }
}

void solve2(int testnum)
{
    long long n;
    cin >> n;

    bestans = (long long)(1e18);
    calc(n, 0);
    cout << "Case #" << testnum + 1 << ": " << bestans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
	solve2(q);
    }
}
