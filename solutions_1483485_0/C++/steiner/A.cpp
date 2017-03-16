#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<char> a;
    
void solve() {
     string s;
     getline(cin, s);
     string str;
     for (int i = 0; i < sz(s); ++i)
         if (s[i] == ' ')
             str.pb(' ');
         else
             str.pb('a' + a[s[i] - 'a']);
     cout << str << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    a.assign(26, 30);
    vector<string> s1(3);
    s1[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    s1[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    s1[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    vector<string> s2(3);
    s2[0] = "our language is impossible to understand";
    s2[1] = "there are twenty six factorial possibilities";
    s2[2] = "so it is okay if you want to just give up";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < sz(s1[i]); ++j)
            if (s1[i][j] != ' ')
                a[s1[i][j] - 'a'] = s2[i][j] - 'a';
    a['z' - 'a'] = 'q' - 'a';
    vector<bool> ok(26, false);
    for (int i = 0; i < 26; ++i)
        if (a[i] < 26)
            ok[a[i]] = true;
    for (int i = 0; i < 26; ++i)
        if (!ok[i])
            a['q' - 'a'] = i;
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    for (int tests = 0; tests < t; ++tests) {
        cout << "Case #" << tests + 1 << ": ";
        solve();
    }   
    return 0;
}
