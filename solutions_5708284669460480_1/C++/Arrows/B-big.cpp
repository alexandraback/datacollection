#include <bits/stdc++.h>

using namespace std;

void preproc(const char *x, int m, int next[]) {
    int i, j;
    i = 0;
    j = next[0] = -1;
    while (i < m) {
        while (j > -1 && x[i] != x[j])
            j = next[j];
        i++, j++;
        if (x[i] == x[j])
            next[i] = next[j];
        else
            next[i] = j;
    }
}

int kmp(const char *x, int m, int n) {
    int i, j, *next;
    next = new int[m+5];

    preproc(x, m, next);
    int cnt = 0;
    i = j = 0;
    while (j < n) {
        i++, j++;
        if (i >= m) {
            cnt++;
            i = next[i];
        }
    }
    delete[] next;
    return cnt;
}

long double calc(string &word, string &kb, int S, int L) {
    int cnt[50];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < kb.length(); i++) {
        cnt[kb[i]-'A']++;
    }

    long double single = 1;
    for(int i = 0; i < word.length(); i++) {
        single *= (long double)cnt[word[i]-'A'] / kb.length();
    }
    single *= S-L+1;
    return single;
}

int match(string &word, int S) {
    return kmp(word.c_str(), word.length(), S);
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t ; cas ++) {
        int K, L, S;
        string kb;
        string word;
        cin >> K >> L >> S;
        cin >> kb;
        cin >> word;
        int carry = match(word, S);
        for(int i = 0; i < word.length(); i++) {
            if(kb.find(word[i]) == string::npos) {
                carry = 0;
                break;
            }
        }
        cout << "Case #" << cas << ": ";
        if(carry==0) {
            printf("%.6lf\n", 0.0);
            continue;
        }
        printf("%.6lf\n", (double)(carry-calc(word, kb, S, L)));
    }
    return 0;
}
