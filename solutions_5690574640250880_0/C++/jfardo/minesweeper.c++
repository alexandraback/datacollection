#include <iostream>
#include <fstream>
#include <vector>

typedef std::vector<std::vector<bool> > Mines;

void PrintMines(const Mines& mines,
                unsigned     clickRow,
                unsigned     clickCol)
{
    for (unsigned r = 0; r < mines.size(); ++r) {
        for (unsigned c = 0; c < mines[r].size(); ++c) {
            if (mines[r][c]) {
                std::cout << '*';
            } else if (r == clickRow && c == clickCol) {
                std::cout << 'c';
            } else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }
}

void Fill(Mines*                 mines_p,
          std::vector<unsigned>* numMinesInRow_p,
          std::vector<unsigned>* numMinesInCol_p,
          unsigned*              numMines_p,
          unsigned               rowStart,
          unsigned               rowEnd,
          unsigned               colStart,
          unsigned               colEnd)
{
    if (*numMines_p == 0) {
        return;
    }
    for (unsigned r = rowStart; r <= rowEnd; ++r) {
        for (unsigned c = colStart; c <= colEnd; ++c) {
            // This prob isn't necessary, but just to be safe...
            if (!(*mines_p)[r][c]) {
                (*mines_p)[r][c] = true;
                ++(*numMinesInRow_p)[r];
                ++(*numMinesInCol_p)[c];
                if (--*numMines_p == 0) {
                    return;
                }
            }
        }
    }
}

// Rows    can't have r-1 mines
// Columns can't have c-1 mines
//
// Can't have a row or column with only 1 empty space unless it's
// the only open space.
//      
void Minesweeper(unsigned numRows, unsigned numCols, unsigned numMines)
{
    Mines mines(numRows, std::vector<bool>(numCols, false));

    std::vector<unsigned> num_mines_in_row(numRows, 0);
    std::vector<unsigned> num_mines_in_col(numCols, 0);

    unsigned mines_to_place = numMines;
    unsigned r = 0;
    unsigned c = 0;

    while (mines_to_place) {
        unsigned empty_in_row = numCols - num_mines_in_row[r];
        unsigned empty_in_col = numRows - num_mines_in_col[c];

        // Place the mines in the row or column that has the most space.
        if (mines_to_place < empty_in_col &&
            mines_to_place < empty_in_row)
        {
            // Fill the last row and column
            bool first_in_col = false;
            if (empty_in_row > 2) {
                // Fill all but the last 2 in the row.
                Fill(&mines,
                     &num_mines_in_row,
                     &num_mines_in_col,
                     &mines_to_place,
                     r, r,
                     c, c + std::min(empty_in_row - 2, mines_to_place) - 1);
                empty_in_col = numRows - num_mines_in_col[c];
                first_in_col = true;
            }

            if (empty_in_col > 2) {
                // Fill all but the last 2 in the column.
                unsigned r2 = r;
                // Skip the first one set above.
                if (first_in_col) {
                    r2 = r+1; 
                }
                Fill(&mines,
                     &num_mines_in_row,
                     &num_mines_in_col,
                     &mines_to_place,
                     r2, r2 + std::min(empty_in_col - 2, mines_to_place) -1,
                     c, c);
            }

            // Fill in any leftover mines in the row
            Fill(&mines,
                 &num_mines_in_row,
                 &num_mines_in_col,
                 &mines_to_place,
                 r, r,
                 c, numCols-1);
            // Fill in any leftover mines in the column
            Fill(&mines,
                 &num_mines_in_row,
                 &num_mines_in_col,
                 &mines_to_place,
                 r, numRows-1,
                 c, c);
                
        } else if (empty_in_row > empty_in_col) {
            // Fill a column of mines
            Fill(&mines, 
                 &num_mines_in_row,
                 &num_mines_in_col,
                 &mines_to_place,
                 r, numRows-1,
                 c, c);
            ++c;
        } else {
            // Fill a row of mines
            Fill(&mines, 
                 &num_mines_in_row,
                 &num_mines_in_col,
                 &mines_to_place,
                 r, r,
                 c, numCols-1);
            ++r;
        }
    }

    if (numMines < numRows*numCols - 1 && numRows != 1 && numCols != 1) {
        // Check for rows and colums with only 1 empty space in them
        for (unsigned i = 0; i < num_mines_in_row.size(); ++i) {
            if (numCols - num_mines_in_row[i] == 1) {
                std::cout << "Impossible\n";
                return;
            }
        }
        for (unsigned i = 0; i < num_mines_in_col.size(); ++i) {
            if (numRows - num_mines_in_col[i] == 1) {
                std::cout << "Impossible\n";
                return;
            }
        }
    }

    PrintMines(mines, numRows-1, numCols-1);
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        std::cout << "Missing file containing input\n";
        return -1;
    }

    std::ifstream istr(argv[1]);

    // Read in the number of test cases.
    unsigned T;
    istr >> T;

    for (unsigned i = 1; i <= T; ++ i) {
        unsigned r= 0;
        unsigned c= 0;
        unsigned m= 0;
        istr >> r;
        istr >> c;
        istr >> m;
        std::cout << "Case #" << i << ":\n";
        Minesweeper(r, c, m);
    }

    return 0;
}
