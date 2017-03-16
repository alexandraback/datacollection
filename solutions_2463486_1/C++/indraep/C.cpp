#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <sstream>

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long LL;

#define REP(i, a) for (int i = 0; i < (int)(a); i++)
#define FOR(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define REPD(i, a) for (int i = (int)(a - 1); i >= 0; i--)
#define FORD(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define CLEAR(x, val) memset(x, val, sizeof(x))


int tc, len;
LL A, B;

map < LL, bool > palindrome;
vector < LL > fairPalindrome;

pair <LL, LL> getPalin(int n) {
	pair <LL, LL> ret;
	LL temp = n;
	LL value = n;

	while (temp > 0) {
		value *= 10;
		value += (temp % 10);
		temp /= 10;
	}

	ret.S = value;

	temp = n / 10;
	value = n;

	while (temp > 0) {
		value *= 10;
		value += (temp % 10);
		temp /= 10;
	}

	ret.F = value;

	return ret;
}

bool isPalindrome(LL temp) {
	string str;
	stringstream sin;
	sin << temp;
	sin >> str;

	int l = 0, r = str.length() - 1;
	while (l < r && str[l] == str[r]) {
		l++; r--;
	}
	return l >= r;
}

void init() {
	pair <LL, LL> temp;
	LL val;
	FOR(i, 1, 9999) {
		temp = getPalin(i);
		val = temp.F * temp.F;
		if (val <= (LL)1e14 && isPalindrome(val) && !palindrome[val]) {
			palindrome[val] = 1;
			fairPalindrome.pb(val);
		}
		val = temp.S * temp.S;
		if (val <= (LL)1e14 && isPalindrome(val) && !palindrome[val]) {
			palindrome[val] = 1;
			fairPalindrome.pb(val);
		}
	}

	sort(fairPalindrome.begin(), fairPalindrome.end());
	len = fairPalindrome.size();
}

int getIndex(LL A) {
	REP(i, len) {
		if (fairPalindrome[i] == A) {
			return i;
		}
		else if (fairPalindrome[i] > A)
			return i - 1;
	}

	return len - 1;
}

int solve(LL A, LL B) {
	return getIndex(B) - getIndex(A - 1);
}

int main () {
	init();
	//REP(i, len)
	//	cout << "i = " << i << " val = " << fairPalindrome[i] << endl;

	scanf("%d", &tc);

	FOR(test, 1, tc) {
		scanf("%lld %lld", &A, &B);
		printf("Case #%d: %d\n", test, solve(A, B));
	}
}












/*
int tc;
LL A, B;
vector < int > ans;

bool isPalindrome(LL x) {
	stringstream sin;
	string temp;
	sin << x;
	sin >> temp;

	int l = 0;
	int r = temp.length() - 1;
	while (l < r && temp[l] == temp[r]) {
		l++; r--;
	}

	return l >= r;
}

void init() {
	FOR(i, 1, 1e7) {
		if (i == 10000 || i == 100000 || i == 1000000 || i == 10000000)
			cout << "i = " << i << endl;
		if (isPalindrome(i) && isPalindrome(i * i))
			ans.pb(i * i);
	}
}

int main () {
	init();
	cout << "ans = " << ans.size() << endl;
	cin >> tc;
	FOR(test, 1, tc) {
		cin >> A >> B;
	}
}
*/







