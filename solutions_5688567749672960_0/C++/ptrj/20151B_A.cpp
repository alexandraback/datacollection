//==============================================================================
// Round 1B 2015
// Problem A
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
using ll = long long;

ll flip(ll);
vector<int> dfs;

ll N;
void read_data();
sol_type find_solution();


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
    cin >> N;
    dfs.resize(N+1);
}

sol_type find_solution(){
    dfs[0] = 0;
    dfs[1] = 1;
    for(auto j=2; j<=N; ++j) {
        auto m = flip(j);
        if(m<j)
            dfs[j] = min(dfs[j-1], dfs[m])+1;
        else
            dfs[j] = dfs[j-1] + 1;
    }

//    for(auto c : dfs)
//        clog << c << ",";
//    clog << endl;

    return dfs[N];
}

ll flip(ll n) {
    if(n%10 == 0)
        return n;
    string s = to_string(n);
//    clog << s << "," << s[0] << ";";
    reverse(s.begin(), s.end());
//    clog << s << ";" << s[0] << endl;
    return stoll(s);
}

