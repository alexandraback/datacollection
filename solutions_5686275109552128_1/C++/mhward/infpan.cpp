#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int reduce_cost(int n, int to) {
    return n / to - (n%to == 0);
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int d;
        cin >> d;
        vector<int> pans;
        int max_elem = - 1;
        for (int i = 0; i < d; ++i) {
            int tmp;
            cin >> tmp;
            pans.push_back(tmp);
            if (tmp > max_elem)
                max_elem = tmp;
        }
        int best = max_elem;
        for (int i = 2; i < max_elem; ++i) {
            int sum = i;
            for (auto e: pans)
                sum += reduce_cost(e, i);
            if (sum < best)
                best = sum;
        }
        cout << "Case #" << tc << ": " << best << endl;
    }
}
