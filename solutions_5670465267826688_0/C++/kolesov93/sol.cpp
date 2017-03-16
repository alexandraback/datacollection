#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;
std::mutex output_lock;
typedef long long ll;

int table1[4][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int table2[4][4] = {{0,0,0,0},{0,1,0,1},{0,1,1,0},{0,0,1,1}};

struct cell {
    bool negative;
    int value; // 0 - 1; 1 - i; 2 - j; 3 -k

    cell() {
        negative = false;
        value = 0;
    }

    explicit cell(char c) {
        negative = false;
        if (c == '1') value = 0;
        else if (c == 'i') value = 1;
        else if (c == 'j') value = 2;
        else if (c == 'k') value = 3;
    }

    const cell operator*(const cell& A) const {
        cell result;
        result.negative = negative ^ A.negative;
        result.value = table1[value][A.value];
        result.negative ^= table2[value][A.value];
        return result;
    }
};

cell pow(cell x, ll y) {
    cell result;
    while (y) {
        if (y & 1) result = result * x;
        x = (x * x);
        y >>= 1;
    }
    return result;
}

class TSolver {
private:
    ll l, x;
    string s;
    bool ans = false;
private:
    void doInputData() {
        cin >> l >> x;
        cin >> s;
    }

    void doSolve() {
        ll len = l * x;
        if (len < 3) {
            ans = false;
            return;
        }

        cell sum;
        for (auto c : s) {
            sum = (sum * cell(c));
        }
        cell whole = pow(sum, x);
        if (!whole.negative || whole.value != 0) {
            ans = false;
            return;
        }

        const int LIMIT = 2000000;
        if (l * x <= LIMIT || x < 20) {
            string all;
            for (int i = 0; i < x; ++i) all += s;

            int best1 = -1, best2 = -1;
            cell sum1, sum2;
            for (size_t i = 0; i < all.size(); ++i) {
                sum1 = sum1 * cell(all[i]);
                if (sum1.negative == false && sum1.value == 1) {
                    best1 = i;
                    break;
                }
            }
            for (int i = int(all.size()) - 1; i >= 0; --i) {
                sum2 = cell(all[i]) * sum2;
                if (sum2.negative == false && sum2.value == 3) {
                    best2 = i;
                    break;
                }
            }
            ans = false;
            if (best1 != -1 && best2 != -1 && best1 < best2) {
                ans = true;
            }
            return;
        }

        ans = false;
        string all;
        for (int i = 0; i < 10; ++i) all += s;
        int best = -1; cell sum1;
        for (size_t i = 0; i < all.size(); ++i) {
            sum1 = sum1 * cell(all[i]);
            if (sum1.negative == false && sum1.value == 1) {
                best = i;
                break;
            }
        }
        if (best == -1) return;

        best = -1; sum1.negative = false; sum1.value = 0;
        for (int i = int(all.size()) - 1; i >= 0; --i) {
            sum1 = cell(all[i]) * sum1;
            if (sum1.negative == false && sum1.value == 3) {
                best = i;
                break;
            }
        }
        if (best == -1) return;
        ans = true;
    }

    void doOuptutData() {
        if (ans) puts("YES");
        else puts("NO");
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

