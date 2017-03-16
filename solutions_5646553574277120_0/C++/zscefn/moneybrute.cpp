#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int dp[40];
int test(vector<int> v, int goal) {
    sort(v.begin(), v.end());
    /*
    cout<<"TEST "<<goal<<'\n';
    for(int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<' ';
    }
    cout<<'\n';
    */
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= goal; ++i) {
        for(int j = v.size()-1; j >= 0; --j) {
            if(i-v[j] == 0 || (i-v[j] >= 0 && dp[i-v[j]] > j)) {
                dp[i] = j;
                goto ohi;
            }
        }
    //    cout<<"LOL EI\n";
        return 0;
        ohi:;
    }
    //cout<<"JEE\n";
    return 1;
}
int f(vector<int> v, int goal, int lis, int lisma) {
    if(test(v, goal)) return v.size();
    if(lis >= 5) return 1e9;
    int lol[31] = {0};
    for(int i = 0; i < v.size(); ++i) {
        lol[v[i]] = 1;
    }
    vector<int> v2 = v;
    int mi = 1e9;
    for(int i = lisma+1; i <= goal; ++i) {
        if(lol[i] == 0) {
            v2.push_back(i);
            mi = min(mi, f(v2, goal, lis+1, i));
            v2.pop_back();
        }
    }
    return mi;
}
int main() {
    int tt;
    cin>>tt;
    for(int xx = 1; xx <= tt; ++xx) {
        int c,d,v;
        cin>>c>>d>>v;
        vector<int> coins;
        for(int i = 0; i < d; ++i) {
            int q;
            cin>>q;
            if(q <= v) coins.push_back(q);
        }
        cout<<"Case #"<<xx<<": "<<f(coins, v, 0, 0)-coins.size()<<endl;
    }
}
