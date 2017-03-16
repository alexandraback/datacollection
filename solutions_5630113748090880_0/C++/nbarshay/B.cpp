#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

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


int main() {
    int np; cin>>np;
    rep(i, np){
        cout << "Case #"<<(i+1)<<":";

        int n; cin>>n;
        map<int, int> m;
        rep(i,2*n-1) {
            rep(k,n) {
                int v; cin>>v;
                m[v]++;
            }
        }

        vector<int> bla;
        for(auto& x : m) {
            if(x.second % 2) {
                bla.push_back(x.first);
            }
        }
        sort(bla.begin(), bla.end());

        assert(bla.size() == n);

        for(int x : bla) {
            cout << " " << x;
        }
        
        cout << endl;
    }
}
