#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

string ss;
int m;
int l;

void foo(string s, int d) {
    if(d==l*2) {
        int a = atoi(s.substr(0,l).c_str());
        int b = atoi(s.substr(l).c_str());
        if(abs(a-b)<m) {
            ss = s;
            m = abs(a-b);
        }
        return;
    }

    if(s[d]=='?') {
        for(int i=0;i<10;i++) {
            s[d] = '0'+i;
            foo(s, d+1);
        }
        s[d]='?';
    } else {
        foo(s, d+1);
    }
}

int main() {
    int T;
    cin >> T;

    for(int cs=1; cs<=T; cs++) {
        string C,J;

        cin >> C >> J;

        l = C.size();
        m = 10000;
        foo(C+J, 0);

        printf("Case #%d: %s %s\n", cs,
                ss.substr(0,l).c_str(), ss.substr(l).c_str());
    }

    return 0;
}
