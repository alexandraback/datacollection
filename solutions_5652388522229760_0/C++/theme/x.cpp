#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define all(a) begin(a),end(a)

typedef long long T;

void solve_case(int case_id);
T calc(T);

int main() {
    int num_case;
    cin >> num_case;
    for (int i=1; i<=num_case; i++)
        solve_case(i);
    return 0;
}

void solve_case(int case_id) {
    T x;
    cin >> x;
    if (x == 0) {
        cout << "Case #" << case_id << ": INSOMNIA\n";
    } else {
        cout << "Case #" << case_id << ": " << calc(x) << '\n';
    }
}

T calc(T x) {
    assert(x > 0);
    vector<bool> found(10, false);
    T multiple = 1;
    for (;;) {
        T curr = x * multiple;
        while (curr != 0) {
            found[curr % 10] = true;
            curr /= 10;
        }
        bool found_all = true;
        for (bool b : found)
            if (!b)
                found_all = false;
        if (found_all)
            return x * multiple;
        multiple++;
    }
}
