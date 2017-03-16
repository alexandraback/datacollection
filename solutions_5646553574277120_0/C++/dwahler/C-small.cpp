#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <functional>
#include <cstdint>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

#define D(x)

using namespace std;

bool is_valid(const set<int>& coins, int V) {
    vector<bool> possible(V+1);
    possible[0] = true;

    for (int coin : coins) {
        for (int i = V-1; i >= 0; i--) {
            if (possible[i] && i+coin <= V) {
                possible[i+coin] = true;
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (!possible[i]) return false;
    }
    return true;
}

template<typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const T& value : s) {
        if (first) {
            first = false;
        } else {
            os << ", ";
        }
        os << value;
    }
    return os << "}";
}

int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
        int C, D, V;
        cin >> C >> D >> V;

        set<int> starting_coins;
        for (int i = 0; i < D; i++) {
            int coin;
            cin >> coin;
            starting_coins.insert(coin);
        }

        set<set<int>> current = { starting_coins }, next;
        int iter = 0;
        while (true) {
            D(cerr << "iter=" << iter << endl);
            bool found = false;
            for (const set<int>& state : current) {
                D(cerr << "testing " << state << endl);
                if (is_valid(state, V)) {
                    D(cerr << " valid!" << endl);
                    found = true;
                    break;
                }

                for (int i = 1; i <= V; i++) {
                    if (state.count(i) == 0) {
                        set<int> new_state = state;
                        new_state.insert(i);
                        next.insert(new_state);
                    }
                }
            }
            if (found) break;

            swap(current, next);
            next.clear();
            iter++;
        }

        cout << "Case #" << testCase << ": " << iter << endl;
    }
}
