#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 5;
/**
int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int t, c, d, v, dd[5];

    cin >> t;
    for(int ca = 1; ca <= t; ca ++) {
        cin >> c >> d >> v;
        for(int i = 0; i < d; i ++)
            cin >> dd[i];
        cout << "Case #" << ca << ": ";
        if(v == 1) {
            if(dd[0] == 1) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else if(v <= 3) {
            if(dd[0] == 1 && dd[1] == 2) cout << 0 << endl;
            else if(dd[0] == 1 || dd[0] == 2) cout << 1 << endl;
            else cout << 2 << endl;
        }
        else if(v <= 6) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3) cnt ++;
            }
            cout << 3 - cnt << endl;
        }
        else if(v <= 10) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 4 || dd[i] == 5) cnt ++;
            }
            cout << 4 - cnt << endl;
        }
        else if(v == 11) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 5) cnt ++;
            }
            cout << 4 - cnt << endl;
        }
        else if(v <= 20) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 5 || dd[i] == 9) cnt ++;
            }
            cout << 5 - cnt << endl;
        }
        else if(v == 21) {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 5 || dd[i] == 10) cnt ++;
            }
            cout << 5 - cnt << endl;
        }
        else {
            int cnt = 0;
            for(int i = 0; i < d; i ++) {
                if(dd[i] == 1 || dd[i] == 2 || dd[i] == 3 || dd[i] == 5 || dd[i] == 9 || dd[i] == 10) cnt ++;
            }
            cout << 6 - cnt << endl;
        }
    }

    return 0;
}
*/

void getNxt(const char *x, int m, int nxt[]) {
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i < m) {
        while (j > -1 && x[i] != x[j])
            j = nxt[j];
        i ++;
        j ++;
        if (x[i] == x[j])
            nxt[i] = nxt[j];
        else
            nxt[i] = j;
    }
}

int KMP(const char *x, int m, int n) {
    int i, j, nxt[m + 5];

    getNxt(x, m, nxt);

    int cnt = 0;
    i = j = 0;
    while (j < n) {
        i ++;
        j ++;
        if (i >= m) {
            cnt ++;
            i = nxt[i];
        }
    }
    return cnt;
}

int maxMatch(string &word, int S) {
    return KMP(word.c_str(), word.length(), S);
}

long double solve(string &word, string &key, int S, int L) {
    int keycnt[26];
    memset(keycnt, 0, sizeof(keycnt));
    for(int i = 0; i < key.length(); i ++) {
        keycnt[key[i]-'A'] ++;
    }

    long double res = 1;
    for(int i = 0; i < word.length(); i ++) {
        res *= (long double)keycnt[word[i]-'A'] / key.length();
    }
    res *= S - L + 1;
    return res;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int t;
    cin >> t;
    for(int ca = 1; ca <= t; ca ++) {
        int K, L, S;
        string key, word;
        cin >> K >> L >> S;
        cin >> key >> word;
        int flg = maxMatch(word, S);
        for(int i = 0; i < word.length(); i ++) {
            if(key.find(word[i]) == string::npos) {
                flg = 0;
                break;
            }
        }
        cout << "Case #" << ca << ": ";
        if(flg == 0) {
            printf("%.6lf\n", 0.0);
            continue;
        }
        printf("%.6lf\n", (double)(flg - solve(word, key, S, L)));
    }
    return 0;
}
