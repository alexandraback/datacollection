#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

const string richard = "RICHARD";
const string gabriel = "GABRIEL";

// Each domino shape can be represented as a grid with '*'s denoting squares
// and '.'s empty squares.
typedef vector<string> DominoShape;

// Grid itself can also be represented 
typedef vector<string> Grid;

// Select the smaller form.
DominoShape better_form(const DominoShape& form1, const DominoShape& form2)
{
    return min(form1, form2);
}

// Rotate the given shape by 90 degrees.
DominoShape rotateClockwise(const DominoShape& form)
{
    int r = (int)form.size(), c = (int)form[0].size();
    vector<string> ret(c, string(r, '.'));

    for (int i = 0;i < r; ++i)
        for (int j = 0;j < c; ++j)
            if (form[i][j] == '*') {
                ret[j][r - 1 - i] = '*';
            }

    return ret;
}

// Return all the rotations of the given domino shape.
vector<DominoShape> rotations(const DominoShape& form)
{
    vector<DominoShape> ret;
    DominoShape cur = form;
    for (int i = 0;i < 4; ++i) {
        ret.push_back(cur);
        cur = rotateClockwise(cur);
    }

    return ret;
}

vector<DominoShape> horizontal_reflections(const DominoShape& form)
{
    int r = (int)form.size(), c = (int)form[0].size();
    vector<string> flipped(r, string(c, '.'));

    for (int i = 0;i < r; ++i)
        for (int j = 0;j < c; ++j)
            if (form[i][j] == '*') {
                flipped[i][c-1-j] = '*';
            }
        

    vector<DominoShape> ret(2);
    ret[0] = form;
    ret[1] = flipped;
    return ret;
}

vector<DominoShape> vertical_reflections(const DominoShape& form)
{
    int r = (int)form.size(), c = (int)form[0].size();
    vector<string> flipped(r, string(c, '.'));

    for (int i = 0;i < r; ++i)
        for (int j = 0;j < c; ++j)
            if (form[i][j] == '*') {
                flipped[r-1-i][j] = '*';
            }
        

    vector<DominoShape> ret(2);
    ret[0] = form;
    ret[1] = flipped;
    return ret;
}

// Return horizontal and vertical reflections of the given form.
vector<DominoShape> reflections(const DominoShape& form)
{
    vector<DominoShape> ret;
    for (auto shape: horizontal_reflections(form))
        for (auto shape2: vertical_reflections(shape))
            ret.push_back(shape2);
}

// Return the canonical representation for a given domino shape.
DominoShape canonical_domino_form(const DominoShape& form)
{
    DominoShape ret = form;
    for (DominoShape rotation: rotations(form))
        for (DominoShape reflection: reflections(rotation))
            ret = better_form(ret, reflection);
    
    return ret;
}

// I wish there were closures in C++.
DominoShape getShape(vector<int>& dRow, vector<int>& dCol)
{
    int minRow = *min_element(dRow.begin(), dRow.end());
    int maxRow = *max_element(dRow.begin(), dRow.end());

    int minCol = *min_element(dCol.begin(), dCol.end());
    int maxCol = *max_element(dCol.begin(), dCol.end());

    int r = maxRow - minRow + 1, c = maxCol - minCol + 1;
    vector<string> ret(r, string(c, '.'));
    for (int i = 0;i < (int)dRow.size(); ++i)
        ret[dRow[i] - minRow][dCol[i] - minCol] = '*';

    return ret;
}

// Generate all the domino shapes of the given size.
void gen_all_shapes(int X, vector<int>& dRow, vector<int>& dCol,
                                   set<DominoShape>& shapes, int i = 0)
{
    if (i == X) {
        //shapes.push_back();
    }
}

// All 20x20 grid tilings can be enumerated.
void try_and_fill_grid_recursive(int X, int R, int C, 
                                 Grid& grid, set<DominoShape>& shapes,
                                 DominoShape** usedShapes, int numUsedShapes)
{
    throw;
}

// Check if Richard can win the game by choosing a domino shape.
// X > 6 => Rich can choose holed polyominos.
bool is_winning_game(int X, int R, int C)
{
    if (X > R && X > C)
        return true;

    if (X > 6 || (R * C) % X != 0)
        return true;

    if (X <= 2)
        return false;

    if (X == 3) {
        return R < 2 || C < 2;
    } else if (X == 4) {
        return R < 3 || C < 3;
    }

    // To be implemented.
    vector<int> dRow, dCol;
    set<DominoShape> allShapes;
    gen_all_shapes(X, dRow, dCol, allShapes, 0);

    set<DominoShape> fittingShapes;


    DominoShape* usedShapes[125];
    //try_and_fill_grid_recursive(X, R, C, dominoShapes, fittingShapes,
     //                           usedShapes, 0);
    //return fittingShapes.size() < dominoShapes.size();
    return true;
}

int main(int argc, char **argv)
{
    int num_cases;
    cin >> num_cases;

    for (int cas = 1;cas <= num_cases; ++cas) {
        int X, R, C;
        cin >> X >> R >> C;
        cout << "Case #" << cas << ": ";
        cout << (is_winning_game(X, R, C) ? richard : gabriel) << endl;
    }

    return 0;
}
