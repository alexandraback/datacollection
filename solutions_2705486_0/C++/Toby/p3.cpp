#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

string S;
vector<string> dict;

unsigned int state[51][5];
int solve() {
    memset(state, -1, sizeof(state));
    state[0][0] = 0;

    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (state[i][j] > S.size())
                continue;
            for (vector<string>::iterator w_it = dict.begin(); w_it != dict.end(); ++w_it) {
                const string &w = *w_it;
                if (i + w.size() > S.size())
                    continue;
                int count = 0;
                int mod = j;
                for (int pos = 0; pos < w.size(); pos++) {
                    if (w[pos] != S[i+pos]) {
                        if (mod > 0) {
                            count = 9999;
                            break;
                        } else {
                            count++;
                            mod = 5;
                        }
                    }
                    mod--;
                }
                if (mod < 0)
                    mod = 0;
                if (state[i + w.size()][mod] > state[i][j] + count)
                    state[i + w.size()][mod] = state[i][j] + count;
            }
        }
    }

    unsigned int ans = 9999;
    for (int i = 0; i < 5; i++)
        ans = min(ans, state[S.size()][i]);

    return ans;
}

int main() {
    ifstream dict_file;
    dict_file.open("garbled_email_dictionary.txt");
    for (int i = 0; i < 521196; i++) {
        string w;
        dict_file >> w;
        dict.push_back(w);
    }
    dict_file.close();


    int T;
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> S;
        printf("Case #%d: %d\n", testcase, solve());
    }
    return 0;
}
