#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cmath>

// STL
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
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

#define SIZE 100

bool coin[SIZE];
bool tmp_coin[SIZE];
string input;

void print_coin() {
    for (unsigned i=0; i < input.size(); ++i) {
        cout << (coin[i] ? '+':'-');
    }
    cout << endl;
}

void flip(int n) {
    for (int i = 0; i <= n; ++i) {
        tmp_coin[i] = !coin[i];
    }
    for (int i = 0; i <= n; ++i) {
        coin[n - i] = tmp_coin[i];
    }
}

int revert(int set) {
    int idx = 0;
    while(coin[idx] && idx <= set) {
        ++idx;
    }
    for(int i = 0; i < idx; ++i) {
        coin[i] = 0;
    }

    flip(set);
    if (idx == 0) return 1;
    return 2;
}

int solve() {
    int count = 0;
    int set = input.size() - 1;

    while (set >= 0) {
        //print_coin();
        if (!coin[set]) {
            count += revert(set);
        }
        --set;
    }

    return count;
}

void init() {
    int s = input.size();
    for (int i=0; i < s; ++i) {
        coin[i] = (input[i] == '+') ? 1 : 0;
    }
}

int main() {
    int numcase;

    //freopen("exB", "r", stdin);
    //freopen("workfile", "r", stdin);
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> input;
        init();
        cout << "Case #" << i + 1 << ": ";
        //cout << setprecision(7) << fixed;
        cout << solve() << endl;
    }

    return 0;
}
