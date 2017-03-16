
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        string a;
        string s;
        cin >> a;
        cin>>s;

        int out = 0;
        int d = 0;
        for (int i=0;i<s.size();++i) {
            int v = s[i]-'0';
            if (v > 0) {
                out = std::max(out, i - d);
                d += v;
            }
        }

        printf("Case #%d: %d\n", t, out);
    }
}
