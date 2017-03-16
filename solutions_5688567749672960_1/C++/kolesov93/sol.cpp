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
typedef long long ll;

const int N = 20;
int f[N];

int how(ll x) {
    int cnt = 0;
    while (x) {
        ++cnt;
        x /= 10;
    }
    return cnt;
}

ll howmuch(ll from, ll middle, ll to) {
    if (middle < from) return to - from;
    ll ans = middle - from;

    vector<int> a;
    while (middle) {
        a.push_back(middle % 10);
        middle /= 10;
    }
    middle = 0;
    for (int x : a) {
        middle = middle * 10 + x;
    }
    if (middle > to) return to - from;

    return ans + to - middle + 1;
}

ll reverse(ll x) {
    vector<int> a;
    while (x) {
        a.push_back(x % 10);
        x /= 10;
    }
    for (int c : a) {
        x = x * 10 + c;
    }
    return x;
}

ll doit(ll to) {
    vector<int> a;
    ll m = to;
    ll from = 1;
    while (m) {
        a.push_back(m % 10);
        m /= 10;
        from *= 10;
    }
    from /= 10;
    reverse(begin(a), end(a));

    ll ans = to - from;
    ll prefix = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        prefix = prefix * 10 + a[i];

        ll revprefix = reverse(prefix);
        ll cand2 = reverse(prefix - 1);
        ans = min(ans, howmuch(from, from + revprefix, to));
        ans = min(ans, howmuch(from, from + revprefix - 1, to));
        ans = min(ans, howmuch(from, from + cand2 - 1, to));
        ans = min(ans, howmuch(from, from + cand2, to));
    }

    return ans;
}

class TSolver {
private:
    ll n;
    ll ans;

private:
    void doInputData() {
        cin >> n;
        ans = ll(1e18);
    }

    void doSolve() {
        int len = how(n);
        if (n < 10) {
            ans = n;
            return;
        }

        ll m = 1;
        ll border = 10;
        ans = 1;
        while (len != how(m)) {
            ans += doit(border - 1) + 1;
            border *= 10;
            m *= 10;
        }
        ans += doit(n);
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
//    for (int i = 1; i < N; ++i) cout << f[i] << endl;
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

