#include <iostream>
#include <memory.h>
#include <sstream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;
std::mutex output_lock;

const int N = 2000111;
int f[N];

class TSolver {
private:
    int n;

private:
    void doInputData() {
        cin >> n;
    }

    void doSolve() {
    }

    void doOuptutData() {
        cout << f[n] << endl;
    }

public:
    void inputData() {
        doInputData();
        {
            std::lock_guard<std::mutex> lock(output_lock);
            cerr << "[#" << testNo << "]: input data finished\n";
        }
    }

    void solve() {
        doSolve();
        {
            std::lock_guard<std::mutex> lock(output_lock);
            cerr << "[#" << testNo << "]: solving finished\n";
        }
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

void doit() {
    memset(f, 63, sizeof(f));
    queue<int> q;
    f[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x + 1 < N && f[x + 1] > f[x] + 1) {
            f[x + 1] = f[x] + 1;
            q.push(x + 1);
        }

        vector<int> a;
        int y = x;
        while (y) {
            a.push_back(y % 10);
            y /= 10;
        }
        y = 0;
        for (int c : a) {
            y = y * 10 + c;
        }
        if (y < N && f[y] > f[x] + 1) {
            f[y] = f[x] + 1;
            q.push(y);
        }
    }
    //for (int i = 1; i < N; ++i) cout << f[i] << endl;
}

int main() {
    doit();
    int T;
    scanf("%d\n", &T);

    solvers.resize(T);
    for (int i = 0; i < T; ++i) {
        solvers[i].setTestNo(i + 1);
        solvers[i].inputData();
        unsolved.push(i);
    }

#ifdef DEBUG
    const size_t THREAD_COUNT = 1;
#else
    const size_t THREAD_COUNT = 4;
#endif
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

