#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

bool possible = true;
const int MAX = 26;
int n;

int c[MAX][MAX];
int u[MAX];
int p[MAX][MAX];
int t[MAX][MAX];
bool uniq[MAX];


unsigned long long f(int i) {
    if (i < 2) return 1;
    return (i * f(i - 1)) % 1000000007;
}

unsigned long long from(int j) {
    unsigned long long r = f(c[j][j]);
    c[j][j] = 0;
    for (int i = 0; i < MAX; i++) {
        if (c[j][i] == 0) continue;
        // c[j][i] = 0;
        if (!uniq[i]) {
            possible = false;
            return 0;
        }
        uniq[i] = false;
        r *= from(i);
        r %= 1000000007;
    }
    return r;
}

unsigned long long to(int j) {
    unsigned long long r = f(c[j][j]);
    c[j][j] = 0;
    for (int i = 0; i < MAX; i++) {
        if (c[i][j] == 0) continue;
        // c[i][j] = 0;
        if (!uniq[i]) {
            possible = false;
            return 0;
        }
        uniq[i] = false;
        r *= to(i);
        r %= 1000000007;
    }
    return r;
}

int main() {
    int tcc;
    scanf("%d", &tcc);
    for (int tc = 1; tc <= tcc; tc++) {
        printf("Case #%d: ", tc);
        string s;
        cin >> n;
        possible = true;
        for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) {
            c[i][j] = 0;
            t[i][j] = 0;
            u[i] = -1;
            uniq[i] = true;
        }
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 1; j < s.size(); j++) {
                if (s[j-1] == s[j]) continue;
                t[s[j] - 'a'][s[j - 1] - 'a']++;
            }
            c[s[0] - 'a'][s[s.size() - 1] - 'a']++;
        }
        for (int i = 0; i < MAX; i++) {
            int c = 0;
            for (int j = 0; j < MAX; j++) {
                c += t[i][j];
            }
            possible = possible && c < 2;

        }
        unsigned long long result = 1;
        if (possible) {
            int p = 0;
            for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++) {
                if (i == j) continue;
                if (c[i][j] == 0) continue;
                p++;
                if (!uniq[i]) {
                    possible = false;
                    break;
                }
                uniq[i] = false;
                if (!uniq[j]) {
                    possible = false;
                    break;
                }
                uniq[j] = false;
                result *= to(i);
                result %= 1000000007;
                result *= from(j);
                result %= 1000000007;
            }
            for (int i = 0; i < MAX; i++) {
                if (c[i][i] == 0) continue;
                result *= f(c[i][i]);
                result %= 1000000007;
                p++;
            }
            result *= f(p);
        }

        if (possible) {
            result %= 1000000007;
            printf("%llu\n", result);
        } else {
            // cerr << "IM" << endl;
            printf("0\n");
        }
    }
    return 0;
}

