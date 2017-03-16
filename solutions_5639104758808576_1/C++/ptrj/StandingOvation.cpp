//==============================================================================
// Qualification Round 2015
// Problem A. Standing Ovation
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

using sol_type = int;

void read_data();
sol_type find_solution();

vector<int> shy;

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
    int smax =0;
    cin >> smax;
    shy.resize(smax+1);
    string s;
    cin >> s;
    transform(s.begin(), s.end(), shy.begin(), [](char c){return c-'0';});
    partial_sum(shy.begin(), shy.end(), shy.begin());
}

sol_type find_solution(){

//    for(const auto x: shy)
//        clog << x << ",";
//    clog << endl;

    int ret = 0;
    for(int i = 1; i<shy.size(); ++i)
        ret = max(ret, i-shy[i-1]);
    return ret;
}



