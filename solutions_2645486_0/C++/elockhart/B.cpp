#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <queue>

using namespace std;

// Typedefs to save typing
typedef long long ll;
typedef pair<int, int> pi;

// Loops
#define REP(k) for (int loop_counter = 0; loop_counter < (k); ++loop_counter)

// Container-level helper functions
template<typename C> const typename C::value_type cmin(const C& c) { return *min_element(c.begin(), c.end()); }
template<typename C> int minidx(const C& c) { return min_element(c.begin(), c.end()) - c.begin(); }
template<typename C> void csort(C& c) { sort(c.begin(), c.end()); }
template<typename C> void cuniq(C& c) { sort(c.begin(), c.end()); c.erase(unique(c.begin(), c.end()), c.end()); }

// Input helper functions
string readstr(istream& in) { string str; getline(in, str); return str; }
void chomp(istream& in) { readstr(in); }
template<typename T> void readN(istream& in, vector<T>& vec, int n) { vec.resize(n); for (int i = 0; i < n; ++i) in >> vec[i]; }

// Output helper
class output
{
public:
    bool tee;
    ostream& stream;
    output(ostream& stream, bool tee) : stream(stream), tee(tee) { }
    template <typename T> output& operator<<(T const& v)
    {
        if (tee) cout << v;
        stream << v;
        return *this;
    }
};

// Test case
struct Case
{
    int idx_;
    int E, R, N;
    vector<int> val;
    
    // Parse input
    Case (int idx, istream& in) : idx_(idx)
    {
        in >> E >> R >> N;
        readN(in, val, N);
    }
    
    // Calculation and output
    void solve(output& out)
    {
        vector<int> u(E+1), v(E+1);
        for (int i = N-1; i >= 0; --i) {
            for (int e = 0; e <= E; ++e) {
                u[e] = 0;
                for (int s = 0; s <= e; ++s) {
                    int ut = val[i] * s + v[min(E, R+e-s)];
                    if (ut > u[e]) u[e] = ut;
                }
            }
            v = u;
        }
        out << v[E] << "\n";
    }
};

// Boilerplate
int main(int argc, char** argv)
{
    if (argc == 2) {
        string prefix(argv[1]);
        ifstream infile((prefix + string(".in")).c_str());
        ofstream outfile((prefix + string(".out")).c_str());
        output out(outfile, true);
        out << setprecision(16);
        int ncase;
        infile >> ncase;
        for (int icase = 1; icase <= ncase; ++icase)
        {
            out << "Case #" << icase << ": ";
            Case(icase, infile).solve(out);
        }
    } else {
        cout << "Running from stdin / stdout\n";
        cout << setprecision(16);
        int ncase;
        cin >> ncase;
        output out(cout, false);
        for (int icase = 1; icase <= ncase; ++icase)
        {
            cout << "Case #" << icase << ": ";
            Case(icase, cin).solve(out);
        }
    }
    return 0;
}

