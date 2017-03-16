#include <fstream>
#include <string>
#include <cctype>

using namespace std;

inline bool is_constant(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u')
                return false;
        return true;
}

int main() {
        ifstream fin("A-small-attempt0.in");
        ofstream fout("A-small-attempt0.out");
        int T;
        fin >> T;
        for (int casenum = 1; casenum <= T; ++casenum) {
                int ans = 0, n;
                string str;
                fin >> str >> n;
                int len = str.length();
                for (int i = 0; i < len; ++i)
                        for (int j = i + n - 1; j < len; ++j) {
                                int cnt = 0;
                                for (int k = i; k <= j; ++k)
                                        if (is_constant(str[k])) {
                                                ++cnt;
                                                if (cnt >= n) {
                                                        ++ans;
                                                        break;
                                                }
                                        } else {
                                                cnt = 0;
                                        }
                        }
                fout << "Case #" << casenum << ": " << ans <<'\n';
        }
        fin.close();
        fout.close();
        //system("pause");
        return 0;
}