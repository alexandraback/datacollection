//==============================================================================
// Round 1C 2015
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

void read_data();
sol_type find_solution();

int sim();

int R, C, W;

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
    cin >> R >> C >> W;
}

sol_type find_solution(){
    return R * (C/W-1) + R - 1 + min(C-W*(C/W-1), W+1);
}
