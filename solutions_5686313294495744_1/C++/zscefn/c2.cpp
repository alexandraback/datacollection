#include <set>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#define F first
#include <cstring>
#define S second
using namespace std; 
bool used[3333];
    unordered_map<int, int> v[3000];

int f(int x) {
    if(x == 2222) return 1;
    used[x] = 1;
    for(auto y: v[x]) {
        if(!used[y.F] && y.S == 1) {
            if(f(y.F)) {
                v[x][y.F] = 0;
                v[y.F][x] = 1;
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int tt;
    cin>>tt;
    for(int xx = 1; xx <= tt; ++xx) {
        cout<<"Case #"<<xx<<": ";
        int n;
        cin>>n;
        vector<pair<string, string> > t(n);
        unordered_map<string, int> s1,s2;
        for(int i = 0; i < 3000; ++i) v[i].clear();
        for(int i =0; i < n; ++i) {
            cin>>t[i].F>>t[i].S;
            if(s1.count(t[i].F) == 0) {
                int q = s1.size();
                s1[t[i].F] = q;
            }
            if(s2.count(t[i].S) == 0) {
                int q = s2.size();
                s2[t[i].S] = q;
            }
            v[1+s1[t[i].F]][1111+s2[t[i].S]] = 1;
            v[1111+s2[t[i].S]][1+s1[t[i].F]] = 0;
        }
        for(auto x: s1) {
            v[0][1+x.S] = 1;
            v[1+x.S][0] = 0;
        }
        for(auto x: s2) {
            v[x.S+1111][2222] = 1;
            v[2222][x.S+1111] = 0;
        }
        for(int i = 0; i < 3000; ++i) {
            for(auto x: v[i]) {
                //cout<<i<<' '<<x.F<<' '<<x.S<<'\n';
            }
        }
        int flow = 0;
        while(1) {
            memset(used, 0, sizeof used);
            int q = f(0);
            if(q == 0) break;
            ++flow;
        }
        //cout<<flow<<' ';
        int w = s1.size()+s2.size()-flow;
        cout<<n-w<<'\n';
    }
}
