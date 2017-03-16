#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;


vector<string> words[11];

int dp[4001];

int edit_dist(string s, int ix, string cmp) {
    int ret = 0;
    for (int i=0;i<cmp.length();i++) {
        if (s[ix+i] != cmp[i]) {
            ret++;
            if (abs(s[ix+i] - cmp[i]) < 5) return 40000;
        }
    }
    return ret;
}

int min_edit_dist(string s, int ix, int l) {
    int ret = 4001;
    for (int i=0;i<words[l].size();i++) {
        int dist = edit_dist(s, ix, words[l][i]);
        if (dist < ret) ret = dist;
    }
    return ret;
}


int main() {
    ifstream fin("garbled_email_dictionary.txt");

    string s;
    int maxlen = 0;
    while (fin >> s) {
        words[s.length()].push_back(s);
    }

    int T; string t;
    cin >> T;
    
    for (int c = 1; c <= T; c++) {
        cin >> t;
        int N = t.length();

        for (int i =0; i <=N;i++) dp[i] = 4001;
        dp[0] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 1 ; j<= min(10, N - i); j++) {
                int dist = min_edit_dist(t, i, j);
                if (dp[i] + dist < dp[i+j])
                    dp[i+j] = dp[i] + dist;
            }
        }

        printf("Case #%d: %d\n", c, dp[N]);
    }

}
