#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

int K, L, S;
int keyCount[30], lastCode;

vector<int> t;
vector<int> g;

long double ans;

void gen(int v) {
    if (v == S) {
        long double p = 1, xi = 0;
        int i, j;

        for (i = 0; i < S; ++i)
            p *= (long double)keyCount[g[i]] / (long double)K;

        bool match;
        for (i = 0; i + L <= S; ++i) {
            match = true;
            for (j = i; j < i + L && match; ++j)
                match &= (g[j] == t[j - i]);
            xi += (long double)match;
        }
        ans -= p * xi;
        // cout << p << " " << xi << "\n";
        return;
    }
    for (g[v] = 0; g[v] < lastCode; ++g[v])
        gen(v + 1);
}

void solve() {
    memset(keyCount, 0, sizeof(keyCount));

    cin >> K >> L >> S;
    string keys, word;
    cin >> keys >> word;

    map<char, int> keyCode;
    lastCode = 0;

    int i, j;
    for (i = 0; i < K; ++i) {
        if (keyCode.find(keys[i]) == keyCode.end())
            keyCode.insert(make_pair(keys[i], lastCode++));
        keyCount[keyCode.find(keys[i])->second]++;
    }

    bool impossible = false;
    t.assign(L, 0);
    map<char, int>::iterator it;
    for (i = 0; i < L; ++i) {
        it = keyCode.find(word[i]);
        if (it != keyCode.end())
            t[i] = it->second;
        else {
            t[i] = -1;
            impossible = true;
        }
    }

    ans = 0;
    if (!impossible) {
        bool found = false;
        for (i = 1; i < L && !found; ++i) {
            found = true;
            for (j = i; j < L && found; ++j) {
                // cout << i << " " << j << " " << word[j] << " " << word[j - i] << "\n";
                found &= (word[j] == word[j - i]);
            }
            // cout << found << "\n";
        }
        j = i - (int)found;
        // cout << "j: " << j << "\n";
        for (i = 0; i + L <= S; i += j)
            ans++;
    }

    // cout << ans << "\n";

    g.assign(S, 0);

    gen(0);
    cout.precision(18);
    cout << ans << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    
    int _T, T;
    cin >> T;
    for (_T = 1; _T <= T; ++_T) {
        printf("Case #%d: ", _T);
        solve();
    }

    return 0;
}