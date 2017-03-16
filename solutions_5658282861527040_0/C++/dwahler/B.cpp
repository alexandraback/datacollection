// CPPFLAGS=-std=gnu++11 -O3

#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int T = 1; T <= numCases; T++) {
        int A, B, K;
        cin >> A >> B >> K;

        int total = 0;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if ((i & j) < K) {
                    total++;
                }
            }
        }

        cout << "Case #" << T << ": ";
        cout << total;
        cout << endl;
    }
}
