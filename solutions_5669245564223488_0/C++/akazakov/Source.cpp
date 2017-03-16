#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

#include <algorithm>
#include <cmath>
#include <ctime>

#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <future>

#define uLL unsigned long long
#define BIG 1000000000

using namespace std;

#define PROBLEM "B"

class TestCaseSolver {
    std::stringstream sout;
    // own vars
    vector<pair<int, string>> v;
    vector<int> p;
public:
    void read();
    void solve();
    void print() {
        std::cout << sout.str() << std::flush;
    }
};

void TestCaseSolver::read() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i].first = i;
        cin >> v[i].second;
    }
}

bool is_valid_str(const vector<pair<int, string>> &v) {
    bool x[256] = { 0 };
    x[v[0].second[0]] = 1;
    char prev = v[0].second[0];
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].second.length(); ++j) {
            if (!i && !j) {
                continue;
            }
            char cur = v[i].second[j];
            if (x[cur] && cur != prev) {
                return false;
            }
            x[cur] = true;
            prev = cur;
        }
    }
    return true;
}

void TestCaseSolver::solve() {
    sort(v.begin(), v.end());
    uLL res = 0;
    do {
        if (is_valid_str(v)) {
            ++res;
            res %= 1000000007;
        }
    } while (next_permutation(v.begin(), v.end()));
    sout << res << endl;
}

int main() {
    srand(unsigned(time(0)));
    if (
        !freopen("input_" PROBLEM ".txt", "rt", stdin) ||
        !freopen("output.txt", "wt", stdout)
    ) {
        std::cerr << "Couldn't open files." << std::endl;
    }
    int num_tests;
    cin >> num_tests;
    std::vector<std::future<TestCaseSolver *>> solver_futures;
#ifdef _DEBUG
    auto launch_type = std::launch::deferred;
#else
    auto launch_type = std::launch::async;
#endif
    for (int i = 0; i < num_tests; ++i) {
        auto *solver = new TestCaseSolver();
        solver->read();
        solver_futures.push_back(std::async(launch_type, 
            [solver, i]() -> TestCaseSolver * {
                solver->solve();
                return solver;
            }
        ));
    }
    for (uLL i = 0; i < num_tests; ++i) {
        cerr << "Now solving: " << (i + 1) << "\r" << flush;
        cout << "Case #" << (i + 1) << ": ";
        auto *solver = solver_futures[i].get();
        solver->print();
        delete solver;
    }
    return 0;
}