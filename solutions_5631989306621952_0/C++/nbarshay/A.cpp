#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define For(i,a,b) for(int i = a; i < b; i++)
#define rep(i,x) For(i,0,x)
#define foreach(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define TWO(x) (1LL<<(x))

using namespace std;

string s;
vector<char> res;

void rec(int a, int b) {
    if(a >= b) {
        return;
    }
    int best_idx = -1;
    For(k, a, b) {
        if(best_idx == -1 || s[k] >= s[best_idx]) {
            best_idx = k;
        }
    }
    res.push_back(s[best_idx]);
    rec(a, best_idx);
    For(i, best_idx+1, b) {
        res.push_back(s[i]);
    }
}

int main() {
    int np; cin>>np;
    rep(i, np){
        cout << "Case #"<<(i+1)<<": ";

        cin>>s;
        int n = s.size();
        res.clear();

        rec(0, n);

        rep(i, n) {
            cout << res[i];
        }
        
        cout << endl;
    }
}
