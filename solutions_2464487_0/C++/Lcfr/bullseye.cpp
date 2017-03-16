#include <fstream>

bool check(int r, int t, int n) {
        while (n > 0) {
                int req = 2 * r + 1;
                t -= req;
                if (t < 0)
                        return false;
                r += 2;
                n -= 1;
        }
        return true;
}

int main() {
        std::ifstream fin("A-small-attempt0.in");
        std::ofstream fout("A-small-attempt0.out");
        int T;
        fin >> T;
        for (int casenum = 1; casenum <= T; ++casenum) {
                int r, t;
                fin >> r >> t;
                int low = 0, high = t, mid;
                while (low < high) {
                        mid = (low + high + 1) / 2;
                        if (check(r, t, mid))
                                low = mid;
                        else
                                high = mid - 1;
                }
                fout << "Case #" << casenum << ": " << low << '\n';
        }
        fin.close();
        return 0;
}