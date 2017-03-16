#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;
std::mutex output_lock;

class TSolver {
private:
    vector<pair<int, int>> a;
    int ans = 0;

private:
    void doInputData() {
        int n;
        scanf("%d", &n);
        while (n--) {
            int d, h, m;
            cin >> d >> h >> m;
            for (int i = 0; i < h; ++i) a.emplace_back(d, m + i);
        }
    }

    void doSolve() {
        if (a.size() <= 1 || a[0].second == a[1].second) {
            ans = 0;
            return;
        }

        sort(begin(a), end(a));
        if (a[0].first == a[1].first) {
            reverse(begin(a), end(a));
        }
        double v1 = 360. / a[0].second;
        double v2 = 360. / a[1].second;

        if (v1 > v2) {
            double t1 = double(a[1].first - a[0].first) / (v1 - v2) + a[0].second;
            if (double(a[1].first) + t1 * v2 > 360) {
                ans = 0;
                return;
            }
            ans = 1;
            return;
        }

        double t1 = double(360 + a[0].first - a[1].first) / fabs(v2 - v1);
        if (double(a[0].first) + t1 * v1 > 360) {
            ans = 0;
            return;
        }
        ans = 1;
    }

    void doOuptutData() {
        cout << ans << endl;
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

int main() {
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

