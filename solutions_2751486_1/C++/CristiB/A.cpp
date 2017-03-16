#include <iostream>
#include <iomanip>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <boost/lexical_cast.hpp>

#define log false && cerr
//#define log cerr

using namespace std;

bool isCons(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

long solve(string s, int n) {
    int runSt = -1;
    int closest = -1;
    long result = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (isCons(s[i]) && runSt == -1)
            runSt = i;
        
        if (!isCons(s[i]))
            runSt = -1;
        
        if (runSt != -1 && i - runSt + 1 >= n)
            closest = i - n + 1;

        log << "i: " << i << " runSt: " << runSt << " closest: " << closest << endl;
        result += closest + 1;
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    string s;
    int n;

    for (int t = 1; t <= T; ++t) {
        cin >> s >> n;
        log << "Test: " << t << " " << s << " " << n << endl;
        long res = solve(s, n);
        cout << "Case #" << t << ": " << res  << endl;
    }

    return 0;
}

