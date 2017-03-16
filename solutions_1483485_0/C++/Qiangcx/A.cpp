#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

#define Fup(i, s, t) for (int i = s; i <= t; i ++)
#define Fdn(i, s, t) for (int i = s; i >= t; i --)
#define Path(i, s) for (int i = s; i; i = d[i].next)

using namespace std;

const char id[27] = "yhesocvxduiglbkrztnwjpfmaq";
string str;

void solve()
{
    getline(cin, str);
    Fup(i, 0, (int)str.size() - 1)
        if (str[i] != ' ')
            cout << id[str[i] - 'a'];
        else
            cout << ' ';
    cout << endl;
}

int main()
{
//    freopen("temp.in", "r", stdin);
//    freopen("temp.out", "w", stdout);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    getline(cin, str);
    Fup(i, 1, t){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
