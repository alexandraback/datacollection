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

LL abs_ll(LL n1, LL n2){
    if(n1 < n2) return n2 - n1;
    return n1 - n2;
}

void search(string& s1, string& s2, LL cur1, LL cur2, LL& ans1, LL& ans2, int pos){
    if(pos == s1.size()){
        LL diff = abs_ll(cur1, cur2);
        LL a_diff = abs_ll(ans1, ans2);
        if(diff < a_diff){
            ans1 = cur1; ans2 = cur2;
        }else if(diff == a_diff){
            if(cur1 < ans1 || (cur1 == ans1 && cur2 < ans2)){
                ans1 = cur1; ans2 = cur2;
            }
        }
        return;
    }
        
    char c1 = s1[pos];
    char c2 = s2[pos];
    int n1 = c1 - '0';
    int n2 = c2 - '0';
    if(c1 == '?' && c2 == '?'){
        if(cur1 == cur2){
            search(s1, s2, cur1*10, cur2*10, ans1, ans2, pos+1);
            search(s1, s2, cur1*10+1, cur2*10, ans1, ans2, pos+1);
            search(s1, s2, cur1*10, cur2*10+1, ans1, ans2, pos+1);
        }else if(cur1 > cur2){
            search(s1, s2, cur1*10, cur2*10+9, ans1, ans2, pos+1);
        }else{
            search(s1, s2, cur1*10+9, cur2*10, ans1, ans2, pos+1);
        }
    }else if(c1 == '?'){
        if(cur1 == cur2){
            search(s1, s2, cur1*10+n2, cur2*10+n2, ans1, ans2, pos+1);
            if(n2 < 9) search(s1, s2, cur1*10+n2+1, cur2*10+n2, ans1, ans2, pos+1);
            if(n2 > 0) search(s1, s2, cur1*10+n2-1, cur2*10+n2, ans1, ans2, pos+1);
        }else if(cur1 > cur2){
            search(s1, s2, cur1*10, cur2*10+n2, ans1, ans2, pos+1);
        }else{
            search(s1, s2, cur1*10+9, cur2*10+n2, ans1, ans2, pos+1);
        }
    }else if(c2 == '?'){
        if(cur1 == cur2){
            search(s1, s2, cur1*10+n1, cur2*10+n1, ans1, ans2, pos+1);
            if(n1 < 9) search(s1, s2, cur1*10+n1, cur2*10+n1+1, ans1, ans2, pos+1);
            if(n1 > 0) search(s1, s2, cur1*10+n1, cur2*10+n1-1, ans1, ans2, pos+1);
        }else if(cur1 > cur2){
            search(s1, s2, cur1*10+n1, cur2*10+9, ans1, ans2, pos+1);
        }else{
            search(s1, s2, cur1*10+n1, cur2*10, ans1, ans2, pos+1);
        }
    }else{
        search(s1, s2, cur1*10+n1, cur2*10+n2, ans1, ans2, pos+1);
    }
}

string fixed_digit(LL v, int n){
    string s(n, '0');
    for(int i = 0; i < n; ++i){
        s[n-1-i] = '0' + v % 10;
        v /= 10;
    }
    return s;
}

string solve(string& s1, string& s2){
    assert(s1.size() == s2.size());
    LL ans1 = 999999999999999999LL, ans2 = 0;
    LL cur1 = 0, cur2 = 0;
    search(s1, s2, cur1, cur2, ans1, ans2, 0);
    string res;
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

