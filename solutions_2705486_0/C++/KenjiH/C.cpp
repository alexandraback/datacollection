#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  

//vector<string> words[16];
vector<string> words;

void init() {
    FILE *fp = fopen("dictionary.txt", "r");
    char str[128];
    while (fgets(str, 128, fp) != NULL) {
        int len = strlen(str);
        //words[len].push_back(str);
        str[len-1] = '\0';
        words.push_back(str);
    }
    
    cerr << words[0] << endl;
    cerr << words[words.size()-1] << endl;
    cerr << words.size() << endl;

}


int dp[64][64];   // (pos, last) => miss
const int oo = 1<<28;

pair<int, int> check(const string &s, const string &word, int pos, int head) {
    int cnt = 0;
    int tail = head;

    REP (i, word.length()) {
        if (pos+i >= (int)s.length())
            return make_pair(oo, oo);

        if (word[i] != s[pos+i]) {
            ++cnt;
            if (pos + i - tail < 5)
                return make_pair(oo, oo);
            tail = pos + i;
        }
    }

    if (tail == -10)
        tail = 0;
    else
        ++tail;
 
    return make_pair(cnt, tail);
}


void solve() {
    memset(dp, 0, sizeof(dp));

    REP (i, 64) REP (j, 64) dp[i][j] = oo;
    dp[0][0] = 0;
    string s;
    cin >> s;
    
    REP (i, s.length()) {
        REP (j, 64) {
            if (dp[i][j] == oo)
                continue;
            REP (k, words.size()) {
                int head = j ? j-1 : -10;
                pair<int, int> p = check(s, words[k], i, head);

                int cnt = p.first;
                int tail = p.second;

                if (cnt == oo)
                    continue;

                dp[i+words[k].length()][tail] = min(dp[i+words[k].length()][tail], dp[i][j] + cnt);
            }
        }
    }

    int ret = oo;
    REP (i, 64) ret = min(dp[s.length()][i], ret);
    cout << ret << endl;
}


int main() {
    init();

    int T;
    cin >> T;
    REP (i, T) {
        cout << "Case #" << (i+1) << ": "; 
        cerr << "Case #" << (i+1) << endl;
        solve();
    }

    return 0;
}
