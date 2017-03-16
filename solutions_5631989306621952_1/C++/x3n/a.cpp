#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        string s;
        cin >> s;

        string beg = "", end = "";
        beg += s[0];

        for (int i = 1; i < s.size(); i++) {
            if (s[i] >= beg.back())
                beg += s[i];
            else end += s[i];
        }

        reverse(beg.begin(), beg.end());
        cout << "Case #" << z << ": " << beg + end << endl;
    }

    return 0;
}
