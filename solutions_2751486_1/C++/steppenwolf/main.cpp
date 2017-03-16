#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;


bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o'
           || c == 'u';
}

int main(int argc, char *argv[]) {
    int ntest;
    cin >> ntest;

    for (int test = 1; test <= ntest; test++) {
        string s;
        int n;
        cin >> s >> n;

        int cons = 0, pos = -1;
        long long res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!isVowel(s[i])) {
                cons++;
                if (cons >= n) pos = i - n + 1;
            }
            else cons = 0;

            res += pos + 1;
        }

        cout << "Case #" << test << ": " << res << endl;
    }

}
