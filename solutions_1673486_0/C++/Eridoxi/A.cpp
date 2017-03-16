#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>

// STL
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>

int A, B;
double * probs;
double * prod;

using namespace std;

double keystrokes_give_up() {
    return 1 + B + 1;
}

double solve(int k, int num_back) {
    if (k == 0)
        return B+1+num_back;

    double var = solve(k-1,num_back+1);
    double finish = prod[k-1] * (num_back+B-k+1) + (1-prod[k-1]) * (num_back+B-k+1+B+1);
    var = var > finish ? finish : var;
    return var;
}


int main() {
    int numcase;

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);

    cout.unsetf(ios::floatfield);
    cout.precision(9);
    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> A >> B;
        cout << "Case #" << i + 1 << ": ";
        probs = new double[A];
        prod = new double[A];
        double tmp;
        double pred = 1;
        for (int i = 0; i < A; ++i) {
            cin >> tmp;
            probs[i] = tmp;
            pred *= tmp;
            prod[i] = pred;
        }
        double var = solve(A, 0);
        double down = keystrokes_give_up();
        var = var > down ? down : var;
        cout << var << endl;
        delete [] probs;
        delete [] prod;
    }

    return 0;
}
