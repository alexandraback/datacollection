#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1e9;

string unique(string s) {
    s.resize(unique(s.begin(), s.end())-s.begin());
    return s;
}

vector<int> histo(string s) {
    char c = s[0];
    vector<int> h;
    for(int i = 0, cnt = 1; i < s.size(); i++, cnt++) {
        if(s[i] != c) {
            h.push_back(cnt);
            c = s[i];
            cnt = 1;
        }
        if(i+1 == s.size())
            h.push_back(cnt);
    }
    return h;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        int N;
        cin >> N;

        vector<string> s(N);
        for(int i = 0; i < N; i++) {
            cin >> s[i];
        }

        bool ok = true;
        for(int i = 1; i < N; i++) {
            if(unique(s[i]) != unique(s[i-1]))
                ok = false;
        }

        if(ok) {
            vector<vector<int> > h(N);
            for(int i = 0; i < N; i++)
                h[i] = histo(s[i]);

            int sol = 0;
            for(int j = 0; j < h[0].size(); j++) {
                vector<int> p;
                for(int i = 0; i < h.size(); i++) {
                    p.push_back(h[i][j]);
                }

                int m = *min_element(p.begin(), p.end());
                int M = *max_element(p.begin(), p.end());

                int curr = INF;
                for(int k = m; k <= M; k++) {
                    int now = 0;
                    for(int i = 0; i < h.size(); i++) {
                        now += abs(h[i][j]-k);
                    }
                    curr = min(curr, now);
                }

                sol += curr;
            }
            printf("%d\n", sol);
        } else {
            puts("Fegla Won");
        }
    }
    return 0;
}

