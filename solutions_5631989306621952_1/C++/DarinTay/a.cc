#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>


using namespace std;
#define ll long long



string s;

string solve(int pos) {
    if (pos <= 0) {
        return "";
    }
    char bestChar = '\0';
    int bestPos;
    for (int i = pos-1; i>=0;--i) {
         if (s[i] > bestChar) {
            bestChar = s[i];
            bestPos = i;
         }
    }

    string out = string("") + bestChar + solve(bestPos) + s.substr(bestPos+1, pos - bestPos - 1);
    return out;
}


int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cin>>s;

        string v = solve(s.size());
        printf("Case #%d: %s\n", t, v.c_str());
    }

}
