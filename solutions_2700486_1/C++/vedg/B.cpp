//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>

using namespace std;


class Big {
public:
    typedef long long L;
private:
    static const L base, biggest, notLittle;
    typedef deque<L> Digits;

    //public:////////////////////
    Digits d;

    void inc(int startPos = 0) {    // startPos <= d.size()
        int i;
        for (i = startPos; i != d.size(); ++i) {
            if (++d[i] != base) {
                return;
            }
            d[i] = 0;
        }
        d.push_back(1);
    }

    void removeStartZeros() {
        while (! d.empty() && d.back() == 0) {
            d.pop_back();
        }
    }

    void dec(int startPos = 0) {    // startPos < d.size()
        for (int i = startPos; ; ++i) {
            if (--d[i] >= 0) {
                removeStartZeros();
                return;
            }
            d[i] = biggest;
        }
    }

    void multiplyBy2() {
        L r = 0;
        for (int i = 0; i != d.size(); ++i) {
            d[i] = d[i] * 2 + r;
            if (d[i] >= base) {
                d[i] -= base;
                r = 1;
            }
            else {
                r = 0;
            }
        }
        if (r != 0) {
            d.push_back(1);
        }
    }
public:
    explicit Big(L n) : d(1, n) {}
    Big() {}

    void operator+=(const Big & n) {
        int size = min(d.size(), n.d.size());
        L r = 0;
        for (int i = 0; i != size; ++i) {
            d[i] += n.d[i] + r;
            if (d[i] >= base) {
                d[i] -= base;
                r = 1;
            }
            else {
                r = 0;
            }
        }
        if (n.d.size() > size) {
            d.insert(d.end(), n.d.begin() + size, n.d.end());
        }
        if (r != 0) {
            inc(size);
        }
    }

    void operator-=(const Big & n) {    // n <= *this
        L r = 0;
        for (int i = 0; i != n.d.size(); ++i) {
            d[i] -= n.d[i] + r;
            if (d[i] < 0) {
                d[i] += base;
                r = 1;
            }
            else {
                r = 0;
            }
        }
        if (r != 0) {
            dec(n.d.size());
        }
        else {
            removeStartZeros();
        }
    }

    bool subtract(const Big & n, int startPos = 0) {
        // if (n > *this) { *this is undefined; return false; } else { *this -= n; return true; }
        if (d.size() < n.d.size() + startPos) {
            return false;
        }
        L r = 0;
        for (int i = 0; i != n.d.size(); ++i) {
            int j = startPos + i;
            d[j] -= n.d[i] + r;
            if (d[j] < 0) {
                d[j] += base;
                r = 1;
            }
            else {
                r = 0;
            }
        }
        if (r != 0) {
            int j = startPos + n.d.size();
            if (j == d.size()) {
                return false;
            }
            dec(j);
        }
        else {
            removeStartZeros();
        }
        return true;
    }

    void operator*=(L n) {  // n < base
        L r = 0;
        for (int i = 0; i != d.size(); ++i) {
            d[i] = d[i] * n + r;
            r = d[i] / base;
            d[i] %= base;
        }
        if (r != 0) {
            d.push_back(r);
        }
    }

    void operator*=(const Big & n) {
        Big original = *this;
        d.clear();
        for (int i = n.d.size() - 1; i >= 0; --i) {
            Big cur = original;
            cur *= n.d[i];
            d.push_front(0);
            *this += cur;
        }
    }

    void divide(L n, L & reminder) {
        reminder = 0;
        for (int i = d.size() - 1; i >= 0; --i) {
            d[i] += reminder * base;
            reminder = d[i] % n;
            d[i] /= n;
        }
        removeStartZeros();
    }

    void divide(const Big & n, Big & reminder) {
        //reminder.d.clear();
        L divisor = n.d.back();
        Digits result;
        if (n.d.size() == 1) {
            L rem = 0;
            int index = d.size();
            do {
                rem = rem * base + d[--index];
                result.push_front(rem / divisor);
                rem %= divisor;
            }
            while (index != 0);
            reminder.d.push_back(rem);
        }
        else {
            divisor = divisor * base + n.d[n.d.size() - 2];
            L rem = d.back();
            int index = d.size() - 1;
            do {
                L k;
                if (rem > notLittle) {
                    long double remD = (long double)rem * base + d[--index];
                    k = remD / divisor;
                }
                else {
                    rem = rem * base + d[--index];
                    if (rem < divisor) {
                        result.push_front(0);
                        continue;
                    }
                    k = rem / divisor;
                }
                Big cur = n;
                cur *= k;
                int startPos;
                while (true) {
                    Big tmp = *this;
                    startPos = index + 2 - n.d.size();
                    if (startPos < 0) {
                        break;
                    }
                    if (tmp.subtract(cur, startPos)) {
                        *this = tmp;
                        result.push_front(k);
                        if (d.size() >= n.d.size()) {
                            rem = d.back();
                            int i = d.size() - 1;
                            if (index < i) {
                                rem = rem * base + d[index];
                            }
                            else {
                                while (index > i) {
                                    result.push_front(0);
                                    --index;
                                }
                            }
                        }
                        break;
                    }
                    if (--k == 0) {
                        result.push_front(0);
                        break;
                    }
                    cur -= n;
                }
                if (d.size() < n.d.size() || startPos < 0) {
                    break;
                }
            }
            while (index != 0);
            reminder = *this;
        }
        d = result;
        removeStartZeros();
    }

