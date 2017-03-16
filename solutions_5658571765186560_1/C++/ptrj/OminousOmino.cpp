//==============================================================================
// Qualification Round 2015
// Problem D. Ominous Omino
//
//==============================================================================

#include <iostream>
#include <string>
#include <vector>

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
    if(R > C)
        swap(R,C);

    if((R*C)%X != 0)   // incongruent dimensions
        return false;

    if(X <= 2)
        return true;
    if(X == 3)
        return R > 1;
    if(X == 4)
        return R > 2;

/*
    If the board is large enough (i.e. Richard's X-omino doesn't disconnect it),
    then filling is possible. This is the case for R > 3 (C >= R).

    For R = 3, some X-ominos disconnect (split) the board.
    If the split can be chosen so that X divides the number of cells in each part,
    than filling is also possible.
*/

    if(X == 5)
        return R > 3 || (R == 3 && C > 5);
    if(X == 6)
        return C > 5 && R > 3;
    if(X > 6)           // X-ominous with holes
        return false;

    return false;
}
