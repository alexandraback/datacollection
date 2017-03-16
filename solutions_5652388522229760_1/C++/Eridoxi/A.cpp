#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>

// STL
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>

using namespace std;

typedef unsigned long long ul;
typedef long long ll;

#define SIZE 4

long long input1[SIZE];
const long long target = (1 << 10) - 1;

long long solve(int num) {
    long long mask = 0;
    long long res = 0, r, current = 0;
    
    //cout << target << endl;
    while (mask != target) {
        res = current += num;
        while (res != 0) {
            r = res % 10;
            res /= 10;
            mask |= (1 << r);
        }
        //cout << mask << endl;
    }
    return current;
}


int main() {
    long long numcase, n;

    //freopen("exA", "r", stdin);
    //freopen("resA", "w", stdout);
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    cin >> numcase;
    for (long long i = 0; i < numcase; ++i) {
        cin >> n;
        cout << "Case #" << i + 1 << ": ";
        
        if (n == 0) {
            cout << "INSOMNIA";
        } else {
            cout << solve(n);
        }
        cout << endl;
    }

    return 0;
}
