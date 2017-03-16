

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
double since(const std::chrono::time_point<std::chrono::system_clock> &t0)
    { return std::chrono::duration<double>(std::chrono::system_clock::now() - t0).count(); }

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
    string s_[2];
public:
    virtual void read(std::istream &in);

protected:
    virtual void saw(std::ostream &out);

    bool place(vector<vector<int>> rc[2], int next);

    bool matches(int a, int b);
    bool follows(int a, int b);

    pair<int64, int64> findBest(string const & sa, string const & sb, int iNext, int64 a, int64 b);
};


void Solver::read(std::istream &in) {
    in >> s_[0] >> s_[1];

    /*
    string s;
    getline(in >> std::ws, s);
    for (auto c : s) {
        a_.push_back(c);
    }
     */
}

void Solver::saw(std::ostream &out) {
    int n = int(s_[0].length());
    int m = int(s_[1].length());
    if (m != n)
        throw 1;
    pair<int64, int64> result = findBest(s_[0], s_[1], 0, 0, 0);//, std::numeric_limits<int64>::max());
    out << setfill('0') << setw(n) << result.first << " " << setfill('0') << setw(n) << result.second;
}


pair<int64, int64> Solver::findBest(string const & sa, string const & sb, int iNext, int64 a, int64 b) {
    if (iNext == sa.length()) {
        return make_pair(a, b);
    }
    vector<pair<int, int>> p;
    int aa = sa[iNext] - '0';
    int bb = sb[iNext] - '0';
    if (sa[iNext] == '?' && sb[iNext] == '?') {
        if (a == b) {
            p.push_back(make_pair<int, int>(0, 0));
            p.push_back(make_pair<int, int>(0, 1));
            p.push_back(make_pair<int, int>(1, 0));
        }
        else if (a < b) {
            p.push_back(make_pair<int, int>(9, 0));
        }
        else {
            p.push_back(make_pair<int, int>(0, 9));
        }
    }
    else if (sa[iNext] == '?') {
        if (a == b) {
            p.push_back(make_pair(bb, bb));
            if (bb > 0)
                p.push_back(make_pair(bb - 1, bb));
            if (bb < 9)
                p.push_back(make_pair(bb + 1, bb));
        }
        else if (a < b) {
            p.push_back(make_pair(9, bb));
        }
        else {
            p.push_back(make_pair(0, bb));
        }
    }
    else if (sb[iNext] == '?') {
        if (a == b) {
            p.push_back(make_pair(aa, aa));
            if (aa > 0)
                p.push_back(make_pair(aa, aa - 1));
            if (aa < 9)
                p.push_back(make_pair(aa, aa + 1));
        }
        else if (a < b) {
            p.push_back(make_pair(aa, 0));
        }
        else {
            p.push_back(make_pair(aa, 9));
        }
    }
    if (p.size() == 0) {
        a = a * 10 + aa;
        b = b * 10 + bb;
        return findBest(sa, sb, iNext + 1, a, b);
    }
    else if (p.size() == 1) {
        a = a * 10 + p[0].first;
        b = b * 10 + p[0].second;
        return findBest(sa, sb, iNext + 1, a, b);
    }
    else {
        pair<int64, int64> bestPair(-1, -1);
        int64 bestDiff = abs(bestPair.first - bestPair.second);
        for (int i = 0; i < p.size(); ++i) {
            pair<int64, int64> r = findBest(sa, sb, iNext + 1, a * 10 + p[i].first, b * 10 + p[i].second);
            int64 diff = abs(r.first - r.second);
            if (bestPair.first < 0 || diff < bestDiff || diff == bestDiff && r < bestPair) {
                bestPair = r;
                bestDiff = diff;
            }
        }
        return bestPair;
    }
}


int main() {
    freopen("B.in.txt","r",stdin);
    freopen("B.out.txt","w",stdout);
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

