#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

int tn, kol[1000];
string s;

void remove (int k, string a) {
//    cerr << k << " " << a << endl;
    for(int i = 0; i < a.length(); i++) kol[a[i]] -= k;
}

string mkstring (string a, int kk) {
    string ret = "";
    for(int i = 1; i <= kk; i++) ret += a;
    return ret;
}

int main () {
    cin >> tn;
    int cc = 0;
    while (tn--) {
        ++cc;
        cin >> s;
        for(int i = 0; i < s.length(); i++) {
            ++kol[s[i]];
        }
        
        string ans = "";
        ans += mkstring("0", kol['Z']); remove(kol['Z'], "ZERO");
        ans += mkstring("2", kol['W']); remove(kol['W'], "TWO");
        ans += mkstring("4", kol['U']); remove(kol['U'], "FOUR");
        ans += mkstring("5", kol['F']); remove(kol['F'], "FIVE");
        ans += mkstring("6", kol['X']); remove(kol['X'], "SIX");
        ans += mkstring("7", kol['S']); remove(kol['S'], "SEVEN");
        ans += mkstring("1", kol['O']); remove(kol['O'], "ONE");
        ans += mkstring("9", kol['N']/2); remove(kol['N']/2, "NINE");
        ans += mkstring("8", kol['G']); remove(kol['G'], "EIGHT");
        ans += mkstring("3", kol['T']); remove(kol['T'], "THREE");
        
        for(int i = 1; i < 1000; i++) assert(kol[i]==0);
        
        for(int i = 0; i < ans.length(); i++) for(int j = i + 1; j < ans.length(); j++) if (ans[i] > ans[j]) swap(ans[i], ans[j]);
        
        cout << "Case #" << cc << ": " << ans << endl;
        
    }
    return 0;
}