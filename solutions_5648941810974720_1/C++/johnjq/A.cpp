#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;


map<char, int> freq;
map<int, int> cnt;
void take(string s) {
    for (const int c : s)
        --freq[c];
}
void run(string s, char c, int d) {
    while (freq[c]) {
        ++cnt[d];
        take(s);
    }
}

int main() {
    int t;
    cin>>t;
    for (int testcase = 1; testcase <= t; ++testcase) {
        string s;
        cin>>s;
        cout<<"Case #"<<testcase<<": ";

        freq.clear();
        cnt.clear();
        for (char c : s)
            ++freq[c];

        run("EIGHT", 'G', 8);
        run("ZERO", 'Z', 0);
        run("TWO", 'W', 2);
        run("FOUR", 'U', 4);
        run("FIVE", 'F', 5);
        run("ONE", 'O', 1);
        run("THREE", 'R', 3);
        run("SEVEN", 'V', 7);
        run("SIX", 'X', 6);
        run("NINE", 'N', 9);

        for (int d = 0; d <= 9; ++d) {
            for (int i = 1; i <= cnt[d]; ++i)
                putchar('0'+d);
        }
        putchar('\n');
    }
}
