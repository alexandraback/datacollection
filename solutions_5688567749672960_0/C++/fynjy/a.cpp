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
        if (flipped < i && flip(flipped) == i)
            nums[i] = min(nums[flipped] + 1, nums[i-1] + 1);
        else
            nums[i] = nums[i-1] + 1;
        //cerr << "i: " << i << ", flipped: " << flipped << ", nums[flipped] = " << (flipped < i ? 0 : nums[flipped]) << ", nums[i-1] = " << nums[i-1] << ", nums[i] = " << nums[i] << endl;
    }
}

int main() {
    //cout << flip(1) << ' ' << flip(2) << ' ' << flip(10) << ' ' << flip(19) << ' ' << flip(2300) << ' ' << flip(23456) << endl;
    precalc();
    ulong numTests = 0;
    cin >> numTests;
    for (ulong t = 1; t <= numTests; ++t) {
        ulong n;
        cin >> n;
        cout << "Case #" << t << ": " << nums[n] << endl;
    }
    return 0;
}

