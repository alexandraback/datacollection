#include <fstream>
#include <cstdint>

using namespace std;

const int MAXLEN = 10000;

class BigInteger {
public:
        int len, s[MAXLEN];

        BigInteger() { (*this) = 0; };
        BigInteger(int64_t inte) { (*this) = inte; };

        friend ostream& operator<<(ostream &cout, const BigInteger &x);

        BigInteger operator=(int64_t inte);
        BigInteger operator+(const BigInteger &b);
        BigInteger operator-(const BigInteger &b);
        BigInteger operator*(const BigInteger &b);
        BigInteger operator/(const BigInteger &b);
        int compare(const BigInteger &b);
};

ostream& operator<<(ostream &cout, const BigInteger &x) {
        for (int i = x.len; i >= 1; --i)
                cout << x.s[i];
        return cout;
}

BigInteger BigInteger::operator=(int64_t inte) {
        if (inte == 0) {
                len = 1;
                s[1] = 0;
                return (*this);
        };
        for (len = 0; inte > 0; ) {
                s[++len] = inte % 10;
                inte /= 10;
        };
        return (*this);
}

BigInteger BigInteger::operator+(const BigInteger &b) {
        int i;
        BigInteger c;
        c.s[1] = 0;
        for (i = 1; i <= len || i <= b.len || c.s[i]; i++) {
                if (i <= len) c.s[i] += s[i];
                if (i <= b.len) c.s[i] += b.s[i];
                c.s[i+1] = c.s[i] / 10;
                c.s[i] %= 10;
        }
        c.len = i - 1;
        if (c.len == 0) c.len=1;
        return c;
}

BigInteger BigInteger::operator-(const BigInteger &b) {
        int i, j;
        BigInteger c;
        for (i = 1, j = 0; i <= len; ++i) {
                c.s[i] = s[i] - j;
                if (i <= b.len) c.s[i] -= b.s[i];
                if (c.s[i] < 0) {
                        j = 1;
                        c.s[i] += 10;
                } else {
                        j = 0;
                }
        }
        c.len = len;
        while (c.len > 1 && !c.s[c.len])
                --c.len;
        return c;
}

BigInteger BigInteger::operator*(const BigInteger &b)  {
        int i ,j;
        BigInteger c;
        c.len = len + b.len;
        for (i = 1; i <= c.len; ++i) c.s[i] = 0;
        for (i = 1; i <= len ; ++i)
                for (j = 1; j <= b.len ; ++j)
                        c.s[i + j - 1] += s[i] * b.s[j];
        for (i = 1; i < c.len; ++i) {
                c.s[i + 1] += c.s[i] / 10;
                c.s[i] %= 10;
        }
        while(c.s[i]) {
                c.s[i + 1] = c.s[i] / 10;
                c.s[i] %= 10;
                ++i;
        }
        while(i >1 && !c.s[i] ) --i;
        c.len = i;
        return c;
}

BigInteger BigInteger::operator/(const BigInteger &b) {
        int i, j;
        BigInteger d(0), c;
        for (i = len; i > 0; --i) {
                if (!(d.len == 1 && d.s[1] == 0)) {
                        for (j = d.len; j > 0; --j)
                                d.s[j + 1] = d.s[j];
                        ++d.len;
                }
                d.s[1] = s[i];
                c.s[i] = 0;
                while((j = d.compare(b)) >= 0) {
                        d = d - b;
                        ++c.s[i];
                        if (j == 0) break;
                }
        }
        c.len = len;
        while((c.len > 1) && (c.s[c.len] == 0))
                --c.len;
        return c;
}

int BigInteger::compare(const BigInteger &y) {
        if (len > y.len) return 1;
        if (len < y.len) return -1;
        int i = len;
        while ((i > 1) && (s[i] == y.s[i]))
                --i;
        return s[i] - y.s[i];
}

bool check(BigInteger r, BigInteger t, BigInteger n) {
        BigInteger a0 = r * 2 + 1;
        BigInteger an = a0 + (n - 1) * 4;
        BigInteger req = (a0 + an) * n / 2;
        if (t.compare(req) < 0)
                return false;
        return true;
}

int main() {
        ifstream fin("A-large.in");
        ofstream fout("A-large.out");
        int T;
        fin >> T;
        for (int casenum = 1; casenum <= T; ++casenum) {
                int64_t r, t;
                fin >> r >> t;
                BigInteger rr = r, tt = t;
                BigInteger low = 0, high = t, mid;
                while (low.compare(high) < 0) {
                        mid = (low + high + 1) / 2;
                        if (check(rr, tt, mid))
                                low = mid;
                        else
                                high = mid - 1;
                }
                fout << "Case #" << casenum << ": " << low << '\n';
        }
        fin.close();
        return 0;
}