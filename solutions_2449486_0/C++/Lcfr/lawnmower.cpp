#include <cstdio>
#include <algorithm>

int main() {
        FILE *fin, *fout;
        fopen_s(&fin, "B-small-attempt0.in", "r");
        fopen_s(&fout, "B-small-attempt0.out", "w");
        int T;
        fscanf_s(fin, "%d", &T);
        for (int casenum = 1; casenum <= T; ++casenum) {
                fprintf(fout, "Case #%d: ", casenum);
                int a[100][100];
                int n, m;
                fscanf_s(fin, "%d%d", &n, &m);
                int rowmax[100] = {0}, colmax[100] = {0};
                for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                                fscanf_s(fin, "%d", &a[i][j]);
                                rowmax[i] = std::max(rowmax[i], a[i][j]);
                                colmax[j] = std::max(colmax[j], a[i][j]);
                        }
                }
                bool ans = true;
                for (int i = 0; i < n && ans; ++i)
                        for (int j = 0; j < m && ans; ++j)
                                if (a[i][j] < rowmax[i] && a[i][j] < colmax[j])
                                        ans = false;
                if (ans)
                        fputs("YES\n", fout);
                else
                        fputs("NO\n", fout);
        }
        return 0;
}