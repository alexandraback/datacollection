#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>


using namespace std;
#define ll long long


int C[30];
int lft = 0;

string L[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

string solve(int dig) {
    if (lft == 0) {
        return ".";
    }
    if (dig == 10) return "";

    string out = solve(dig+1);
    if (out != "") {
        return out;
    }
    string l = L[dig];
    bool good = true;
    for (int j=0;j<l.size();++j) {
        C[l[j]-'A']--;
        good &= C[l[j]-'A'] >= 0;
        lft--;
    }
    if (good) {
        out = solve(dig);
        if (out != "") {
            char a = '0' + dig;
            return string() + a + out;
        }
    }

    for (int j=0;j<l.size();++j) {
        C[l[j]-'A']++;
        lft++;
    }

    return "";
}

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        string s;
        cin>>s;

        memset(C,0,sizeof(C));
        lft = 0;
        for (int i=0;i<s.size();++i) {
            C[s[i]-'A']++;
            lft++;
        }

        string ans = solve(0);



        printf("Case #%d: %s\n", t, ans.substr(0, ans.size()-1).c_str());
    }

}
