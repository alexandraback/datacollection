#include <bits/stdc++.h>

using namespace std;
int t,n;
vector<pair<string,string>> vec;

bool check(int d){
    int c;
    for(int i=0;i<n;i++){
        c = ((1<<i) & d);
        if (c > 1) c = 1;
        if (c==1){
            bool first = false;
            bool second = false;
            for(int j = 0;j<n;j++){
                int e = ((1<<j) & d);
                if (e == 0){
                    if (vec[j].first == vec[i].first) first = true;
                    if (vec[j].second == vec[i].second) second = true;
                }
            }
            if (!(first && second)) return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> t;
    for(int cn=1;cn<=t;cn++){
        cin >> n;
        vec.resize(n);
        for(auto&x : vec) cin >> x.first >> x.second;
        int ans = 0;
        for(int i=0;i<((1<<(n)));i++){
            if (check(i)){
                ans = max(ans,__builtin_popcount(i));
            }
        }
        cout << "Case #" << cn << ": " << ans << '\n';
    }
    return 0;
}

