#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> vns(10);
vector<ll> v[300], ans;
ll i, j, num, f, k, l, t, _t, h[300], hg[300][300], c, tmp, m[100];
string s;
int main() {
    vns[0] = "ZERO";
    vns[1] = "ONE";
    vns[2] = "TWO";
    vns[3] = "THREE";
    vns[4] = "FOUR";
    vns[5] = "FIVE";
    vns[6] = "SIX";
    vns[7] = "SEVEN";
    vns[8] = "EIGHT";
    vns[9] = "NINE";
    m[0] = 'Z'-'A';
    m[1] = 'O'-'A';
    m[2] = 'W'-'A';
    m[3] = 'R'-'A';
    m[4] = 'U'-'A';
    m[5] = 'F'-'A';
    m[6] = 'X'-'A';
    m[7] = 'V'-'A';
    m[8] = 'G'-'A';
    m[9] = 'N'-'A';

    cin>>t;
    for(_t = 1; _t <= t; _t++) {
        cin>>s;
        l = s.length();
        memset(h, 0, sizeof h);
        for(i = 0; i < l; i++) {
            h[s[i]-'A']++;
        }
        for(i = 0; i < 10; i += 2) {
            while(h[m[i]] > 0) {
                for(j = 0; j < vns[i].size(); j++) {
                    c = vns[i][j] - 'A';
                    h[c]--;
                }
                ans.push_back(i);
            }
        }
        for(i = 1; i < 10; i += 2) {
            while(h[m[i]] > 0) {
                for(j = 0; j < vns[i].size(); j++) {
                    c = vns[i][j] - 'A';
                    h[c]--;
                }
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());
        printf("Case #%lld: ", _t);
        for(i = 0; i < ans.size(); i++) {
            cout<<ans[i];
        }
        cout<<endl;
        ans.clear();
    }


    return 0;
}

