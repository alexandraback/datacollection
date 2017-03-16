#include <bits/stdc++.h>

using namespace std;

mutex cerr_lock;
class LOG {
public:
    template<class T>
    LOG& operator<<(const T& value) {
        ss_ << value;
        return *this;
    }

    ~LOG() {
        lock_guard<mutex> lock(cerr_lock);
        cerr << ss_.str() << '\n';
        cerr.flush();
    }
private:
    stringstream ss_;
};

class TestImpl {
public:
    void Input() {
        vector<pair<int,int>> edges;
        int p;
        scanf("%d", &p);
        was = p;
        while (p--) {
            string a, b;
            cin >> a >> b;

            if (first.find(a) == first.end()) {
                int id = first.size();
                first[a] = id;
            }
            if (second.find(b) == second.end()) {
                int id = second.size();
                second[b] = id;
            }
            edges.emplace_back(first[a], second[b]);
        }

        n = first.size();
        k = second.size();
        g.resize(n);
        for (auto edge : edges) {
            g[edge.first].push_back(edge.second);
        }
    }

    bool kuhn(int v) {
        if (used[v]) return false;
        used[v] = true;
        for (int y : g[v]) {
            if (mt[y] == -1 || kuhn(mt[y])) {
                mt[y] = v;
                return true;
            }
        }
        return false;
    }

    void Solve() {
        vector<bool> used1(n);
        mt.resize(k);
        mt.assign(k, -1);

        for (int i = 0; i < n; ++i) {
            for (auto y : g[i]) {
                if (mt[y] == -1) {
                    mt[y] = i;
                    used1[i] = true;
                    break;
                }
            }
        }

        used.resize(n);
        for (int i = 0; i < n; ++i) 
            if (!used1[i]) {
                used.assign(n, 0);
                kuhn(i);
            }

        int got = 0;
        for (auto res : mt) 
            if (res != -1) ++got;

        got += (n + k) - (got + got);
        ans = was - got;
    }

    void Output() {
        cout << ans << endl;
    }

private:
    int was;
    int n, k;
    vector<vector<int>> g;
    vector<bool> used;
    vector<int> mt;

    map<string, int> first, second;

    int ans = 0;
};

class Test {
public:
    void Input(int testNo) {
        testNo_ = testNo;
        impl_.reset(new TestImpl);
        impl_->Input();
        
        LOG() << "Test #" << testNo_ << " is inputted";
    }

    void Solve() {
        impl_->Solve(); 
        LOG() << "Test #" << testNo_ << " is solved";
    }

    void Output() {
        printf("Case #%d: ", testNo_);
        impl_->Output();
        LOG() << "Test #" << testNo_ << " is outputted";
    }

private:
    int testNo_;
    unique_ptr<TestImpl> impl_;
};

int main() {
    constexpr int N_THREADS = 4;
    vector<Test> tests;
    queue<int> not_solved;

    int T;
    scanf("%d\n", &T);
    tests.resize(T);
    for (int i = 0; i < T; ++i) {
        tests[i].Input(i + 1);
        not_solved.push(i);
    }
    
    mutex test_mutex;
    vector<thread> threads;
    for (int i = 0; i < N_THREADS; ++i) {
        threads.emplace_back(
                [&](){
                    bool done = false;
                    do {
                        int next_test = -1;
                        test_mutex.lock();
                        if (not_solved.empty()) {
                            done = true;
                        } else {
                            next_test = not_solved.front();
                            not_solved.pop();
                        }
                        test_mutex.unlock();
                        if (!done) {
                            tests[next_test].Solve();
                        }
                    } while (!done);
                });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    for (auto& test : tests) {
        test.Output();
    }

    return 0;
}
