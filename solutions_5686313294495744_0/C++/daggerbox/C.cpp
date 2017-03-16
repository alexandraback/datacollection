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
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>
#include <future>
#include <thread>
#include <chrono>
#include <iomanip>
#include <numeric>
#include <thread>
#include <atomic>

using namespace std;
typedef int64_t int64;

// functional form of next value in a stream
template<typename T>
T nextValue(std::istream &in) {
    T i;
    in >> i;
    return i;
}

// reads a vector (of integral values) from an input stream
template<typename T>
std::vector<T> readVector(std::istream &in, int n) {
    std::vector<T> c;
    std::generate_n(std::back_inserter(c), n, [&in]() { return nextValue<T>(in); });
    return c;
}

template<typename T, typename U>
bool contains(T &&c, U &&x) {
    return find(std::begin(c), std::end(c), x) != std::end(c);
}

std::chrono::time_point<std::chrono::system_clock> now() { return std::chrono::system_clock::now(); }

double since(const std::chrono::time_point<std::chrono::system_clock> &t0) {
    return std::chrono::duration<double>(std::chrono::system_clock::now() - t0).count();
}

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

// base class: override with a specific problem
class SolverBase {
    std::ostringstream out_;
public:
    virtual void read(std::istream &in) = 0;    // read input for a single test case

    virtual void solve() { saw(out_); }     // solve a single test case

    virtual void write(std::ostream &out) { out << out_.str(); }    // write output (after "Case: #N: ")

    string str() { return out_.str(); }

    operator string() { return out_.str(); }

protected:
    virtual void saw(std::ostream &out) = 0;    // solve and write
};

class Solver : public SolverBase {
    int n_;
    vector<string> a_;
    vector<string> b_;
public:
    virtual void read(std::istream &in);

protected:
    virtual void saw(std::ostream &out);

    int go(vector<int> & perm) const;
};


void Solver::read(std::istream &in) {
    in >> n_;
    a_.resize(n_);
    b_.resize(n_);
    for (int i = 0; i < n_; ++i) {
        in >> a_[i] >> b_[i];
    }
}


void Solver::saw(std::ostream &out) {

    vector<int> perm(n_);
    iota(begin(perm), end(perm), 0);
    int best = 0;
    for (int j = 0; j < (1 << min(n_, 16)); ++j) {
        int c = go(perm);
        if (c > best)
            best = c;
        std::next_permutation(perm.begin(), perm.end());
    }

    out << best;

}

int Solver::go(vector<int> & perm) const {
    map<string, int> ac, bc;
    for (int i = 0; i < n_; ++i) {
        ac[a_[i]]++;
        bc[b_[i]]++;
    }
    vector<bool> used(n_);
    int uc = 0;
    map<string, bool> as, bs;

    int nOriginal = 0;
    for (int i = 0; i < n_; ++i) {
        if (ac[a_[i]] == 1 || bc[b_[i]] == 1) {
            nOriginal++;
            used[i] = true;
            uc++;
            as[a_[i]] = true;
            bs[b_[i]]= true;
        }
    }

    while (uc < n_) {
        for (int i = 0; i < n_; ++i) {
            int k = perm[i];
            if (!used[k]) {
                if (as[a_[k]] && bs[b_[k]]) {
                    used[k] = true;
                    uc++;
                }
            }
        }
        int delta = 0;
        for (int i = 0; i < n_; ++i) {
            int k = perm[i];
            if (!used[k]) {
                if (!as[a_[k]] && !bs[b_[k]]) {
                    as[a_[k]] = true;
                    bs[b_[k]]= true;
                    nOriginal++;
                    used[k] = true;
                    uc++;
                    delta++;
                    break;
                }
            }
        }
        if (delta == 0) {
            for (int i = 0; i < n_; ++i) {
                int k = perm[i];
                if (!used[k]) {
                    if (!as[a_[k]] || !bs[b_[k]]) {
                        as[a_[k]] = true;
                        bs[b_[k]]= true;
                        nOriginal++;
                        used[k] = true;
                        uc++;
                        break;
                    }
                }
            }
        }
    }
    return n_ - nOriginal;
}


int main() {
    freopen("C.in.txt", "r", stdin);
    freopen("C.out.txt", "w", stdout);

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
            s.solve();
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