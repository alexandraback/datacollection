#include <fstream>
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;

inline bool is_constant(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u')
                return false;
        return true;
}

int main() {
        ifstream fin("A-large.in");
        //ofstream fout("A-large.out");
        FILE *fout = fopen("A-large.out", "w");
        int T;
        fin >> T;
        for (int casenum = 1; casenum <= T; ++casenum) {
                double ans = 0;
                int n;
                string str;
                fin >> str >> n;
                int num = 0, cnt = 0;
                int len = str.length();
                bool consec = false;
                int start;
                for (int i = 0; i < len; ++i) {
                        if (is_constant(str[i])) {
                                ++cnt;
                                if (cnt >= n) {
                                        consec = true;
                                        start = i - n + 1;
                                }
                        } else {
                                cnt = 0;
                        }
                        if (consec)
                                ans += (start + 1);
                }
                //fout << "Case #" << casenum << ": " << ans <<'\n';
                fprintf(fout, "Case #%d: %.0lf\n", casenum, ans);
        }
        fin.close();
        //fout.close();
        //system("pause");
        return 0;
}