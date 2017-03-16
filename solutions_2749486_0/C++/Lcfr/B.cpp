#include <fstream>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
        ifstream fin("B-small-attempt1.in");
        ofstream fout("B-small-attempt1.out");
        int T;
        fin >> T;
        for (int casenum = 1; casenum <= T; ++casenum) {
                int X, Y;
                fin >> X >> Y;
                string ans = "";
                string tmp;
                if (X < 0) tmp = "EW";
                else tmp = "WE";
                for (int i = 0; i < abs(X); ++i)
                        ans += tmp;
                if (Y < 0) tmp = "NS";
                else tmp = "SN";
                for (int i = 0; i < abs(Y); ++i)
                        ans += tmp;
                fout << "Case #" << casenum << ": " << ans << '\n';
        }
        fin.close();
        fout.close();
        return 0;
}