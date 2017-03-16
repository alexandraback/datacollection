#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void do_testcase() {
    unsigned long int A, N, t, max = 0;
    cin >> A >> N;
    priority_queue<unsigned long int, vector<unsigned long int>, greater<unsigned long int> > sizes;
    for (unsigned long int i = 0; i < N; ++i) {
        cin >> t;
        if (t > max) {
            max = t;
        }
        sizes.push(t);
    }
    while (!sizes.empty() && sizes.top() < A) {
        A += sizes.top();
        sizes.pop();
    }
    unsigned long int op = 0;
    unsigned long int bestOp = sizes.size();
    while (max >= A && op < bestOp) {
        ++op;
        A += A - 1;
        while (!sizes.empty() && sizes.top() < A) {
            A += sizes.top();
            sizes.pop();
        }
        if (op + sizes.size() < bestOp) {
            bestOp = op + sizes.size();
        }
    }
    cout << bestOp;
}

int main(int argc, char *argv[]) {
    unsigned long int T;
    cin >> T;
    for (unsigned long int i = 0; i < T; ++i) {
        cout << "Case #" << (i + 1) << ": ";
        do_testcase();
        cout << endl;
    }
}
