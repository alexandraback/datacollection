

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>
#include <future>
#include <thread>
#include <chrono>
#include <iomanip>
#include <thread>
#include <atomic>

using namespace std;
typedef int64_t int64;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define mp make_pair
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

template<typename T>
int nextValue(std::istream & in) {
    T i;
    in >> i;
    return i;
}

template<typename T>
std::vector<T> readVector(std::istream &in, int n) {
    std::vector<T> c;
    std::generate_n(std::back_inserter(c), n, [&in](){ return nextValue<T>(in); });
    return c;
}

std::chrono::time_point<std::chrono::system_clock> now() { return std::chrono::system_clock::now(); }
double since(const std::chrono::time_point<std::chrono::system_clock> &t0) {
    return std::chrono::duration<double>(std::chrono::system_clock::now() - t0).count(); }

static int64 gcd(int64 a, int64 b) {
    if (a < 0 || b < 0)
        return -1;
    while (b != 0) {
        int64 x = a % b;
        a = b;
        b = x;
    }
    return a;
}

class SolverBase {
    std::ostringstream out_;
public:
    virtual void read(std::istream & in) = 0;
    virtual void solve() { saw(out_); }
    virtual void write(std::ostream & out) { out << out_.str(); }
    string str() { return out_.str(); }
    operator string() { return out_.str(); }

protected:
    virtual void saw(std::ostream & out) = 0;	// solve and write
};

class Solver : public SolverBase {
    string s_;
public:
    virtual void read(std::istream &in);

protected:
    virtual void saw(std::ostream &out);

};

//static std::map<string, ve>;

void Solver::read(std::istream &in) {
    in >> s_;
}

static string text[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

static int removeDigit(vector<int> & cc, char c, int digit) {
    int dc = cc[c];
    for (int j = 0; j < text[digit].length(); ++j) {
        cc[text[digit][j]] -= dc;
    }

    return dc;
}
void Solver::saw(std::ostream &out) {
    vector<int> cc(128, 0);
    for (int i = 0; i < s_.length(); ++i) {
        cc[s_[i]] += 1;
    }

    vector<int> dc(10, 0);

    dc[0] = removeDigit(cc, 'Z', 0);
    dc[2] = removeDigit(cc, 'W', 2);
    dc[4] = removeDigit(cc, 'U', 4);
    dc[5] = removeDigit(cc, 'F', 5);
    dc[6] = removeDigit(cc, 'X', 6);
    dc[7] = removeDigit(cc, 'V', 7);
    dc[8] = removeDigit(cc, 'G', 8);
    // 1, 3, 9
    dc[9] = removeDigit(cc, 'I', 9);
    dc[3] = removeDigit(cc, 'H', 3);
    dc[1] = removeDigit(cc, 'O', 1);

    string result;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < dc[i]; ++j) {
            result.push_back(char('0' + i));
        }
    }
    out << result;
}



int main() {

    freopen("A.in.txt","r",stdin);
    freopen("A.out.txt","w",stdout);
    auto t00 = std::chrono::system_clock::now();

    int nTestCases ;
    cin >> nTestCases;

    // number of processors
    const int nThreads = min(max(int(thread::hardware_concurrency()), 1), nTestCases);

    if (nThreads <= 1) {
        // sequential processing: less memory and useful for debugging
        Solver s;
        for (int it = 0; it < nTestCases; ++it) {
            s.read(cin);
            cout << "Case #" << (it + 1) << ": " << s.str() << endl;
        }
    }
    else {
        // parallel processing with simple thread pool
        vector<Solver> s(nTestCases);
        // read all input sequentially
        for (int it = 0; it < nTestCases; ++it) {
            s[it].read(cin);
        }

        atomic<int> next(0);    // the next case that needs a worker thread
        atomic<int> done(0);    // only used for progress reporting

        auto work = [&next, &done, &s, &nTestCases, t00](void) {
            while (true) {
                int i = next++; // this atomic operation is how the threads synchronize with each other
                if (i >= nTestCases)
                    return;
                //fprintf(stderr, "start %3d\n", i + 1);
                auto t0 = now();
                s[i].solve();
                double t = since(t0);
                done++;
                if (t > 0.01)
                    fprintf(stderr, "%3d : %3d / %d = %.2f | %.2f\n", i + 1, int(done), nTestCases, t,
                            since(t00) / done * nTestCases);
            }
        };
        vector<thread> workers;
        // start worker threads
        for (int i = 0; i < nThreads; ++i) {
            workers.push_back(thread(work));
        }
        // wait for all workers to complete
        for (int i = 0; i < nThreads; ++i) {
            workers[i].join();
        }
        // report results
        for (int it = 0; it < nTestCases; ++it) {
            cout << "Case #" << (it + 1) << ": " << s[it].str() << endl;
        }
    }
    fprintf(stderr, "%.2f\n", since(t00));
    return 0;
}
