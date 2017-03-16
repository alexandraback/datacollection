#include <cstdlib>
#include <bitset>
#include <functional>
#include <utility>
#include <tuple>
#include <limits>
#include <cstdint>
#include <cctype>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <random>
#include <numeric>
#include <iostream>
#include <sstream>

using namespace std;

vector<tuple<char, string, int>> m = {
        {'Z', "ZERO", 0},
        {'W', "TWO", 2},
        {'X', "SIX", 6},
        {'G', "EIGHT", 8},
        {'S', "SEVEN", 7},
        {'V', "FIVE", 5},
        {'F', "FOUR", 4},
        {'R', "THREE", 3},
        {'O', "ONE", 1},
        {'N', "NINE", 9}
};

void comp(int tc){
    string s;
    cin >> s;

    unordered_map<char, int> cnt;
    for(char c : s){
        ++cnt[c];
    }

    vector<int> ans;

    for(auto p : m){
        while(true) {
            if(cnt[get<0>(p)] == 0)
                break;

            for(char c : get<1>(p)){
                --cnt[c];
            }
            ans.push_back(get<2>(p));
        }
    }

    sort(ans.begin(), ans.end());
    cout << "Case #" << tc << ": ";
    for(int val : ans){
        cout << val;
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}