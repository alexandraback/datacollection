#include<bits/stdc++.h>
#define rep(i,k,n) for(int i= (int) k;i< (int) n;i++)
#define mp make_pair
#define pb push_back
#define ft first
#define sd second
typedef long long ll;
const long long inf = 9223372036854775807ll;
const int iinf = 2147483647;
const int limit = 1048576;
using namespace std;

int presuf(const string& s){
    vector<int> border(s.size() + 3, 0); border[0] = -1;
    rep(i, 2, s.size() + 1){
        int k = border[i - 1];
        while(s[k] != s[i - 1] && k != -1)
            k = border[k];
        border[i] = k + 1;
    }
    return border[s.size()];
}

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w",stdout);
    int t; cin >> t;
    rep(c, 1, t + 1){
        int k, l, s; cin >> k >> l >> s;
        string klaw, docel; cin >> klaw >> docel;

        vector<double> pstw(200);
        rep(i, 0, klaw.size())
            pstw[klaw[i]]++;

        rep(i, 0, pstw.size())
            pstw[i] /= (double) klaw.size();

        bool poss = true;
        double p = 1.0;
        rep(i, 0, docel.size()){
            if(pstw[docel[i]] < 1e-9)
                poss = false;
            p *= pstw[docel[i]];
        }

        double e = max(0, s + 1 - l) * p;
        //cout << setprecision(9) << e << "\n";

        cout << setprecision(9);
        if(poss)
            cout << "Case #" << c << ": " << (s - l) / (l - presuf(docel)) + 1.0 - e << "\n";
        else
            cout << "Case #" << c << ": 0.0"  << "\n";

    }
    return 0;
}

