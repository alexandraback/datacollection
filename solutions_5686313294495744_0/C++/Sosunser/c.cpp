#include <bits/stdc++.h>
using namespace std;

int t,n,sol;
vector<pair<string,string>> v;

int solve(){
    int res = 0;
    set<string> a,b;
    for(auto i : v){
        if(a.count(i.first) && !b.count(i.first) &&
            b.count(i.second) && !a.count(i.second)){
            res++;
        }
        a.insert(i.first);
        b.insert(i.second);
    }
    return res;
}

int main(){
    freopen("C-small-attempt3.in","r",stdin);
    freopen("C-small-attempt3.out","w",stdout);
    cin >> t;
    srand(time(0));
    for(int k = 1; k <= t; k++){
        cin >> n;
        string s1,s2;
        sol = 0;
        v.clear();
        for(int i = 0; i < n; i++){
            cin >> s1 >> s2;
            v.push_back({s1,s2});
        }
        sort(v.begin(),v.end());
        sol = max(sol,solve());
        cout << "Case #" << k << ": " << sol << endl;
    }
}