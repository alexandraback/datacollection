#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>


using namespace std;

typedef long long LL;

string fixed_digit(LL v, int n){
    string s(n, '0');
    for(int i = 0; i < n; ++i){
        s[n-1-i] = '0' + v % 10;
        v /= 10;
    }
    assert(v == 0);
    return s;
}

LL n_abs(LL n){
    if(n < 0) return -n;
    return n;
}

bool fit(int v,  string& s){
    int n = s.size();
    for(int i = 0; i < s.size(); ++i){
        int r = v % 10;
        v /= 10;
        if(s[n-1-i] == '?') continue;
        if('0'+r != s[n-1-i]) return false;
    }
    return true;
}

string solve(string& s1, string& s2){
    LL ans1 = 9999LL;
    LL ans2 = 0LL;
    int s_max = 1000;
    if(s1.size() == 1){
        s_max = 10;
    }else if(s2.size() == 2){
        s_max = 100;
    }
    for(int i = 0; i < s_max; ++i){
        if(!fit(i, s1)) continue;
        for(int j = 0; j < s_max; ++j){
            if(fit(j, s2)){
                LL diff = n_abs(j-i);
                LL a_diff = n_abs(ans1-ans2);
                if(diff < a_diff){
                    ans1 = i; ans2 = j;
                }else if(diff == a_diff){
                    if(i < ans1 || (i == ans1 && j < ans2)){
                        ans1 = i; ans2 = j;
                    }
                }
            }
        }
    }
    assert(ans2 != 9999);
    int n = s1.size();
    return fixed_digit(ans1, n) + " " + fixed_digit(ans2, n);
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        string s1, s2;
        cin >> s1 >> s2;
        cout << "Case #" << t << ": " << solve(s1, s2) << endl;
    }
    return 0;
}

