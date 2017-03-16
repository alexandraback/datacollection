#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string ss, s, start, end;
        cin >> s;
        cout << "Case #" << t << ": ";
        char lastC = s[0];
        for (char c : s) {
            if (c >= lastC) {
                start += c;
                lastC = c;
            }
            else end += c;
        }
        for (auto c = start.rbegin(); c < start.rend(); ++c) ss += *c;
        cout << ss << end << endl;
//        int I = 0;
//        while (I < s.length()) {
//            int lastI = I;
//            for (int i = lastI; i < s.length(); ++i) {
//                if (s[i] > s[lastI]) lastI = i;
//            }
//            cout << "{Found " << s[lastI] << '}';
//            for (int i = I; i < lastI; i++) {
//                end += s[i];
//            }
//            start += s[lastI];
//            I = lastI + 1;
//        }
//        cout << start << '|' << end << endl;
    }
}

