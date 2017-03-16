#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vb> vvb;
typedef vector<vs> vvs;
typedef vector<vl> vvl;

int inf = 0x3f3f3f3f;
double eps = 10e-8;
ll mod = 1000000007ll;

#define rep(k, a, b) for (int k = (a); k < int(b); k++)
#define sz(a) int(a.size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define x first
#define y second
#define mi(r, c, v) vvi(r, vi(c, v))
#define rrep(k, a, b) for (int k = (a); k >= int(b); k--)
#define irep(k, a) for (auto& k : (a))
#define md(r, c, v) vvd(r, vd(c, v))
#define mb(r, c, v) vvb(r, vb(c, v))
#define ms(r, c, v) vvs(r, vs(c, v))
#define ml(r, c, v) vvl(r, vl(c, v))
#define mc(r, c, v) vs(r, string(c, v))
#define add(i, j) ((i) + (j)) % mod
#define mul(i, j) ((i) * (j)) % mod
#define bits(n) int(__builtin_popcount(n))

class BigInt {
	vl digits;
	int sign;
	static const ll unit = 100000000;
	static const int pos = 8;

	//compares the magnitute of 2 bigints, from the digit shift and up.
	int compareIgnoreSign(const BigInt& b, int shift = 0) const {
		if (sz(digits) > sz(b.digits) + shift)
			return 1;
		else if (sz(digits) < sz(b.digits) + shift)
			return -1;
		rrep(i, sz(digits) - 1, shift) {
			if (digits[i] > b.digits[i - shift])
				return 1;
			else if (digits[i] < b.digits[i - shift])
				return -1;
		}
		return 0;
	}
	int compare(const BigInt& b) const {
		if (sign > b.sign)
			return 1;
		else if (sign < b.sign)
			return -1;
		return compareIgnoreSign(b) * sign;
	}
	void clear_zero() {
		while (digits.back() == 0 && sz(digits) > 1)
			digits.resize(sz(digits) - 1);
		if (sz(digits) == 1 && digits[0] == 0)
			sign = 0;
	}
	void carry(int k) {
		while (digits[k] >= unit) {
			if (k == sz(digits) - 1)
				digits.resize(sz(digits) + 1, 0);

			digits[k + 1] += digits[k] / unit;
			digits[k] %= unit;
			k++;
		}
	}
	void addValue(const BigInt& b) {
		if (sz(b.digits) > sz(digits))
			digits.resize(sz(b.digits), 0);
		rep(i, 0, sz(b.digits)) {
			digits[i] += b.digits[i];
			carry(i);
		}
	}
	void subValue(const BigInt& b, int shift = 0, bool do_not_compare = false) {
		if (sz(b.digits) + shift > sz(digits))
			digits.resize(sz(b.digits) + shift, 0);
		if (do_not_compare || compareIgnoreSign(b) >= 0) {
			rep(i, 0, sz(b.digits))
				digits[i + shift] -= b.digits[i];
		} else {
			rep(i, 0, sz(b.digits))
				digits[i + shift] = b.digits[i] - digits[i + shift];
			sign *= -1;
		}
		rep(i, 0, sz(digits)) {
			if (digits[i] < 0) {
				digits[i + 1]--;
				digits[i] += unit;
			}
		}
		clear_zero();
	}
public:
	BigInt(ll n = 0) {
		digits.clear();
		if (n == 0) {
			sign = 0;
			digits.pb(0);
			return;
		} else if (n > 0) {
			sign = 1;
		} else {
			sign = -1;
			n = -n;
		}
		while (n > 0) {
			digits.pb(n % unit);
			n /= unit;
		}
	}
	// allows for leading zeroes, but negative sign should be first symbol
	BigInt(const string& s) {
		int start = 0;
		if (s == "") {
			digits.pb(0);
		} else if (s[0] == '-') {
			sign = -1;
			start = 1;
		} else {
			sign = 1;
		}
		int end = sz(s) - 1;
		while (end >= start) {
			ll mul = 1;
			digits.pb(0);
			rep(i, 0, min(pos, end - start + 1)) {
				digits.back() += (s[end - i] - '0') * mul;
				mul *= 10;
			}
			end -= pos;
		}
		clear_zero();
	}
	BigInt& operator+=(const BigInt& b) {
		if (b.sign == 0)
			return *this;
		else if (sign == 0) {
			*this = b;
			return *this;
		}
		if (sign == b.sign)
			addValue(b);
		else
			subValue(b);
		return *this;
	}
	BigInt& operator-=(const BigInt& b) {
		if (b.sign == 0)
			return *this;
		else if (sign == 0) {
			*this = b;
			sign *= -1;
			return *this;
		}
		if (sign == b.sign)
			subValue(b);
		else
			addValue(b);
		return *this;
	}
	BigInt operator*(const BigInt& b) const {
		BigInt result;
		result.sign = sign * b.sign;
		if (result.sign == 0)
			return result;
		result.digits.resize(sz(digits) + sz(b.digits) - 1);
		rep(i, 0, sz(digits)) {
			rep(j, 0, sz(b.digits)) {
				result.digits[i + j] += digits[i] * b.digits[j];
				result.carry(i + j);
			}
		}
		return result;
	}
	// returns quotient, becomes remainder
	BigInt divisionRemainder(const BigInt& b) {
		if (b.sign == 0)
			sign = b.sign / b.sign;
		else if (compareIgnoreSign(b, 0) < 0)
			return BigInt(0);

		vector<BigInt> b_table(1, b);
		vector<ll> d_table(1, 1);
		while (d_table.back() < unit / 2) {
			d_table.push_back(d_table.back() * 2);
			b_table.push_back(b_table.back() + b_table.back());
		}

		int shift = sz(digits) - sz(b.digits);
		BigInt quotient;
		quotient.sign = sign;
		quotient.digits.resize(shift + 1);

		rrep(k, shift, 0)
			rrep(l, sz(d_table) - 1, 0)
			if (compareIgnoreSign(b_table[l], k) >= 0) {
				subValue(b_table[l], k, true);
				quotient.digits[k] += d_table[l];
			}
		sign *= b.sign;
		quotient.sign *= b.sign;
		clear_zero();
		quotient.clear_zero();
		return quotient;
	}
	string toString() const {
		string s;
		if (sign == 0)
			return "0";
		rep(i, 0, sz(digits) - 1) {
			ll n = digits[i];
			rep(j, 0, pos) {
				s += char('0' + n % 10);
				n /= 10;
			}
		}
		ll n = digits.back();
		while (n > 0) {
			s += char('0' + n % 10);
			n /= 10;
		}
		if (sign == -1)
			s += '-';
		reverse(all(s));
		return s;
	}
	BigInt operator+(const BigInt& b) const { BigInt result = *this; return result += b; }
	BigInt operator-(const BigInt& b) const { BigInt result = *this; return result -= b; }
	BigInt& operator*=(const BigInt& b) { *this = *this * b; return *this; }
	BigInt operator/(const BigInt& b) const { BigInt result = *this; return result.divisionRemainder(b); }
	BigInt& operator/=(const BigInt& b) { *this = *this / b; return *this; }
	BigInt& operator%=(const BigInt& b) { divisionRemainder(b); return *this; }
	BigInt operator%(const BigInt& b) const { BigInt result = *this; return result %= b; }
	BigInt operator-() const { BigInt result = *this; result.sign *= -1; return result; }
	bool operator<(const BigInt& b) const { return compare(b) < 0; }
	bool operator>(const BigInt& b) const { return compare(b) > 0; }
	bool operator<=(const BigInt& b) const { return compare(b) <= 0; }
	bool operator>=(const BigInt& b) const { return compare(b) >= 0; }
	bool operator==(const BigInt& b) const { return compare(b) == 0; }
	bool operator!=(const BigInt& b) const { return compare(b) != 0; }
};
istream& operator>>(istream& in, BigInt& b) { string s; in >> s; b = s; return in; }

