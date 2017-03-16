#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <climits>
#include <sstream>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR_EACH(it,v) for(__typeof((v).begin()) it = (v).begin(); it!=(v).end(); ++it)
#define show(x) cout << #x << ": " << x << endl;

template<typename T>
ostream& operator<<(ostream &o, const vector<T>&v){
    FOR_EACH(x, v){
        if(x==v.begin()) o << "[";
        else o << ", ";
        o << *x;
    }
    o << "]";
    return o;
}

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int>VI;
typedef vector<vector<int> >VII;

void solve(){
    LL a,n; cin >> a >> n;
    VI motes;
    REP(i,n){
        LL x; cin >> x;
        motes.push_back(x);
    }
    sort(motes.begin(), motes.end());
    LL res = motes.size();
    LL cur = 0;
    if(a!=1){
        for(LL i=0; i<n; i++){
            while(a <= motes[i]) {
                a = a*2-1;
                cur++;
            }
            res = min(res, cur + n-i-1);
            a += motes[i];
        }
    }
    cout << res << endl;
}

int main(int argc,char *argv[]) {
    int T; cin >> T;
    for(int t=1; t<=T; t++){
        printf("Case #%d: ", t);
        solve();
    }
}
