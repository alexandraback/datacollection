#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long int64;

class BigInt {
public:
    static const int MAX_DIGITS = 150;
    static const int BASE = 1000000000;

    int digits[MAX_DIGITS];

    BigInt() {
        memset(digits, 0, sizeof(digits));
        digits[0] = 1;
    }

    BigInt(const string &stringDigits) {
        *this = 0;
        for (int i = 0; i < static_cast<int>(stringDigits.length()); ++i)
            *this = *this * 10 + (stringDigits[i] - '0');
    }

    BigInt(int64 value) {
        memset(digits, 0, sizeof(digits));
        for (; value > 0; value /= BASE)
            digits[++digits[0]] = value % BASE;
        if (digits[0] == 0)
            digits[0] = 1;
    }

    BigInt operator=(const BigInt &other) {
        memcpy(digits, other.digits, sizeof(other.digits));
        return *this;
    }

    BigInt operator=(const int64 value) {
        return *this = BigInt(value);
    }

    BigInt operator+(const BigInt &other) const {
        BigInt result = 0;
        int i; int64 t;
        for (i = 1, t = 0; i <= digits[0] || i <= other.digits[0] || t; ++i, t /= BASE)
            result.digits[i] = (t += (digits[i] + other.digits[i])) % BASE;
        result.digits[0] = i - 1;
        return result;
    }

    BigInt operator+(const int64 value) const {
        return *this + BigInt(value);
    }

    BigInt operator+=(const BigInt &other) {
        return *this = *this + other;
    }

    BigInt operator+=(const int64 value) {
        return *this = *this + value;
    }

    BigInt operator*(const BigInt &other) const {
        BigInt result = 0;
        int i, j; int64 t;
        for (i = 1; i <= digits[0]; ++i) {
            for (j = 1, t = 0; j <= other.digits[0] || t; ++j, t /= BASE)
                result.digits[i + j - 1] = (t += (result.digits[i + j - 1] + 1LL * digits[i] * other.digits[j])) % BASE;
            if (i + j - 2 > result.digits[0])
                result.digits[0] = i + j - 2;
        }
        for (; result.digits[0] > 1 && result.digits[result.digits[0]] == 0; --result.digits[0]);
        return result;
    }

    BigInt operator*(const int64 value) const {
        return *this * BigInt(value);
    }

    BigInt operator*=(const BigInt &other) {
        return *this = *this * other;
    }

    BigInt operator*=(const int64 value) {
        return *this = *this * value;
    }

    BigInt operator-(const BigInt &other) const {
        BigInt result = *this;
        int i; int64 t;
        for (i = 1, t = 0; i <= digits[0]; ++i) {
            result.digits[i] -= (other.digits[i] + t);
            result.digits[i] += ((t = (result.digits[i] < 0 ? 1 : 0)) * BASE);
        }
        for (; result.digits[0] > 1 && result.digits[result.digits[0]] == 0; --result.digits[0]);
        return result;
    }

    BigInt operator-(const int64 value) const {
        return *this - BigInt(value);
    }

    BigInt operator-=(const BigInt &other) {
        return *this = *this - other;
    }

    BigInt operator-=(const int64 value) {
        return *this = *this - value;
    }

    BigInt operator/(const int64 value) const {
        BigInt result = *this;
        int i; int64 t;
        for (i = result.digits[0], t = 0; i > 0 ; --i, t %= value)
            result.digits[i] = (t = (t * BASE + result.digits[i])) / value;
        for (; result.digits[0] > 1 && result.digits[result.digits[0]] == 0; --result.digits[0]);
        return result;
    }

    BigInt operator/=(const int64 value) {
        return *this = *this / value;
    }

    int64 operator%(const int64 value) {
        int64 t = 0;
        for (int i = digits[0]; i > 0; --i)
            t = (1LL * t * BASE + digits[i]) % value;
        return t;
    }

    bool operator<(const BigInt &other) const {
        if (digits[0] != other.digits[0])
            return digits[0] < other.digits[0];
        for (int i = digits[0]; i > 0; --i)
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        return false;
    }

    bool operator<=(const BigInt &other) const {
        return !(other < *this);
    }

    bool operator==(const BigInt &other) const {
        return (!(*this < other) && !(other < *this));
    }
};

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int n;
        cin >> n;
        vector< pair<int, int> > hikers;
        for (int i = 0; i < n; ++i) {
            int start, size, speed;
            cin >> start >> size >> speed;
            for (int s = 0; s < size; ++s)
                hikers.push_back(make_pair(s + speed, start));
        }
        sort(hikers.rbegin(), hikers.rend());
        int collisions = 0;
        if (int(hikers.size()) == 2 && hikers[0].first > hikers[1].first) {
            int d = 360 + hikers[0].second - hikers[1].second;
            BigInt c1 = BigInt(hikers[0].first) * BigInt(hikers[0].first - hikers[1].first) * BigInt(360 - hikers[0].second);
            BigInt c2 = BigInt(d) * BigInt(hikers[0].first) * BigInt(hikers[1].first);
            if (c2 <= c1)
                collisions = 1;
        }
        cout << "Case #" << t << ": " << collisions << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
