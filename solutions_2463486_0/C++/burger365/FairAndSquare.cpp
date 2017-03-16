#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
namespace mp = boost::multiprecision;

mp::int512_t A, B, res;

bool isPalindrome(string &str) {
    const int N = str.size();
    for (int i = 0, j = N - 1; i <= j; ++i, --j)
        if (str[i] != str[j]) return false;
    return true;
}

bool calc(string &str) {
    const int N = str.size();
    mp::int512_t num = 0;
    for (int i = 0; i < N; ++i)
        num = num * 10 + str[i] - '0';

    mp::int512_t square = num * num;
    string s = square.str();
    if (isPalindrome(s)) {
        //cout << num << " -> " << square << endl;
        if (square > B)
            return false;
        if (square >= A && square <= B)
            ++res;
        return true;
    } else {
        return false;
    }
}

void dfs(string str, int n) {
    if (!calc(str)) 
        return;

    if (n % 2 == 0) {
        for (char c = '0'; c <= '2'; ++c) {
            string next = str;
            next.insert(next.begin() + n / 2, c);
            //cout << str << " -> " << next << endl;
            dfs(next, n + 1);
        }
    } else {
        string next = str;
        next.insert(next.begin() + n / 2, next[n / 2]);
        //cout << str << " -> " << next << endl;
        dfs(next, n + 1);
    }
}

int main() {
    int T;
    assert(scanf("%d\n", &T) != EOF);

    for (int t = 1; t <= T; ++t) {
        A = 0;
        while (1) {
            char c;
            assert(scanf("%c", &c) != EOF);
            if (c == ' ')
                break;
            A = A * 10 + c - '0';
        }
        B = 0;
        while (1) {
            char c;
            assert(scanf("%c", &c) != EOF);
            if (c == '\n')
                break;
            B = B * 10 + c - '0';
        }

        res = 0;
        dfs("1", 1);
        dfs("2", 1);
        dfs("3", 1);
        cout << "Case #" << t << ": " << res << endl;
    }

    return 0;
}
