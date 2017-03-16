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

#define SIZE 1000000

long A;
int N;
long input[SIZE];

int solve(int i, int ins) {
    while (i < N) {
        if (input[i] < A) A+=input[i];
        else {
            A += A-1;
            return min(ins+N-i, solve(i, ins+1));
        }
        ++i;
    }
    return ins;
}


int main() {
    int numcase;

    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> A >> N;
        memset(input, 0, sizeof(int)*N);
        for  (int j = 0; j < N; ++j) {
            cin >> input[j];
        }
        if (A >= 2) {
            sort(input, input+N);
            cout << "Case #" << i + 1 << ": " << solve(0, 0) << endl;
        } else {
            cout << "Case #" << i + 1 << ": " << N << endl;
        }
    }

    return 0;
}
