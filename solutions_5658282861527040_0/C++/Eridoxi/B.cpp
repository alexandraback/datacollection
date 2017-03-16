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

#define SIZE 1000

int A, B, K;
int input[SIZE];

int solve() {
    int cnt = 0;
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            if ((i & j) < K) ++cnt;
        }
    }
    return cnt;
}


int main() {
    int numcase;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> A >> B >> K;
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }

    return 0;
}