    bool operator<(const Big & other) const {
        if (d.size() != other.d.size()) {
            return d.size() < other.d.size();
        }
        for (int i = d.size() - 1; i >= 0; --i) {
            if (d[i] != other.d[i]) {
                return d[i] < other.d[i];
            }
        }
        return false;
    }

    bool operator<=(const Big & other) const {
        if (d.size() != other.d.size()) {
            return d.size() < other.d.size();
        }
        for (int i = d.size() - 1; i >= 0; --i) {
            if (d[i] != other.d[i]) {
                return d[i] < other.d[i];
            }
        }
        return true;
    }

    void sqrt() {
        long double n = 0;
        int end = min(4, int(d.size()));
        if (end == 4 && (d.size() - end) % 2 != 0) {
            ++end;
        }
        for (int i = 1; i <= end; ++i) {
            n = n * base + d[d.size() - i];
        }
        n = std::sqrt(n);
        if (d.size() <= 2) {
            d.resize(1);
            d.back() = L(n);
            return;
        }
        Big x;
        do {
            long double cur = floor(n / base);
            x.d.push_back(n - cur * base);
            n = cur;
        }
        while (n != 0);
        end = (d.size() + 1) / 2;
        while (x.d.size() != end) {
            x.d.push_front(0);
        }
        while (true) {
            Big xSqr = x;
            xSqr *= x;
            Big res = *this;
            bool good = res.subtract(xSqr);
            Big xMult2 = x;
            xMult2.multiplyBy2();
            if (good && res <= xMult2) {
                *this = x;
                return;
            }
            Big rem;
            if (good) {
                res.divide(xMult2, rem);
                rem.multiplyBy2();
                if (xMult2 < rem) {
                    x.inc();
                }
                x += res;
            }
            else {
                xSqr -= *this;
                xSqr.divide(xMult2, rem);
                rem.multiplyBy2();
                if (xMult2 < rem || xSqr.d.empty()) {
                    x.dec();
                }
                x -= xSqr;
            }
        }
    }

    void print() const {
        printf("%lld", d.back());
        for (int i = d.size() - 2; i >= 0; --i) {
            printf("%09lld", d[i]);
        }
        putchar('\n');
    }
};

const Big::L Big::base = 1E9;
const Big::L Big::biggest = Big::base - 1;
const Big::L Big::notLittle = 9223372035;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("large.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        int n, x, y;
        cin >> n >> x >> y;
        x = abs(x);
        int level, k = 1;//level=x+y
        for (level = 0; n >= k; level += 2, k += 4) {
            n -= k;
        }
        long double ans;
        if (x + y < level) {
            ans = 1;
        }
        else if (x + y > level || x == 0) {
            ans = 0;
        }
        else {
            int left = n, space = k;
            int filled = left - space / 2;
            if (y < filled) {
                ans = 1;
            }
            else {
                filled = max(filled, 0);
                left -= filled * 2;
                int needed = y - filled + 1;
                if (needed > left) {
                    ans = 0;
                }
                else {
                    n = left;
                    Big nom(0), cur(1);
                    for (int i = 0; i <= n; ++i) {
                        if (needed <= i) {
                            nom += cur;
                        }
                        cur *= (n - i);
                        Big::L rem;
                        cur.divide(i + 1, rem);
                        if (rem != 0) {
                            throw "rem!=0";
                        }
                    }

                    ans = 0;
                    Big::L rem;
                    //long double t = 0;
                    for (int i = 0; i < n; ++i) {
                        nom.divide(2, rem);
                        if (rem > 0) {
                            ++ans;
                        }
                        ans /= 2;
                    }
                }
            }
        }


        cout << "Case #" << cas << ": ";
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(10);
        cout << ans << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}

