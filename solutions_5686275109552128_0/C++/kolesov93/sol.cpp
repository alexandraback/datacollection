#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;

class TSolver {
private:
    int n;
    vector<int> a;
    size_t ans = 0;

private:
    void doInputData() {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
    }

    void doSolve() {
        sort(begin(a), end(a), greater<int>());

        ans = a[0];
        for (int limit = 1; limit <= a[0]; ++limit) {
            size_t cand = limit;
            for (int x : a) {
                cand += (x - 1) / limit;
            }
            ans = min(ans, cand);
        }
    }

    void doOuptutData() {
        cout << ans << endl;
    }

public:
    void inputData() {
        doInputData();
        cerr << "[#" << testNo << "]: input data finished\n";
    }

    void solve() {
        doSolve();
        cerr << "[#" << testNo << "]: solving finished\n";
    }

    void outputData() {
        printf("Case #%d: ", testNo);
        doOuptutData();
    }

    void setTestNo(int number) {
        testNo = number;
    }
private:
    int testNo;
};

vector<TSolver> solvers;
queue<int> unsolved;
std::mutex queue_lock;
std::mutex output_lock;

void worker() {
    while (true) {
        int testNo = -1;
        {
            std::lock_guard<std::mutex> lock(queue_lock);
            if (unsolved.empty()) {
                return;
            }
            testNo = unsolved.front();
            unsolved.pop();
        }
        solvers[testNo].solve();

    }
}

int main() {
    int T;
    scanf("%d\n", &T);

    solvers.resize(T);
    for (int i = 0; i < T; ++i) {
        solvers[i].setTestNo(i + 1);
        solvers[i].inputData();
        unsolved.push(i);
    }

    const size_t THREAD_COUNT = 4;
    std::vector<std::thread> workers;
    for (size_t i = 0; i < THREAD_COUNT; ++i) {
        workers.emplace_back(worker);
    }
    for (auto& worker : workers) {
        worker.join();
    }

    for (auto& solver : solvers) {
        solver.outputData();
    }

    return 0;
}

