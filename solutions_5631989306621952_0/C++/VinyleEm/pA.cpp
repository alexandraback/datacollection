#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <utility>

#include "common.h"

using namespace std;

string best(string s)
{
    if (s.empty())
        return s;
    const size_t n = s.size();
    char mx = *max_element(s.begin(), s.end());
    int i = 0;
    while (s[i] != mx)
        i++;
    string ret = best(s.substr(0, i));
    int mc = 0;
    for (auto c: s)
        if (c == mx)
            mc++;
    ret = string(mc, mx) + ret;
    ostringstream out;
    for (int j = i;j < n; j++)
        if (s[j] != mx)
            out << s[j];
    return ret + out.str();
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;

    for (int tno = 1;tno <= T; tno++) {
        string S;
        cin >> S;
        cout << "Case #" << tno << ": " << best(S) << endl;
    }

    return 0;
}
