#include <set>
#include <vector>
#include <iostream>
#define F first
#define S second
using namespace std; 
int main() {
    int tt;
    cin>>tt;
    for(int xx = 1; xx <= tt; ++xx) {
        cout<<"Case #"<<xx<<": ";
        int n;
        cin>>n;
        vector<pair<string, string> > t(n);
        for(int i =0; i < n; ++i) {
            cin>>t[i].F>>t[i].S;
        }
        int ans = 0;
        for(int i = 0; i < (1<<n); ++i) {
            int x = i;

            set<string> s1, s2;
            for(int j = 0; j < n; ++j) {
                if(i & (1<<j)) {
                    s1.insert(t[j].F);
                    s2.insert(t[j].S);
                }
            }
            for(int j = 0; j < n; ++j) {
                if((i & (1<<j)) == 0) {
                    if(s1.count(t[j].F) == 0 || s2.count(t[j].S) == 0) {
                        goto ohi;
                    }
                }
            }
            ans = max(ans,n-__builtin_popcount(i));
            ohi:;
        }
        cout<<ans<<'\n';

    }
}
