#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "utility/type/ll.hpp"
#include "utility/range.hpp"
using namespace std;
int digits(ll x) {
    int d = 0;
    ll y = 1;
    while (y <= x) {
        d += 1;
        y *= 10;
    }
    return d;
}
ll reverse(ll x) {
    ll y = 0;
    while (x) {
        y *= 10;
        y += x % 10;
        x /= 10;
    }
    return y;
}
ll flippoint(int d) {
    ll x = 1;
    for (int i : range((d+1)/2-1)) x *= 10;
    for (int i : range(d/2)) x = x*10 + 9;
    return x;
}
ll powi(ll x, int y) {
    ll z = 1;
    for (int i : range(y)) z *= x;
    return z;
}
ll upper_digits_in(ll x) {
    return x / powi(10,digits(x)/2);
}
ll lower_digits_ex(ll x) {
    return x % powi(10,digits(x)/2);
}
ll upper_digits_ex(ll x) {
    return x / powi(10,(digits(x)+1)/2);
}
ll lower_digits_in(ll x) {
    return x % powi(10,(digits(x)+1)/2);
}
ll filled(int a, int d) {
    ll y = 0;
    for (int i : range(d)) {
        y *= 10;
        y += a;
    }
    return y;
}

ll smallest_pow10(int d) {
    ll n = powi(10,d);
    ll x = 1;
    ll y = 1;
    while (true) {
        ll z = flippoint(digits(x)+1);
        if (n < reverse(z)) break;
        y += z - x; x = z;
        assert (reverse(x) != x);
        y += 1; x = reverse(x);
    }
    y += n - x;
    x = n;
    return y;
}

ll solve(ll n) {
    if (n <= 20) return n;
    ll x = powi(10,digits(n)-1);
    ll y = smallest_pow10(digits(n)-1);
    assert (digits(x) == digits(n));
    ll un = upper_digits_in(n);
    ll ln = lower_digits_ex(n);
    ll run = reverse(un);
    if (x == n) return y;
    if (ln) {
        if (run != 1) {
            y += run; x += run;
            if (reverse(x) != x) { y += 1; x = reverse(x); }
        }
        ll z = (x % 10 == 1) ? ln - 1 : ln;
        y += z; x += z;
    } else {
        if (10 <= run) {
            assert (run != 1);
            if (reverse(x+run) <= n) {
                y += run; x += run;
                if (reverse(x) != x) { y += 1; x = reverse(x); }
                y += n - x; x = n;
            } else {
                ll z = reverse(un - 1);
                y += z; x += z;
                if (reverse(x) != x) { y += 1; x = reverse(x); }
cerr << n << "\t" << x << "\t" << y << endl;
                y += n - x; x = n;
            }
        } else {
            assert (run <= 9);
            ll z = filled(9,digits(n)/2) / 10 * 10 + run-1;
            y += z; x += z;
            if (reverse(x) != x) { y += 1; x = reverse(x); }
            y += n - x; x = n;
        }
    }
    return y;
}

int main() {
    assert (digits(0) == 0);
    assert (digits(9) == 1);
    assert (digits(10) == 2);
    assert (digits(99) == 2);
    assert (digits(100) == 3);
    assert (reverse(123456789123456789ll) == 987654321987654321ll);
    assert (reverse(2300) == 32);
    assert (reverse(32) == 23);
    assert (flippoint(2) == 19);
    assert (flippoint(3) == 109);
    assert (flippoint(4) == 1099);
    assert (flippoint(5) == 10099);
    assert (flippoint(6) == 100999);
    assert (powi(10,digits(123)-1) == 100);
    assert (upper_digits_ex(123456) == 123);
    assert (lower_digits_in(123456) == 456);
    assert (upper_digits_in(123456) == 123);
    assert (lower_digits_ex(123456) == 456);
    assert (upper_digits_ex(1234567) == 123);
    assert (lower_digits_in(1234567) == 4567);
    assert (upper_digits_in(1234567) == 1234);
    assert (lower_digits_ex(1234567) == 567);
    assert (lower_digits_ex(10) == 0);
    assert (upper_digits_ex(10) == 1);
    assert (lower_digits_in(10) == 0);
    assert (upper_digits_in(10) == 1);
    ios_base::sync_with_stdio(false);
    for (int testcase : range(cin)) {
        ll n; cin >> n;
        cout << "Case #" << testcase+1 << ": " << solve(n) << endl;
    }
    return 0;
}
