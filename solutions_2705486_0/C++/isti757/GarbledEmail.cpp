#ifndef STDAFX_H
#define STDAFX_H

#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define F first
#define S second
#define PB push_back
#define PF push front
#define MP make_pair
#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define VAR(v,n) __typeof(n) v=(n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MOD(x, n) ((x)%(n)+(n))%(n)
#define SZ(x) (int((x).size()))
#define ALL(x) ((x).begin()),((x).end())
#define SORT(v) sort((v).begin(),(v).end())
#define REVERSE(v) reverse((v).begin(),(v).end())
#define UNIQUE(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
LL GCD( LL a , LL b ) { while( b ) b ^= a ^= b ^= a %= b ; return a ; }
LL LCM( LL a , LL b ) { return a * ( b / GCD( a , b ) ) ; }

typedef vector<int>    VI;
typedef vector<string> VS;
typedef vector<VI>     VVI;
typedef vector<LL>     VLL;
typedef vector<bool>   VB;
typedef vector<double> VD;
typedef vector<VD>     VVD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII>    VPII;
typedef pair<LL, LL>   PLL;
typedef vector<PLL>    VPLL;

const double EPS = 10e-9;
const double PI = acos(-1.0);
const int INF = (1LL << 30);

using namespace std;

template<typename T>
string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

struct node {
    char ch;
    bool end;
    node *childs[26];
    node(char c) {ch = c;}
};

node *getNode(char ch) {
    node *nd = new node(ch);
    nd->end = false;
    memset(nd->childs, 0, 26*sizeof(node*));
    return nd;
}

node *insert(node *nd, string &s) {
    node *curr = nd;
    REP(i, s.size()) {
        if(curr->childs[s[i]-'a'] == 0) {
            curr->childs[s[i]-'a'] = getNode(s[i]);
            curr = curr->childs[s[i]-'a'];
        } else {
            curr = curr->childs[s[i]-'a'];
        }
    }
    curr->end = true;
    return nd;
}

node *buildDict(VS &dict) {
    node *root = getNode(' ');
    REP(i, dict.size()) {
        root = insert(root, dict[i]);
    }
    return root;
}

int minChange(node *nd, string &s, int pos, int last) {
    if(pos >= s.size()) {
        if(nd->end)
            return 0;
        else
            return INF;
    }

    // can change
    if(pos-last >= 5) {
        int change = INF;
        REP(i, 26) {
            if(i+'a' != s[pos] && nd->childs[i] != 0) {
                change = min(change, minChange(nd->childs[i], s, pos+1, pos)+1);
            }
        }
        if(nd->childs[s[pos]-'a'] != 0) {
            change = min(change, minChange(nd->childs[s[pos]-'a'], s, pos+1, last));
        }
        return change;
    } else {
        // can't change
        if(nd->childs[s[pos]-'a'] == 0)
            return INF;
        else
            return minChange(nd->childs[s[pos]-'a'], s, pos+1, last);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif

    VS d;
    string word;
    ifstream dstr("dict");
    while(dstr >> word) {
        if(word == "c")
            cout << "YES" << endl;
        d.push_back(word);
    }

    node *dict = buildDict(d);

    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;
    REP(t, T) {
        string s;
        cin >> s;

        VVI dp(s.size(), VI(s.size()+1, INF));
        REP(i, s.size()) {
            for(int len = 1; len+i-1 < s.size(); len++) {
                string subs = s.substr(i, len);
                dp[i][len] = minChange(dict, subs, 0, -5);
            }
        }

        FOR(len, 1, s.size()) {
            FOR(i, 0, (int)s.size()-len) {
                FOR(l, 1, len-1) {
                    dp[i][len] = min(dp[i][l]+dp[i+l][len-l], dp[i][len]);
                    dp[i][len] = min(dp[i][len], INF);
                }
            }
        }

        printf("Case #%d: %d\n", (t+1), dp[0][s.size()]);
    }

    return 0;
}

#endif // STDAFX_H


