#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int P = 1000000007;

int T, n;

char s[100][100], c;

int l[26], r[26], m[26], a[26];

long long fact[101];

void shows() {
    for (int i = 0; i < n; ++i) {
        cout << (int)s[i][0] << " " << s[i] + 1 << endl;
    }
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("b.out", "w", stdout);
    fact[0] = 1;
    for (int i = 1; i <= 100; ++i) {
        fact[i] = (i * fact[i - 1]) % P;
    }
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        memset(m, 0, sizeof m);
        memset(a, 0, sizeof a);
        
        cin >> n;
        while ((c = getchar()) != '\n');
        for (int i = 0, j; i < n; ++i) {
            for (j = 1; ; ++j) {
                for (c = getchar(); (c < 'a' || c > 'z') && c != ' ' && c != '\n'; c = getchar());
                if (c == ' ' || c == '\n')
                    break;
                if (j == 1 || c != s[i][j - 1])
                    s[i][j] = c;
                else --j;
            }
            s[i][j] = 0;
            s[i][0] = (char)(j - 1);
            
        }
        
        //shows();
        
        for (int i = 0; i < n; ++i) {
            if ((int)s[i][0] == 1) {
                ++a[s[i][1] - 'a'];
                continue;
            }
            for (int j = (int)s[i][0]; j > 0; --j) {
                if (j == (int)s[i][0])
                    ++r[s[i][j] - 'a'];
                else if (j == 1)
                    ++l[s[i][j] - 'a'];
                else
                    ++m[s[i][j] - 'a'];
            }
        }
        long long ans = 1;
        int h = 0, t = 0, b = 0;
        for (int i = 0; i < 26; ++i) {
            if (l[i] > 1) goto impossible;
            if (r[i] > 1) goto impossible;
            if (m[i] > 1) goto impossible;
            if (m[i] * (l[i] + r[i] + a[i]) > 0) goto impossible;
            //ring
            
            ans = (ans * fact[a[i]]) % P;
            if (l[i] * r[i] == 0) {
                h += l[i];
                t += r[i];
                if (l[i] + r[i] == 0 && a[i] != 0)
                    ++b;
            }
        }
        //cout << ans << endl;
        ans = (ans * fact[h + b]) % P;
        //cout << h << " " << t << " " << b << endl;
        if (0 == h && b == 0) 
            goto impossible;
        
        printf("Case #%d: %lld\n", cs, ans);
        
        continue;
impossible :
        printf("Case #%d: 0\n", cs);
exit:
        continue;
        
    }
    return 0;
}
