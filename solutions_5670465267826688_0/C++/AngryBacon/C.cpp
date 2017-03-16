#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int N = 100000 + 10;

//1->1, i->2, j->3, d->4

int multi[][4] = 
{
	{1, 2, 3, 4},
	{2, -1, 4, -3},
	{3, -4, -1, 2},
	{4, 3, -2, -1}
};

int toNum(char c)
{
	if (c == '1') return 1;
	if (c == 'i') return 2;
	if (c == 'j') return 3;
	return 4;
}

int multiply(int a, int b)
{
	int ret = (a / abs(a)) * (b / abs(b));
	return ret * multi[abs(a) - 1][abs(b) - 1];
}

int quickPower(int a, long long d)
{
	int ret = 1;
	for( ; d; d >>= 1, a = multiply(a, a)) {
		if (d & 1) {
			ret = multiply(ret, a);
		}
	}
	return ret;
}

int a[N];

void bruteforce(string t)
{
	int n = t.size();

	int tmp = 1;
	int first = -1;
	for(int i = 0; i < n; ++ i) {
		a[i] = toNum(t[i]);
		tmp = multiply(tmp, a[i]);
		if (tmp == 2 && first < 0) {
			first = i;
		}
	}
	tmp = 1;
	int second = -1;
	for(int i = n - 1; i >= 0; -- i) {
		tmp = multiply(a[i], tmp);
		if (tmp == 4 && second < 0) {
			second = i;
		}
	}
	if (first < second && first >= 0 && second >= 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

void solve()
{
	long long n, d;
	string s;
	cin >> n >> d >> s;

	int sum = 1;
	for(int i = 0; i < n; ++ i) {
		sum = multiply(sum, toNum(s[i]));
	}
	sum = quickPower(sum, d);
	if (sum != -1) {
		cout << "NO" << endl;
		return;
	}

	if (d < 10) {
		string t;
		for(int i = 0; i < d; ++ i) {
			t += s;
		}
		bruteforce(t);
	} else {
		int tmp = 1;
		int flag = 0;
		for(int i = 0; i < 4 * n; ++ i) {
			tmp = multiply(tmp, toNum(s[i % n]));
			if (tmp == 2) {
				flag ++;
				break;
			}
		}
		tmp = 1;
		for(int i = 4 * n - 1; i >= 0; -- i) {
			tmp = multiply(toNum(s[i % n]), tmp);
			if (tmp == 4) {
				flag += 2;
				break;
			}
		}
		if (flag == 3) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-attempt0.out", "w", stdout);
	//freopen("C-small-attempt1.in", "r", stdin); freopen("C-small-attempt1.out", "w", stdout);
	//froepen("C-large.in", "r", stdin); freopen("C-large.out", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
