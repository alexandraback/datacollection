#include <bits/stdc++.h>

using namespace std;

const string S[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<pair<int, char>> q;
set<char> Q[10];
bool used[10];
vector<string> ss(10);

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
        cin >> s;
        result.resize(10);
    }

    void Solve() {
        vector<int> counts(333);
        for (char c : s) {
            counts[int(c)]++;
        }

        
        for (auto x : q) {
            int ans = counts[int(x.second)];
            int times = 0;
            for (int c : ss[x.first])
                if (c == x.second) ++times;
            ans /= times;

            result[x.first] = ans;
            for (char c : ss[x.first]) {
                counts[c] -= ans;
            }
        }
    }

    void Output() {
        for (int i = 0; i < 10; ++i) {
            while (result[i]--) putchar('0' + i);
        }
        puts("");
    }

private:
    string s;
    vector<int> result;
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
    for (int i = 0; i < 10; ++i) {
        ss[i] = S[i];
        Q[i] = set<char>(ss[i].begin(), ss[i].end());
        used[i] = false;
    }
    for (int iter = 0; iter < 10; ++iter) {
        bool done = false;
        for (int i = 0; i < 10; ++i) {
            if (used[i]) continue;

            for (char c : Q[i]) {
                bool cool = true;
                for (int j = 0; j < 10; ++j) if (!used[j] && i != j) {
                    if (Q[j].find(c) != Q[j].end()) {
                        cool = false;
                        break;
                    }
                }

                if (cool) {
                    done = true;
                    q.emplace_back(i, c);
                    cerr << i << " " << c << endl;
                    used[i] = true;
                    break;
                }
            }

            if (done) break;
        }
    }

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
