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

#define PROBLEM "C"

class TestCaseSolver {
    std::stringstream sout;
    // own vars
    int n, m, k;
public:
    void read();
    void solve();
    void print() {
        std::cout << sout.str() << std::flush;
    }
};

void TestCaseSolver::read() {
    cin >> n >> m >> k;
}

struct Field {
    bool *f;
    int n, m;
    Field(int n, int m) {
        this->n = n;
        this->m = m;
        f = new bool[n * m];
    }
    ~Field() {
        delete [] f;
    }
    bool *operator[] (int k) {
        return f + (k * m);
    }
    void load(uLL x) {
        for (int i = 0; i < n * m; ++i) {
            f[i] = (x & 1);
            x >>= 1;
        }
    }
};

int bitCnt(uLL x) {
    int res = 0;
    while (x > 0) {
        res += (x & 1);
        x >>= 1;
    }
    return res;
}

inline bool dfs_can_go(Field &f, Field &mark, int y, int x) {
    if (y < 0 || x < 0 || y >= f.n || x >= f.m) {
        return false;
    }
    return !mark[y][x] && !f[y][x];
}

void dfs(Field &f, Field &mark, int y, int x) {
    if (!dfs_can_go(f, mark, y, x)) {
        return;
    }
    mark[y][x] = true;
    dfs(f, mark, y + 1, x);
    dfs(f, mark, y - 1, x);
    dfs(f, mark, y, x + 1);
    dfs(f, mark, y, x - 1);
}

int num_closed(Field &f) {
    Field mark(f.n, f.m);
    mark.load(0);
    for (int i = 0; i < f.n; ++i) {
        dfs(f, mark, i, 0);
        dfs(f, mark, i, f.m - 1);
    }
    for (int i = 0; i < f.m; ++i) {
        dfs(f, mark, 0, i);
        dfs(f, mark, f.n - 1, i);
    }
    int res = 0;
    for (int i = 0; i < f.n * f.m; ++i) {
        if (mark.f[i] == false) {
            ++res;
        }
    }
    return res;
}

void TestCaseSolver::solve() {
    uLL bm_max = (1ULL << (n * m));
    Field f(n, m);
    int res = n * m + 1;
    for (uLL bm = 0; bm < bm_max; ++bm) {
        f.load(bm);
        if (num_closed(f) >= k) {
            res = min(res, bitCnt(bm));
        }
    }
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