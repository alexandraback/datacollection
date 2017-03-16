#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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
        cin >> a >> b;
        n = a.size();

        pows.resize(n);
        pows[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            pows[i] = pows[i + 1] * ll(10);
        }
    }

    void fin(string a, string b, int pos, bool swap) {
        for (int i = pos + 1; i < n; ++i) {
            if (a[i] == '?') a[i] = '9';
            if (b[i] == '?') b[i] = '0';
        }
        
        ll xx = 0, yy = 0;
        for (int i = 0; i < n; ++i) {
            xx += pows[i] * ll(a[i] - '0');
            yy += pows[i] * ll(b[i] - '0');
        }
        if (swap) check(xx, yy);
        else check(yy, xx);
    }

    void doit(string a, string b, int pos) {
        char wa = a[pos], wb = b[pos];
        for (char ca = '0'; ca <= '9'; ++ca) {
            if (wa != '?' && wa != ca) continue;

            for (char cb = '0'; cb <= '9'; ++cb) {
                if (wb != '?' && wb != cb) continue;

                a[pos] = ca;
                b[pos] = cb;
                fin(a, b, pos, true);
                fin(b, a, pos, false);
            }
        }
    }

    void Solve() {
        int index = -1;
        bool cool = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
                index = i;
                cool = false;
                break;
            }
        }

        if (cool) {
            ll ans = 0;
            for (int i = 0; i < n; ++i) {
                char c;
                if (a[i] == '?') c = b[i];
                else c = a[i];
                if (c == '?') c = '0';
                
                ans += pows[i] * ll(c - '0'); 
            }
            A = B = ans;
            return;
        }

        for (int first = 0; first <= index; ++first) {
            doit(a, b, first);
            char c = a[first];
            if (c == '?') c = b[first];
            if (c == '?') c = '0';
            a[first] = b[first] = c;
        }
    }

    void Output() {
        for (int i = 0; i < n; ++i) {
            a[i] = A % 10;
            A /= 10;
            b[i] = B % 10;
            B /= 10;
            a[i] += '0'; b[i] += '0';
        }
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        cout << a << " " << b << endl;
    }

    ll myabs(ll x) {
        if (x < 0) return -x;
        return x;
    }

    void check(ll x, ll y) {
        if (A == -1) {
            A = x;
            B = y;
            return;
        }

        ll diff = myabs(x - y), bdiff = myabs(A - B);
        if (diff != bdiff) {
            if (diff < bdiff) {
                A = x;
                B = y;
            }
            return;
        }

        if (A != x) {
            if (x < A) {
                A = x;
                B = y;
            }
            return;
        }

        if (y < B) {
            A = x;
            B = y;
        }
    }
private:
    string a, b;
    int n;
    vector<ll> pows;

    ll A = -1, B = -1;
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
