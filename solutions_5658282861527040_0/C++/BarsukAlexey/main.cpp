#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

string stringGenome(string s) {
    string ideal_str = "";
    for (int i = 0; i < s.size(); i++) {
        if (ideal_str.size() == 0) {
            ideal_str += s[i];
        }
        else {
            int sz = ideal_str.size();
            if (s[i] == ideal_str[sz - 1]) ;
            else ideal_str += s[i];
        }
    }
    return ideal_str;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tests;
    cin >> tests;
    for (int i = 1; i <= tests; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        int answer = 0;
        for (int j = 0; j < a; j++) {
            for (int t = 0; t < b; t++) {
                int res = j & t;
                if (res < k) answer++;
            }
        }
        cout << "Case #" << i << ": " << answer << endl;
        cout.flush();
    }

    return 0;
}
