#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <cstring>


using namespace std;
typedef long long LL;
#define x1 gjigu
#define y1 djigd
template<typename T>
inline T Abs(const T& value) { return value < 0 ? -value : value; }
template<typename T>
inline T Sqr(const T& value) { return value * value; }


int a[256];
int b[256];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

a['a'] = 'y';
a['b'] = 'h';
a['c'] = 'e';
a['d'] = 's';
a['e'] = 'o';
a['f'] = 'c';
a['g'] = 'v';
a['h'] = 'x';
a['i'] = 'd';
a['j'] = 'u';
a['k'] = 'i';
a['l'] = 'g';
a['m'] = 'l';
a['n'] = 'b';
a['o'] = 'k';
a['p'] = 'r';
a['q'] = 'z';
a['r'] = 't';
a['s'] = 'n';
a['t'] = 'w';
a['u'] = 'j';
a['v'] = 'p';
a['w'] = 'f';
a['x'] = 'm';
a['y'] = 'a';
a['z'] = 'q';
/*    vector< vector<string> > s(2);
    for (int j = 0; j < 2; ++j) {
        s[j].resize(3);
        for (int i = 0; i < 3; ++i)
            getline(cin, s[j][i]);
    }

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < s[0][i].length(); ++j)
            if (s[0][i][j] != ' ')
                a[s[0][i][j]] = s[1][i][j];

    for (int i = 0; i < 26; ++i) {
        cout << "a['" << char(i+'a') << "'] = '" << char(a[i+'a']) << "';" << endl;
    }

    for (int i = 'a'; i <= 'z'; ++i)
        b[a[i]] = 1;
    for (int i = 'a'; i <= 'z'; ++i)
        if (!b[i])
            cout << char(i) << endl;
*/

    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        for (int j = 0; j < s.length(); ++j)
            if (s[j] != ' ')
                s[j] = a[s[j]];
        cout << "Case #" << i+1 << ": " << s << endl;
    } 

    return 0;
}
