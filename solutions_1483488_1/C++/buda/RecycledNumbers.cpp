#include <cassert>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>

using namespace std;

string to_str(int x) {
    ostringstream os;
    os << x;
    return os.str();
}
int main() {
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int A, B;
        cin >> A >> B;
        string Astr = to_str(A);
        string Bstr = to_str(B);
        assert(Astr.size() == Bstr.size());

        int sol = 0;
        for (int m=A+1; m<=B; ++m) {
            string mstr = to_str(m);
            assert(mstr.size() == Astr.size());
            assert(Astr<mstr && mstr<=Bstr);
            vector<string> V;
            for (int i=1; i<(int)mstr.size(); ++i) {
                if (mstr[i] == '0') {
                    continue;
                }
                string cand = mstr.substr(i) + mstr.substr(0, i);
                assert(cand.size() == mstr.size());
                if (Astr<=cand && cand<mstr) {
                    V.push_back(cand);
                }
            }
            sort(V.begin(), V.end());
            sol += unique(V.begin(), V.end()) - V.begin();
        }
        
        cout << "Case #" << t << ": " << sol << '\n';
    }
	return 0;
}
