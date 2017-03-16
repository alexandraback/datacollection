#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <strstream>
#include <sstream>
using namespace std;
int t;
long long a, b;
int check(long long n) {
    stringstream ss;
    ss << n;
    string s = ss.str();
    int l = s.size();
    for (int i = 0; 2*i < l; ++i)
        if (s[i] != s[l-1-i])
            return 0;
    return 1;
}
long long solve(long long n) {
    if (n < 1)
        return 0;
    long long ret = 0;
    for (int i = 1; ; ++i) {
        stringstream ss;
        ss << i;
        string s = ss.str();
        int l = s.size();
        string s1 = s;
        for (int i = 0; i < l-1; ++i)
            s1 += s[l-2-i];
        string s2 = s;
        for (int i = 0; i < l; ++i)
            s2 += s[l-1-i];
        ss.clear();
        ss.str(s1);
        long long a1, a2;
        ss >> a1;
        ss.clear();
        ss.str(s2);
        ss >> a2;
        //cout << a1 << " " << a2 << endl;
        if (a1*a1 > n)
            break;
        if (check(a1*a1))
            ret++;
        if (a2*a2 <= n && check(a2*a2))
            ret++;
    }
    return ret;
}
int main() {
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cin >> a >> b;
        cout << "Case #" << tt << ": ";
        cout <<  (solve(b) - solve(a-1)) << endl;
    }
    return 0;
}
