#include <cstdio>
#include <cassert>

typedef long long ll;

int numberOfDigits(ll x) {
    int res = 0;
    while (x > 0) {
        x /= 10;
        ++res;
    }
    return res;
}

ll reverse(ll x) {
    ll res = 0;
    while (x > 0) {
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

ll firstHalf(ll x, int incl) {
    int length = numberOfDigits(x);
    ll res = 0;
    int pow = 1;
    //printf("FIrst half of %Ld with %d\n", x, incl);
    for (int i = 0; i < (length + incl) / 2; ++i) {
        res += pow * (x % 10);
        //printf("_%Ld\n", res);
        x /= 10;
        pow *= 10;
    }
    return res;
}

ll allNines(int length) {
    ll res = 0;
    for (int i = 0; i < length; ++i) {
        res *= 10;
        res += 9;
    }
    return res;
}

void moveFirstTo(ll &number, ll &counter, int incl, ll dest) {
    //printf("MOVING FIRST %Ld to %Ld\n", number, dest);
    ll diff =  dest - firstHalf(number, incl);
    assert(diff >= 0);
    number += diff;
    counter += diff;
}

void getSomething(ll &number, ll &counter, ll dest) {
    //printf("GETTING FROM %Ld to %Ld\n", number, dest);
    if (firstHalf(reverse(dest), 0) == firstHalf(reverse(number), 0)) {
        moveFirstTo(number, counter, 1, firstHalf(dest, 1));
    } else {
        //printf("... %Ld %Ld\n", reverse(dest), firstHalf(reverse(dest), 1));
        moveFirstTo(number, counter, 1, firstHalf(reverse(dest), 1));
        ++counter;
        number = reverse(number);
        moveFirstTo(number, counter, 0, firstHalf(dest, 0));
        //printf("GOT %Ld %Ld\n", number, dest);
    }
}

void getAllNines(ll &number, ll &counter) {
    getSomething(number, counter, allNines(numberOfDigits(number)));
}

void incr(ll &number, ll &counter, int amount) {
    number += amount;
    counter += amount;
}

void testCase(int t) {
    ll x;
    scanf("%Ld", &x);
    bool incrementAfter = false;
    if (x % 10 == 0) {
        --x;
        incrementAfter = true;
    }
    ll counter = 1;
    ll number = 1;
    while (numberOfDigits(number) < numberOfDigits(x)) {
        getAllNines(number, counter);
        //printf("-> %Ld %Ld\n", number, counter);
        incr(number, counter, 2);
    }
    getSomething(number, counter, x);
    if (incrementAfter)
        incr(number, counter, 1);
    printf("Case #%d: %Ld\n", t, counter);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        testCase(i);
}