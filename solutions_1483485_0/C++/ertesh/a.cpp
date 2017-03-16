#include <iostream>
#include <vector>
using namespace std;

int main() {
    string t[3];
    t[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    t[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    t[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string d[3];
    d[0] = "our language is impossible to understand";
    d[1] = "there are twenty six factorial possibilities";
    d[2] = "so it is okay if you want to just give up";

    vector<int> v(26, -1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < t[i].length(); j++) {
            if (t[i][j] == ' ') continue;
            int p = t[i][j] - 'a';
            int q = d[i][j] - 'a';
            if (v[p] == -1) v[p] = q;
            else if (v[p] != q) {
                cout << "error " << p << " " << v[p] << " " << q << endl;
            }
        }
    }
    v['q' - 'a'] = 'z' - 'a';
    v['z' - 'a'] = 'q' - 'a';
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int te = 1; te <= n; te++) {
        getline(cin, s);
        cout << "Case #" << te << ": ";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                cout << ' ';
                continue;
            }
            int p = s[i] - 'a';
            char q = 'a' + v[p];
            cout << q;
        }
        cout << endl;
    }
}
