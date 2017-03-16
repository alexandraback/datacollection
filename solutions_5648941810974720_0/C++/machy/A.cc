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

void count_down(vector<int>& counts, string s, int cnt){
    //cerr << "debug : " << s << " : " << cnt << endl;
    for(int i = 0; i < s.size(); ++i){
        counts[s[i]] -= cnt;
        assert(counts[s[i]] >= 0);
    }
}

string solve(string& s){
    vector<int> counts(256);
    for(int i = 0; i < s.size(); ++i){
        counts[s[i]]++;
    }
    vector<int> digit_cnt(10);
    // ZERO
    digit_cnt[0] = counts['Z'];
    count_down(counts, "ZERO", digit_cnt[0]);
    // TWO
    digit_cnt[2] = counts['W'];
    count_down(counts, "TWO", digit_cnt[2]);
    // FOUR
    digit_cnt[4] = counts['U'];
    count_down(counts, "FOUR", digit_cnt[4]);
    // SIX
    digit_cnt[6] = counts['X'];
    count_down(counts, "SIX", digit_cnt[6]);
    // EIGHT
    digit_cnt[8] = counts['G'];
    count_down(counts, "EIGHT", digit_cnt[8]);
    // SEVEN
    digit_cnt[7] = counts['S'];
    count_down(counts, "SEVEN", digit_cnt[7]);
    // FIVE
    digit_cnt[5] = counts['V'];
    count_down(counts, "FIVE", digit_cnt[5]);
    // THREE
    digit_cnt[3] = counts['H'];
    count_down(counts, "THREE", digit_cnt[3]);
    // ONE
    digit_cnt[1] = counts['O'];
    count_down(counts, "ONE", digit_cnt[1]);
    // NINE
    digit_cnt[9] = counts['I'];
    count_down(counts, "NINE", digit_cnt[9]);

    string res = "";
    for(int d = 0; d <= 9; ++d){
        res += string(digit_cnt[d], '0' + d);
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        string s;
        cin >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }
    return 0;
}

