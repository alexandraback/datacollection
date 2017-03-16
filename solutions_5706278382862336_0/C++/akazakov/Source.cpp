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

#define PROBLEM "A"

class TestCaseSolver {
    std::stringstream sout;
    // own vars
    uLL a, b;
public:
    void read();
    void solve();
    void print() {
        std::cout << sout.str() << std::flush;
    }
};

void TestCaseSolver::read() {
    scanf("%I64u/%I64u", &a, &b);
}

uLL gcd(uLL a, uLL b) {
    return (a && b) ? gcd(b % a, a) : (a | b);
}

void TestCaseSolver::solve() {
    uLL g = gcd(a, b);
    a /= g;
    b /= g;
    uLL x = 1;
    uLL s = 0;
    while (x < b) {
        x *= 2;
        ++s;
    }
    if (x > b) {
        sout << "impossible" << endl;
        return;
    }
    while (a > 1) {
        a /= 2;
        b /= 2;
        --s;
    }
    sout << s << endl;
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