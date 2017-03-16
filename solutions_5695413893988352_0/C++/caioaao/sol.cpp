#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define ms(x,v) memset((x), (v), sizeof(x))

#define _NO_USE_LOG
#ifdef _USE_LOG
#define LOG(x) cout << x;
#else
#define LOG(x)
#endif

using namespace std;

typedef long long L;
typedef unsigned long long UL;
typedef double D;
typedef pair<L,L> PL;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef vector<PL> VPL;
typedef vector<VPL>VVPL;
typedef pair<string, string> PS;
typedef pair<int, PS > ANS;

int p10(int x) {
    int p = 1;
    while(x--) p*= 10;
    return p;
}

string s1, s2;
int n;
int l;
string mks(int x){
    string r;
    for(int i = 0; i < l; ++i) {
        r.pb(x%10 + '0'); x/=10;
    }
    reverse(r.begin(), r.end());
    return r;
}

bool poss(const string& s1, const string& so) {
    for(int i = 0; i < l; ++i) {
        if(s1[i] != so[i] && so[i] != '?') return false;
    }
    return true;
}

int delt(const string& s1, const string& s2) {
    int d = 0;
    for(int i = 0; i <l; ++i) {
        d = d*10 + s1[i] - s2[i];
    }
    return abs(d);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        cin >> s1 >> s2;
        l = s1.length();
        n = p10(l);
        string bs1,bs2;
        ANS ans(10000, PS("", ""));
        for(int i = 0; i < n; ++i) {
            bs1 = mks(i);
            if(poss(bs1, s1)){
                for(int j = 0; j < n; ++j) {
                    bs2 = mks(j);
                    if(poss(bs2, s2)) {
                        ans = min(ans, ANS(delt(bs1, bs2), PS(bs1, bs2)));
                    }
                }
            }
        }

        LOG(ans.ff << endl);
        cout << ans.ss.ff << ' ' << ans.ss.ss;
        cout << '\n';
    }
}
