#include <fstream>
#include <algorithm>

using namespace std;

int main() {
        ifstream fin("C-small-1-attempt0.in");
        ofstream fout("C-small-1-attempt0.out");
        int T;
        fin >> T;
        for (int casenum = 1; casenum <= T; ++casenum) {
                fout << "Case #" << casenum << ":\n";
                int r, n, m, k;
                fin >> r >> n >> m >> k;
                while (r--) {
                        int a[10];
                        for (int i = 0; i < k; ++i)
                                fin >> a[i];
                        sort(a, a + k);
                        bool flag = true;
                        for (int i = 2; i <= m && flag; ++i)
                                for (int j = 2; j <= m && flag; ++j)
                                        for (int k = 2; k <= m && flag; ++k) {
                                                int t;
                                                for (t = 0; t < k; ++t) {
                                                        int tmp = a[t];
                                                        while (a[t] % i == 0) a[t] /= i;
                                                        while (a[t] % j == 0) a[t] /= j;
                                                        while (a[t] % k == 0) a[t] /= k;
                                                        if (a[t] == 1) {
                                                                a[t] = tmp;
                                                                continue;
                                                        }
                                                        else {
                                                                a[t] = tmp;
                                                                break;
                                                        }
                                                }
                                                if (t==k)
                                                {
                                                        flag = false;
                                                        fout<<i<<j<<k<<'\n';
                                                }
                                        }
                }
        }
        fin.close();
        fout.close();
        return 0;
}