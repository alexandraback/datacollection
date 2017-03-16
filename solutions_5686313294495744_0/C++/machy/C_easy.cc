#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>


using namespace std;

typedef long long LL;

vector<int> words_id(vector<string>& words, int& cnt){
    map<string, int> s;
    vector<int> res(words.size());
    for(int i = 0; i < words.size(); ++i){
        if(s.count(words[i]) == 0){
            int id = s.size();
            s[words[i]] = id;
        }
        res[i] = s[words[i]];
        //cerr << words[i] << " id= "<< res[i] << endl;
    }
    cnt = s.size();
    return res;
}

bool possible(vector<int>& ids1, vector<int>& ids2, int pattern, int n, int m1, int m2){
    vector<int> cnt1(m1);
    vector<int> cnt2(m2);
    for(int i = 0; i < n; ++i){
        if(pattern & (1<<i)) continue;
        cnt1[ids1[i]]++;
        cnt2[ids2[i]]++;
    }
    for(int i = 0; i < m1; ++i){
        if(cnt1[i] == 0) return false;
    }
    for(int i = 0; i < m2; ++i){
        if(cnt2[i] == 0) return false;
    }
    return true;
}

int solve(vector<string>& words1, vector<string>& words2){
    int m1 = 0, m2 = 0;
    vector<int> ids1 = words_id(words1, m1);
    vector<int> ids2 = words_id(words2, m2);

    int ans = 0;
    int n = words1.size();
    for(int i = 0; i < (1<<n); ++i){
        if(possible(ids1, ids2, i, n, m1, m2)){
            int cnt = 0;
            for(int j = 0; j < n; ++j){
                if(i & (1<<j)) cnt++;
            }
            if(cnt > ans){
//                cerr << "update : " << i << " : " << cnt << endl;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t){
        int n;
        cin >> n;
        vector<string> words1(n);
        vector<string> words2(n);
        for(int i = 0; i < n; ++i){
            cin >> words1[i] >> words2[i];
        }
        cout << "Case #" << t << ": " << solve(words1, words2) << endl;
    }
    return 0;
}

