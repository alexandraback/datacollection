#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
int a[] = {'a', 'o', 'e', 'i', 'u'}, n, m;
string s;
int check(char c) {
    for (int i = 0; i < 5; ++i)
        if (c == a[i])
            return 0;
    return 1;
}
int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        cin >> s >> n;
        int l = s.size();
        long long ans = 0;
        long long total = 0;
        int a1 = 0, a2 = -1;
        for (int i = 0; i < l; ++i) {
            total += i+1;
            if (!check(s[i]))
                a2 = i;
            //cout << a2 << endl;
            if (i-a2 >= n) {
                a1 = i-n+2;
            }
            ans += i-a1+1;
        }
        cout << total-ans << endl;
    }
    return 0;
}
