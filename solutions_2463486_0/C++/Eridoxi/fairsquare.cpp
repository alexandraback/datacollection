#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <math.h>

// STL
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>

typedef unsigned long long ul;

using namespace std;


bool palindrome(ul n) {
    ul v = n;
    ul rev = 0;
    while (v > 0) {
        rev = (rev * 10) + (v % 10);
        v /= 10;
    }
    return rev == n;
}


int main() {
    int numcase;
    ul A, B, h;

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> A >> B;
        ul count = 0;
        ul cur = (ul) floor(sqrt(A));
        h = cur*cur;
        while (h < A) {++cur; h = cur*cur;}
        while (h <= B) {
            if (palindrome(cur) && palindrome(h)) ++count;
            ++cur;
            h = cur*cur;
        }
        cout << "Case #" << i + 1 << ": " << count << endl;
    }

    return 0;
}
