#include <fstream>

using namespace std;

void dfs(const int d, const int e, const int r, const int n, const int v[],
         int ce, int val, int &ans) {
        if (d == n) {
                ans = ans > val ? ans : val;
                return;
        }
        for (int i = 0; i <= ce; ++i) {
                val += i * v[d];
                int oce = ce;
                ce = ce - i + r;
                ce = ce > e ? e : ce;
                dfs(d + 1, e, r, n, v, ce, val, ans);
                ce = oce;
                val -= i * v[d];
        }
}

int main() {
        ifstream fin("B-small-attempt1.in");
        ofstream fout("B-small-attempt1.out");
        int T;
        fin >> T;
        for (int casenum = 1; casenum <= T; ++casenum) {
                int e, r, n, v[10];
                fin >> e >> r >> n;
                for (int i = 0; i < n; ++i)
                        fin >> v[i];
                int ans = 0;
                dfs(0, e, r, n, v, e, 0, ans);
                fout << "Case #" << casenum << ": " << ans << '\n';
        }
        fin.close();
        return 0;
}