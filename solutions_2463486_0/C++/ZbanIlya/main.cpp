#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <iomanip>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int base = 1000000000;
const int base_digits = 9;

struct bigint {
    vector<int> a;
    int sign;

    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

bool is_palyn(ll x) {
	string s;
	stringstream ss;
	ss << x;
	ss >> s;
	for (int i = 0; i < (int)s.length() - i - 1; i++)
		if (s[i] != s[s.length() - i - 1])
			return 0;
	return 1;
}

bool is_palyn(string s) {
	for (int i = 0; i < (int)s.length() - i - 1; i++)
		if (s[i] != s[s.length() - i - 1])
			return 0;
	return 1;
}

void analyze() {
	vector<ll> v;
	for (ll i = 1; i <= 100000000; i++)
		if (is_palyn(i) && is_palyn(i * i))
			v.push_back(i);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	exit(0);
}

ll d[128][16];

void precalc() {

}

ll dp(int x, int y) {
	if (y >= 10) return 0;
	if (d[x][y] != -1) return d[x][y];
	if (!x) return 1;
	d[x][y] = 0;
	for (int i = 0; y + i * i + i * i * (x != 1) < 10; i++)
		d[x][y] += dp(x - 1 - (x != 1), y + i * i + i * i * (x != 1));
	return d[x][y];
}

bool anothercheck(string s) {
	//for (int i = 0; i < (int)s.length() - i - 1; i++)
	//	if (s[i] > s[(int)s.length() - i - 1])
	for (int i = ((int)s.length() - 1) / 2; i >= 0; i--) 
		if (s[i] != s[(int)s.length() - i - 1])
			return s[i] < s[(int)s.length() - i - 1];
	return 1;
}

ll solve(string s) {
	if (s == "0") return 0;
	ll res = 0;
	for (int i = 1; i < s.length(); i++)
		for (int j = 1; j <= 3; j++)
			res += dp(i - 1 - (i != 1), j * j + j * j * (i != 1));
	
	bool fl = 0;
	string S = "";
	int csum = 0, lastlen = s.length();
	for (int i = 0; i <= (int)s.length() - i - 1; i++) {
		int k = (s[i] - '0') - (i == 0);
		int j; 
		for (j = (i == 0); csum + (j+1) * (j+1) + (j+1) * (j+1) * (i != (int)s.length() - i - 1) < 10 && (('0' + j) < s[i] || fl); j++)
			res += dp(lastlen - 1 - (i != (int)s.length() - i - 1), csum + j * j + j * j * (i != (int)s.length() - i - 1));
		lastlen -= 1 + (i != (int)s.length() - i - 1);
		
		csum += j * j + j * j * (i != (int)s.length() - i - 1);
		if (csum >= 10) break;
		S += (char)('0' + j);
		fl |= ('0' + j) < s[i];

		if (i == ((int)s.length() - i - 1) || i + 1== ((int)s.length() - i - 1)) {
			for (int j = S.length() - 1 - (s.length() & 1); j >= 0; j--)
				S += S[j];
			res += S <= s;
		}
	}
	return res;
}

bigint sqrt(bigint x) {
	bigint l = 0, r; r.read("10000000");//r.read("1000000000000000000000000000000000000000000000000000"); //
	while (r - l > 1) {
		bigint m = (l + r) / 2;
		if (m * m <= x)
			l = m;
		else
			r = m;
	}
	if (r * r <= x) return r;
	return l;
}

string write(bigint x) {
	string res = "";
	for (int i = 0; i < x.a.size(); i++) {
		string s = "";
		int y = x.a[i];
		while (y) {
			s = (char)('0' + y % 10) + s;
			y /= 10;
		}
		while (i + 1 < x.a.size() && s.length() < 9)
			s = '0' + s;
		res = s + res;
	}
	if (res == "") res = "0";
	return res;
}

bool good(string s) {
	int res = 0;
	for (int i = 0; i < s.length(); i++)
		res += (s[i] - '0') * (s[i] - '0');
	return res < 10;
}

ll fastsolve(string l, string r) {
	bigint L, R, x;
	L.read(l);
	R.read(r);
	x.read(l);
	L = sqrt(L);
	if (L * L == x) L -= 1;
	x.read(r);
	R = sqrt(R);
	l = write(L);
	r = write(R);
	ll ans = solve(r) - solve(l);// + (is_palyn(l) && good(l));
	return ans;
}

ll Rand() {
	return (((ll)rand()) << 47) + (((ll)rand()) << 31) + (((ll)rand()) << 15) + rand();
}

string tostr(ll x) {
	string s;
	stringstream ss;
	ss << x;
	ss >> s;
	return s;
}

ll toll(string s) {
	ll x;
	stringstream ss;
	ss << s;
	ss >> x;
	return x;
}

ll slowsolve(string l, string r) {
	ll b[48] = {1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 10000001, 10011001, 10100101, 10111101, 11000011, 11011011, 11100111, 11111111, 20000002};
	ll L = toll(l), R = toll(r);
	int ans = 0;
	for (int i = 0; i < 48; i++) {
		if (1LL * b[i] * b[i] >= L)
			if (1LL * b[i] * b[i] <= R)
				ans++;
	}
	return ans;
}

void stress() {
	for (int it = 0; it < 100000; it++) {
		ll L = Rand() % ((ll)1e14) + 1;
		ll R = Rand() % ((ll)1e14) + 1;
		if (L > R) swap(L, R);
		string l = tostr(L), r = tostr(R);
		
		ll ans = fastsolve(l, r);
		ll ans2= slowsolve(l, r);

		if (ans != ans2 && !ans2) {
			cout << l << " " << r << endl;
			exit(0);
		}
		cerr << it << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(d, -1, sizeof(d));
	//analyze();
	//precalc();
	//stress();

	int tests;
    cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";

		string l, r;
		cin >> l >> r;
		
		ll ans = fastsolve(l, r);
		ll ans2= slowsolve(l, r);

		cout << ans;
		//cout << " " << ans2;
		cout << endl;
	}

	return 0;
}