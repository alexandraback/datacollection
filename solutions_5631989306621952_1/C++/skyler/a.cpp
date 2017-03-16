#include <iostream>
#include <deque>
using namespace std;

string proc(string s) {
    deque<char> dq;
    dq.push_back(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= dq.front()) {
            dq.push_front(s[i]);
        } else {
            dq.push_back(s[i]);
        }
    }

    string ret = "";
    while (!dq.empty()) {
        ret += dq.front();
        dq.pop_front();
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string s;
        cin >> s;
        cout << "Case #" << i << ": " << proc(s) << endl;
    }
    return 0;
}
