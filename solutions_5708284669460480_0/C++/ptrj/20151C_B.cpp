//==============================================================================
// Round 1C 2015
// Problem B
//
//==============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using sol_type = double;

void read_data();
sol_type find_solution();

int K, L, S;
string word, keyboard;

int main() {

    int cases;
    int case_num =0;

    cin >> cases;

    while (cases--) {
        ++case_num;
        read_data();
        auto solution = find_solution();
        cout << "Case #" << case_num << ": ";
        cout << solution << endl;
    }
    return 0;
}

void read_data(){
    cin >> K >> L >> S;
    cin >> keyboard >> word;
}

int count(const string & s, const string & pattern) {
    int ret = 0;
    auto pos = s.find(pattern);
    while(pos != string::npos) {
        ++ret;
        pos = s.find(pattern, pos+1);
    }
    return ret;
}

sol_type find_solution(){
    vector<string> all, pre;
    all.reserve(pow(K,S));
    pre.reserve(pow(K,S));
    all.push_back("");
    for(int i=0; i<S; ++i) {
        pre.clear();
        for(const auto s : all) {
            for(int k = 0; k<K; ++k)
                pre.push_back(s + keyboard[k]);
        }
        swap(all, pre);
    }
    int summ = 0;
    int maxx = 0;
    for(const auto & s : all) {
        auto r = count(s, word);
        summ += r;
        maxx = max(maxx, r);
    }
//    clog << maxx << "," << summ << "," << all.size()<< endl;

    return maxx - summ*1.0/all.size();
}
