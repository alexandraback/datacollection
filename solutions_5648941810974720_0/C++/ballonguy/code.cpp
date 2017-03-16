#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())

int cnt[2222];

string solve() {
    string s; cin>>s;
    memset(cnt, 0, sizeof(cnt));
    FOR(i,0,sz(s)-1) cnt[s[i]]++;
    vector<pair<int, int> > all;
    string dig[]={
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    };
    all.pb(mp(0, 'Z'));
    all.pb(mp(8, 'G'));
    all.pb(mp(6, 'X'));
    all.pb(mp(7, 'S'));
    all.pb(mp(5, 'V'));
    all.pb(mp(4, 'F'));
    all.pb(mp(2, 'W'));
    all.pb(mp(3, 'R'));
    all.pb(mp(1, 'O'));
    all.pb(mp(9, 'I'));
    string ans = "";
    FOR(i,0,sz(all)-1) {
        int cur = cnt[all[i].second];
        FOR(j,1,cur) {
            int d = all[i].first;
            ans += char(d+'0');
            FOR(pos,0,sz(dig[d])-1) cnt[dig[d][pos]]--;
        }
    }
    sort(ans.begin(), ans.end());
    FOR(i,'A','Z') if(cnt[i]) cerr<<"WFT"<<endl;
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int tests;
    cin>>tests;
    FOR(idtest, 1, tests) {
        string ans = solve();
        cout<<"Case #"<<idtest<<": "<<ans<<endl;
    }
}
