#include <iostream>
#include <string>

using namespace std;

int main() {
        int T;
        cin >> T;
        for (int i = 1; i <= T; ++i) {
                string s;
                cin >> s;
                string res = "";
                for (int j = 0; s[j]; ++j) {
                        //cerr << j << ": " << s[j] << endl;
                        string r1 = res + s[j];
                        //cerr << r1 << endl;
                        string r2 = "";
                        r2 = r2 + s[j] + res;
                        //cerr << r2 << endl;
                        res = (r1 > r2 ? r1 : r2);
                }
                cout << "Case #" << i << ": " << res <<'\n';
        }
        return 0;
}