vi sieve(int n) {
	n = (n - 1) / 2;
	vb arr(n + 1);
	vi primes(1, 2);
	int p = 1;

	while (2 * p * (p + 1) <= n) {
		if (!arr[p]) {
			primes.pb(2 * p + 1);
			for (int j = 2 * p * (p + 1); j <= n; j += 2 * p + 1)
				arr[j] = true;
		}
		p++;
	}

	while (p <= n) {
		if (!arr[p])
			primes.push_back(2 * p + 1);
		p++;
	}

	return primes;
}

template <class T>
T stringToInt(const string& s, int base = 10) {
	T result = 0;
	bool neg = s[0] == '-';
	irep(c, s) {
		result *= base;
		if (c >= '0' && c <= '9') {
			result += c - '0';
		} else if (c >= 'A' && c <= 'Z') {
			result += c - 'A' + 10;
		} else if (c >= 'A' && c <= 'Z') {
			if (base > 36)
				result += c - 'a' + 36;
			else
				result += c - 'a' + 10;
		}
	}
	if (neg)
		result *= -1;
	return result;
}

template <class T>
int fastSmallPrime(T n, const vi& primes) {
	irep(p, primes) {
		if (n < p * p) return -1;
		if (n % p == 0) return p;
	}
	return -1;
}

int main() {
	int T, n, j;
	string s;
	cin >> T >> n >> j;
	printf("Case #1:\n");

	vi primes = sieve(10000);

	if (n == 6)
		s = "100001";
	else if (n == 16)
		s = "1000000000000001";
	else
		s = "10000000000000000000000000000001";

	while (j > 0) {
		vl ans;
		rep(b, 2, 11) {
			BigInt var = stringToInt<BigInt>(s, b);
			int p = fastSmallPrime(var, primes);
			if (p == -1)
				break;
			ans.pb(p);
		}

		if (sz(ans) == 9) {
			cerr << j << ' ';
			cerr.flush();
			printf("%s", s.c_str());
			irep(v, ans)
				printf(" %lld", v);
			printf("%\n");
			j--;
		}

		rrep(d, sz(s) - 2, 0) {
			if (s[d] == '0') {
				s[d] = '1';
				break;
			} else {
				s[d] = '0';
			}
		}
	}
}
