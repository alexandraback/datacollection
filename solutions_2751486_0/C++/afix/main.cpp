// GCJ 1C - Problem A
#include <fstream>
//#include <iostream>
#include <string>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void solve() {
    string s;
    long long k;
    fin >> s >> k;
    int n = s.length();
    vector<long long> v(n), d;
    d.assign(n, 0);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') v[i] = 0;
        else v[i] = 1;
        if (v[i]) d[i] = (i > 0 ? d[i - 1] : 0) + 1;
        else d[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        d[i] = (d[i] >= k);
    }
    int i = k - 1, j = i;
    while (i < n) {
        while (j < n && !d[j]) ++j;
        if (j == n) break;
        ans += (n - j);
        ++i;
        if (j < i) j = i;
    }
    fout << ans << endl;
}

void init() {

}

int main()
{
    int T;
    fin >> T;
    for (int I = 1; I <= T; ++I) {
        fout << "Case #" << I << ": ";
        init();
        solve();
    }

    return 0;
}
