
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

using namespace std;

typedef long long int LLI;
typedef pair < int , int > PII;
typedef pair < LLI , LLI > PLL;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < PII > VP;
typedef vector < LLI > VL;
typedef vector < PLL > VPL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;
typedef vector < VP > VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const LLI LLINF = 1000000000000000001LL;

/*************************************************************************/

const int ALPH = 'z' - 'a' + 1;
int cnt[ALPH];

const string name[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR",
    "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

string curr;

void change(int dig, int add) {
    for (char c : name[dig]) {
        cnt[c - 'A'] += add;
    }
}

bool anyNeg() {
    return *min_element(cnt, cnt + ALPH) < 0;
}

bool getAnswer(int lower) {
    if (anyNeg()) {
        return false;
    } else if (*max_element(cnt, cnt + ALPH) == 0) {
        return true;
    }

    FOR(i,lower,9) {
        change(i, -1);
        curr.PB('0' + i);

        if (getAnswer(i)) return true;

        curr.pop_back();
        change(i, 1);
    }

    return false;
}

string solve(string &s) {
    FOR(i,0,ALPH-1) cnt[i] = 0;
    for (char c : s) cnt[c - 'A']++;

    curr = "";

    getAnswer(0);
    return curr;
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(i,1,t) {
        string s;
        cin >> s;

        cout << "Case #" << i << ": " << solve(s) << '\n';
    }

    return 0;
}

/*************************************************************************/

