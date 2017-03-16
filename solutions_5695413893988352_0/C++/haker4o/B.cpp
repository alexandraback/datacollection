#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int l;

string s;

string b1, b2;

int best = 10000;

int calc() {
    string s1, s2;
    s1 = s.substr(0, l);
    s2 = s.substr(l);
    int a1, a2;
    a1 = atoi(s1.c_str());
    a2 = atoi(s2.c_str());
//    sscanf(s1.c_str(), "%d", &a1);
//    sscanf(s2.c_str(), "%d", &a2);
    return (a1 <= a2 ? a2-a1 : a1-a2);
}

void rec(int cur) {
    if (cur >= s.size()) {
        int t = calc();
        if (t < best ||
            t == best && b1 > s.substr(0, l) ||
            t == best && b1 == s.substr(0, l) && b2 > s.substr(l)) {

            b1 = s.substr(0, l);
            b2 = s.substr(l);
            best = t;
        }
        return;
    }
    if (s[cur] == '?') {
        for(char i='0'; i<='9'; ++i) {
            s[cur] = i;
            rec(cur+1);
        }
        s[cur] = '?';
    } else {
        rec(cur+1);
    }
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T, NT;
    int i, j;
    cin>>NT;
    string s1, s2;
    for(T=1; T<=NT; ++T) {
        cin>>s1>>s2;
        l = s1.size();
        s = s1 + s2;
        best = 10000;
        rec(0);
        cout<<"Case #"<<T<<": "<<b1<<" "<<b2<<endl;
    }
    return 0;
}
