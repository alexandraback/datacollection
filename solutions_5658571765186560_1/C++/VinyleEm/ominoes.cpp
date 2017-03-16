#include <algorithm>
#include <utility>
#include <iostream>
#include <set>
#include <stack>
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
    return ret;
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

    return canonical_domino_form(ret);
}

// Generate all the domino shapes of the given size.
void gen_all_shapes(int X, vector<int>& dRow, vector<int>& dCol,
                                   set<DominoShape>& shapes, int i = 0)
{
    if (i == X) {
        shapes.insert(getShape(dRow, dCol));
        return;
    }

    set<pair<int, int> > seen;
    set<pair<int, int> > neighbors;
    for (int j = 0;j < (int)dRow.size(); j++) {
        seen.insert(make_pair(dRow[j], dCol[j]));

        for (int dx = -1;dx <= 1;dx++)
            for (int dy = -1;dy <= 1; dy++)
                if (abs(dx + dy) == 1)
                    neighbors.insert(make_pair(dRow[j] + dy, dCol[j] + dx));
    }

    if (i == 0) {
        neighbors.insert(make_pair(0, 0));
    }

    for (auto loc : neighbors) {
        if (seen.count(loc))
            continue;
        dRow.push_back(loc.first);
        dCol.push_back(loc.second);
        gen_all_shapes(X, dRow, dCol, shapes, i + 1);
        dRow.pop_back();
        dCol.pop_back();
    }

    return;
}

void fill_grid_recursive(int y, int x, int R, int C,
                         set<DominoShape>& allShapes, vector<string>& grid,
                         vector<DominoShape>& shapeStack, set<DominoShape>& fitting)
{
    if (y == R) {
        for (auto shape: shapeStack)
            fitting.insert(shape);
        return;
    }

    if (x == C) {
        fill_grid_recursive(y + 1, 0, R, C, allShapes, grid, shapeStack,
                            fitting);
        return;
    }

    if (grid[y][x] == '*') {
        fill_grid_recursive(y, x + 1, R, C, allShapes, grid, shapeStack,
                            fitting);
        return;
    }

    for (auto shape : allShapes) {
        int W = (int)shape[0].size(), H = (int)shape.size();

        for (int lft = x - W + 1;lft <= x; lft++)
            for (int upp = y - H + 1;upp <= y; upp++) {
                if (lft < 0 || lft + W > C || upp < 0 || upp + H > R)
                    continue;
                if (shape[y - upp][x - lft] != '*')
                    continue;

                for (int yy = upp;yy < upp + H; yy++)
                    for (int xx = lft ;xx < lft + W; xx++)
                        if (shape[yy - upp][xx - lft] == '*' 
                                and grid[yy][xx] == '*') {
                            goto done;
                        } else if (shape[yy - upp][xx - lft] == '*')
                            grid[yy][xx] = '*';

                shapeStack.push_back(shape);
                fill_grid_recursive(y, x + 1, R, C, allShapes, grid, shapeStack,
                                    fitting);
                shapeStack.pop_back();
                for (int yy = upp;yy < upp + H; yy++)
                    for (int xx = lft;xx < lft + W; xx++)
                        if (shape[yy - upp][xx - lft] == '*')
                            grid[yy][xx] = '.';

done:;
            }
    }
    return;
}

bool is_winning_game(int X, int R, int C)
{
    if (X > 3 || X > max(R, C) || R * C % X != 0)
        return true;

    set<DominoShape> allCanonicalShapes;
    vector<int> dRow, dCol;
    gen_all_shapes(X, dRow, dCol, allCanonicalShapes, 0);

    set<DominoShape> allShapes;
    for (auto shape: allCanonicalShapes) {
        for (auto rot : rotations(shape))
            for (auto refl : reflections(rot))
                allShapes.insert(refl);
    }

    vector<string> searchGrid(R, string(C, '.'));
    set<DominoShape> fittingShapes;
    vector<DominoShape> shapeStack;
    fill_grid_recursive(0, 0, R, C,
                        allShapes, searchGrid, shapeStack, fittingShapes);
    return fittingShapes.size() < allCanonicalShapes.size();
}

int main(int argc, char **argv)
{
    int num_cases;
    cin >> num_cases;

    for (int cas = 1;cas <= num_cases; ++cas) {
        int X, R, C;
        cin >> X >> R >> C;
        cout << "Case #" << cas << ": ";
        if (is_winning_game(X, R, C))
            cout << richard << endl;
        else cout << gabriel << endl;
    }

    return 0;
}
