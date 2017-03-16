#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <utility>
#include <numeric>
#include <string.h>

using namespace std;

typedef unsigned long long ulong;
typedef unsigned int uint;
typedef long long int64;


inline ulong max(ulong a, ulong b) {
    return a > b ? a : b;
}

inline ulong min(ulong a, ulong b) {
    return a < b ? a : b;
}

const size_t MAX = 1000000;
ulong nums[MAX + 10];

inline ulong flip(ulong a) {
    ulong res = 0;
    while (a != 0) {
        res = res * 10 + a % 10;
        a /= 10;
    }
    return res;
}

void precalc() {
    nums[1] = 1;
    for (ulong i = 2; i <= MAX; ++i) {
        ulong flipped = flip(i);
        if (flipped < i && flip(flipped) == i) {
            //if (nums[flipped] < nums[i-1])
            //    //cerr << i << endl;
            nums[i] = min(nums[flipped] + 1, nums[i-1] + 1);
        } else {
            nums[i] = nums[i-1] + 1;
        }
        ////cerr << "i: " << i << ", flipped: " << flipped << ", nums[flipped] = " << (flipped < i ? 0 : nums[flipped]) << ", nums[i-1] = " << nums[i-1] << ", nums[i] = " << nums[i] << endl;
    }
}

ulong numDigits(ulong n) {
    ulong res = 0;
    while (n != 0) {
        ++res;
        n/=10;
    }
    return res;
}

bool isBad(ulong n, ulong d) {
    //cerr << "isBad: n = " << n << endl;
    ulong half = (d+1)/2;
    for (ulong i = 0; i < half; ++i) {
        n /= 10;
    }

    //cerr << "isBad: check " << n << endl; 
    for (ulong i = 0; i < (d - half) - 1; ++i) {
        //cerr << "isBad: i = " << i << ", n = " << n << endl;
        if (n % 10 != 0)
            return false;
        n /= 10;
    } 

    return n == 1;
}

ulong gen9(ulong d) {
    ulong res = 9;
    for (ulong i = 1; i < d; ++i)
        res = res*10 + 9;
    return res;
}

ulong toFlip(ulong n) {
    //ulong n1 = n;
    if (n%10 == 0)
        --n;
    ulong res = 1;
    ulong d = numDigits(n);
    if (isBad(n, d)) {
        //cerr << n << " is bad\n";
        n = gen9(d - 1);
        //cerr << "now n = " << n << "\n";
        d -= 1;
    }
    n /= 10;
    ulong digit = 1;

    for (ulong i = 1; i < d; ++i) {
        digit *= 10;
        if (i >= (d+1) / 2)
            res += digit * (n % 10);
        n /= 10;
    }

    //if (res == n1)
    //    return toFlip(n1 - 1);
    return res; 
}

ulong smartCalc(ulong n) {
    if (n <= 20)
        return n;

    ulong res = 0;

    ulong tf = toFlip(n);

    res += n - tf;

    ulong flipped = flip(tf);
    res += 1;
    //cerr << "n == " << n << ", toflip = " << tf << ", flipped = " << flipped << ", res = " << res << endl;

    res += smartCalc(flipped);
    //cerr << "totalRes = " << res << endl;


    return res;
}




int main() {
    //cout << flip(1) << ' ' << flip(2) << ' ' << flip(10) << ' ' << flip(19) << ' ' << flip(2300) << ' ' << flip(23456) << endl;
    //cout << numDigits(1) << ' ' << numDigits(20) << ' ' << numDigits(123) <<  endl;
    //cout << toFlip(29) << ' ' << toFlip(2345) << ' ' << toFlip(23456) << ' ' << toFlip(234) << endl;
    //cout << toFlip(1123) << endl;
    //cout << toFlip(1101) << endl;
    //cout << toFlip(1100) << endl;
    //cout << toFlip(1099) << endl;
    //cout << toFlip(11099) << endl;
    //cout << toFlip(109) << endl;
    //return 0;
    //precalc();
    ulong numTests = 0;
    cin >> numTests;
    for (ulong t = 1; t <= numTests; ++t) {
        ulong n;
        cin >> n;
        //cout << "Case #" << t << ": " << nums[n] << endl;
        cout << "Case #" << t << ": " << smartCalc(n) << endl;
    }
    return 0;
}

