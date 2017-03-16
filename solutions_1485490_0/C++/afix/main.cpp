#include <fstream>
#include <vector>

using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");

vector<unsigned long long> suff(vector<unsigned long long> v, int i) {
    vector<unsigned long long> res;
    for (; i < (int)v.size(); ++i) res.push_back(v[i]);
    return res;
}

unsigned long long solve1(vector<unsigned long long> a, vector<unsigned long long> A, vector<unsigned long long> b, vector<unsigned long long> B) {
    if (a.empty() || b.empty()) return 0;
    unsigned long long best = 0;
    if (A[0] != B[0]) {
        best = solve1(suff(a, 1), suff(A, 1), b, B);
        best = max(best, solve1(a, A, suff(b, 1), suff(B, 1)));
    } else {
        if (a[0] < b[0]) {
            b[0] -= a[0];
            best = a[0] + solve1(suff(a, 1), suff(A, 1), b, B);
        } else if (a[0] == b[0]) {
            best = a[0] + solve1(suff(a, 1), suff(A, 1), suff(b, 1), suff(B, 1));
        } else {
            a[0] -= b[0];
            best = b[0] + solve1(a, A, suff(b, 1), suff(B, 1));
        }
    }
    return best;
}

int n, m;
unsigned long long x, y;
vector<unsigned long long> a, A, b, B;

void solve(int t) {
    cin >> n >> m;
    a.resize(n);
    A.resize(n);
    b.resize(m);
    B.resize(m);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a[i] = x;
        A[i] = y;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        b[i] = x;
        B[i] = y;
    }
    unsigned long long best = solve1(a, A, b, B);
    cout << "Case #" << t << ": " << best << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) solve(i);

    return 0;
}
