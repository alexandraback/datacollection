//==============================================================================
// Qualification Round 2015
// Problem D. Ominous Omino
//     (small version)
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

using sol_type = bool;

sol_type find_solution();
int X, R, C;

int main() {

    int cases;
    int case_num =0;

    cin >> cases;

    while (cases--) {
        ++case_num;
        auto solution = find_solution();
        cout << "Case #" << case_num << ": ";
        cout << (solution ? "GABRIEL" : "RICHARD") << endl;
    }
    return 0;
}

sol_type find_solution(){
    cin >> X >> R >> C;
    if(R>C)
        swap(R,C);

    if(X > 6 || (R*C)%X != 0)
        return false;
    if(X <= 2)
        return true;
    if(X == 3)
        return R > 1;
    if(X == 4)
        return R > 2;

    return false;
}
