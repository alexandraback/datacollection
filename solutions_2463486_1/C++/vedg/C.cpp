

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
#include <climits>
#include <cfloat>
#include <cctype>
#include <sstream>


using namespace std;

FILE * fileAns = fopen("all", "r");

FILE * fileOut = fopen("small.out", "w");

FILE * fileInput = fopen("cin", "r");




class Big {
public:
    typedef long long L;
private:
    static const L base, biggest;
    typedef deque<L> Digits;

    Digits d;






    void inc(int startPos = 0) {    // startPos <= d.size()
        int i;
        for (i = startPos; i != d.size(); ++i) {
            if (++d[i] != base)
                return;
            d[i] = 0;
        }
        d.push_back(1);
    }

    void removeStartZeros() {
        while (! d.empty() && d.back() == 0)
            d.pop_back();
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
            } else
                r = 0;
        }
        if (r != 0)
            d.push_back(1);
    }
public:
    Big(char buf[]) {
        int index = strlen(buf);
        do {
            int num = 0;
            int mult = 1;
            for (int i = 0; i < 9; ++i) {
                if (--index < 0)
                    break;
                num += mult * (buf[index] - '0');
                mult *= 10;
            }
            d.push_back(Big::L(num));
        } while (index > 0);
    }

    void operator+=(const Big & n) {
        int size = min(d.size(), n.d.size());
        L r = 0;
        for (int i = 0; i != size; ++i) {
            d[i] += n.d[i] + r;
            if (d[i] >= base) {
                d[i] -= base;
                r = 1;
            } else
                r = 0;
        }
        if (n.d.size() > size)
            d.insert(d.end(), n.d.begin() + size, n.d.end());
        if (r != 0)
            inc(size);
    }

    void operator-=(const Big & n) {    // n <= *this
        L r = 0;
        for (int i = 0; i != n.d.size(); ++i) {
            d[i] -= n.d[i] + r;
            if (d[i] < 0) {
                d[i] += base;
                r = 1;
            } else
                r = 0;
        }
        if (r != 0)
            dec(n.d.size());
        else
            removeStartZeros();
    }

    bool subtract(const Big & n, int startPos = 0) {
        // if (n > *this) { *this is undefined; return false; } else { *this -= n; return true; }
        if (d.size() < n.d.size() + startPos)
            return false;
        L r = 0;
        for (int i = 0; i != n.d.size(); ++i) {
            int j = startPos + i;
            d[j] -= n.d[i] + r;
            if (d[j] < 0) {
                d[j] += base;
                r = 1;
            } else
                r = 0;
        }
        if (r != 0) {
            int j = startPos + n.d.size();
            if (j == d.size())
                return false;
            dec(j);
        } else
            removeStartZeros();
        return true;
    }

    void operator*=(L n) {  // n < base
        L r = 0;
        for (int i = 0; i != d.size(); ++i) {
            d[i] = d[i] * n + r;
            r = d[i] / base;
            d[i] %= base;
        }
        if (r != 0)
            d.push_back(r);
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

    bool operator<(const Big & other) const {
        if (d.size() != other.d.size())
            return d.size() < other.d.size();
        for (int i = d.size() - 1; i >= 0; --i) {
            if (d[i] != other.d[i])
                return d[i] < other.d[i];
        }
        return false;
    }

    bool operator<=(const Big & other) const {
        if (d.size() != other.d.size())
            return d.size() < other.d.size();
        for (int i = d.size() - 1; i >= 0; --i) {
            if (d[i] != other.d[i])
                return d[i] < other.d[i];
        }
        return true;
    }


    void print() const {
        printf("%lld", d.back());
        for (int i = d.size() - 2; i >= 0; --i)
            printf("%09lld", d[i]);
        putchar('\n');
    }
};

const Big::L Big::base = 1E9;
const Big::L Big::biggest = Big::base - 1;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("cin", "r", stdin);
#endif

    static vector<Big> big;
    big.reserve(1E6);

    static char buf[2000];
    while (fscanf(fileAns, " %s", buf) == 1)
        big.push_back(Big(buf));


    cout << "Ready\n!!\n!\n!\n!!!\n" << endl;
    char c;
    cin >> c;



    int cases;
    fscanf(fileInput, "%d", & cases);
    static char buf2[2000];

    for (int cas = 1; cas <= cases; ++cas) {
        fscanf(fileInput, " %s %s", buf, buf2);
        Big a(buf), b(buf2);

        const int ans = upper_bound(big.begin(), big.end(), b) -
        lower_bound(big.begin(), big.end(), a);

        fprintf(fileOut, "Case #%d: %d\n", cas, ans);
    }


#ifndef ONLINE_JUDGE
   // fclose(stdin);
    //putchar('\n');
#endif
}


