#include <iostream>
#include <string>
#include <list>

using namespace std;

void main2(int x) {
    string s;
    list<char> lst;
    cin >> s;
    lst.push_front(s[0]);
    for (uint i = 1; i < s.length(); ++i) {
        if (lst.front() > s[i]) {
            lst.push_back(s[i]);
        } else
            lst.push_front(s[i]);
    }

    string ans(lst.begin(), lst.end());
    cout << ans << '\n';
}
