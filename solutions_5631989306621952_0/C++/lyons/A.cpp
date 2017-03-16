#include <iostream>
#include <string>
using namespace std;

int N;
string s;

string calc(string s) {
    if (s.size() <= 1) return s;
    string out = "";
    int imax = 0;
    for (int i = 0; i < s.size(); ++ i)
        if (s[i] >= s[imax]) imax = i;
    out = s[imax] + calc(s.substr(0, imax)) + s.substr(imax+1);
    return out;
}

int main() {
    cin >> N;
    for (int ncase = 1; ncase <= N; ++ ncase) {
        cin >> s;
        cout << "Case #" << ncase << ": " << calc(s) << endl;
    }
    return 0;
}
