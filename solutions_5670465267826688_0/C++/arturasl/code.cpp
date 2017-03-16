#include      <algorithm>
#include      <cassert>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <queue>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll mul[5][5] = {
	{0,  0,  0,  0,  0},
	{0,  1,  2,  3,  4},
	{0,  2, -1,  4, -3},
	{0,  3, -4, -1,  2},
	{0,  4,  3, -2, -1}
};

const ll kwdI = 2, kwdJ = 3, kwdK = 4;
const ll maxRep = 10;

ll multiply(ll i, ll j) {
	return mul[abs(i)][abs(j)] * (i < 0 ? -1 : 1) * (j < 0 ? -1 : 1);
}

ll mod(ll i, ll n) {
	return i % n + (i < 0 ? n : 0);
}

string printable(ll i) {
	string r = "";
	if (i < 0) {
		r += "-";
		i *= -1;
	}
	switch (i) {
		case 0: r += "0"; break;
		case 1: r += "1"; break;
		case kwdI: r += "i"; break;
		case kwdJ: r += "j"; break;
		case kwdK: r += "k"; break;
	}
	return r;
}

bool solve() {
	ll rep;
	cin >> rep >> rep;
	string str;
	cin >> str;
	vector<ll> nums(str.length());
	for (ll i = 0; i < (ll) str.length(); i += 1) {
		switch (str[i]) {
			case 'i': nums[i] = kwdI; break;
			case 'j': nums[i] = kwdJ; break;
			case 'k': nums[i] = kwdK; break;
		}
	}

	const ll size = rep * nums.size();
	const ll upper = nums.size() * maxRep;

	ll prefix = 1, prefixPos;
	for (prefixPos = 0; prefixPos < upper && prefix != kwdI; prefixPos += 1) {
		const ll pos = mod(prefixPos, nums.size());
		prefix = multiply(prefix, nums[pos]);
	}
	if (prefix != kwdI) return false;

	ll postfix = 1, postfixPos;
	for (postfixPos = 0; postfixPos < upper && postfix != kwdK; postfixPos += 1) {
		const ll pos = nums.size() - mod(postfixPos, nums.size()) - 1;
		postfix = multiply(nums[pos], postfix);
	}
	if (postfix != kwdK) return false;

	ll totalMul = 1;
	for (ll i = 0; i < (ll) nums.size(); i += 1) {
		totalMul = multiply(totalMul, nums[i]);
	}

	const ll absPrefixPos = prefixPos;
	const ll absPostfixPos = size - ll(postfixPos) - ll(1);
	if (absPostfixPos <= 0 || absPrefixPos >= size || absPrefixPos > absPostfixPos) return false;

	// if (absPostfixPos - absPrefixPos <= upper) {
		ll middle = 1;
		for (ll i = absPrefixPos; i <= absPostfixPos; i += 1) {
			middle = multiply(middle, nums[i % nums.size()]);
		}
		return middle == kwdJ;
	// }
    //
	// ll repTotal = absPostfixPos - absPrefixPos + 1;
	// ll pl = 1;
	// for (ll i = mod(absPrefixPos, nums.size()); i < (ll) nums.size(); i += 1, repTotal -= 1) {
	// 	pl = multiply(pl, nums[i]);
	// }
	// ll pr = 1;
	// for (ll i = 0; i <= mod(absPostfixPos, nums.size()); i += 1, repTotal -= 1) {
	// 	pr = multiply(pr, nums[i]);
	// }
    //
	// assert(repTotal % nums.size() == 0);
    //
	// switch ((repTotal / nums.size()) % 4) {
	// 	case 0: totalMul = 1; break;
	// 	case 1: totalMul = totalMul; break;
	// 	case 2: totalMul = -1; break;
	// 	case 3: totalMul = -totalMul; break;
	// }
	// return multiply(pl, multiply(totalMul, pr)) == kwdJ;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	ll T;
	cin >> T;
	for (ll t = 1; t <= T; t += 1) {
		cout << "Case #" << t << ": " << (solve() ? "YES" : "NO") << endl;
	}
	return 0;
}
