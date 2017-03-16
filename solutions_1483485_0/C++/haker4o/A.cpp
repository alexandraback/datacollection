#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

char m[128];

void fillMapping(string from, string to) {
    for(int i=0; i<from.size(); ++i) {
        m[from[i]] = to[i];
    }
}

int main() {
    int i, j;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    memset(m, 0, sizeof(m));
    fillMapping("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
    fillMapping("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
    fillMapping("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
    m['q'] = 'z';
    m['z'] = 'q';
    m[' '] = ' ';
    int NT, T;
    cin>>NT;
    string s;
    getline(cin, s);
    for(T=1; T<=NT; ++T) {
        getline(cin, s);
        for(i=0; i<s.size(); ++i) {
            s[i] = m[s[i]];
        }
        cout<<"Case #"<<T<<": "<<s<<endl;
    }
    return 0;
}

