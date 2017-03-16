#include <iostream>
#include <fstream>
using namespace std;

const string INPUT_FILE = "C-large.in";
const string OUTPUT_FILE = "output_large.txt";

void printOutputGrid(string grid[], const int rows, ofstream & output) {
    for (int i = 0; i < rows; i++) {
        output << grid[i] << endl;
    }
}

void fail(ofstream & output) {
    output << "Impossible" << endl;
}

void findGrid(const int rows, const int columns, const int mines, ofstream & output) {
    string grid[rows];
    int emptySpots = (rows * columns) - mines;
    for (int i = 0; i < rows; i++) {
        grid[i].append(columns, '*');
    }
    //OBSERVATIONS
    //We are looking for a single empty area, where the area that does not include its
    //border is continuous.
    //It is always possible to win if:
    // - all but 1 spot is a mine
    if (emptySpots == 1) {

    }
    // - rows or columns = 1
    else if (rows == 1) {
        string emptyness = "";
        emptyness.append(emptySpots, '.');
        grid[0].replace(0, emptySpots, emptyness);

    }
    else if (columns == 1) {
        for (int i=0; i < emptySpots; i++) {
            grid[i][0] = '.';
        }
    }
    //Else if columns or rows = 2, fail on odd number of empty spots.
    //You can also never place 2, 3, 5 or 7 empty spots in any grid that is at least 2x2.
    else if ((emptySpots % 2 == 1 && (columns == 2 || rows == 2))
             || (emptySpots < 4 || emptySpots == 5 || emptySpots == 7)) {
        fail(output);
        return;
    }
    //The rest, we can solve by placing empty space greedily.
    else {
        //First row should be just as wide as the second one, with a remainder of either 0 or >= 2.
        int firstRowWidth = emptySpots / 2;
        if (firstRowWidth > columns)
            firstRowWidth = columns;
        int remainder = emptySpots - (firstRowWidth * 2);
        if (remainder == 1) {
            firstRowWidth--;
            remainder = 3;
        }
        string rowString(firstRowWidth, '.');
        grid[0].replace(0, firstRowWidth, rowString);
        grid[1].replace(0, firstRowWidth, rowString);
        //From the third row onwards, either put down everything possible, or everything -1.
        int row = 2;
        while (remainder > 0) {
            int rowSize;
            if (remainder < firstRowWidth) {
                rowSize = remainder;
            }
            else if (remainder - firstRowWidth == 1) {
                rowSize = firstRowWidth - 1;
            }
            else {
                rowSize = firstRowWidth;
            }
            string replacementString(rowSize, '.');
            grid[row].replace(0, rowSize, replacementString);
            remainder -= rowSize;
            row++;
        }
    }

    grid[0][0] = 'c';
    printOutputGrid(grid, rows, output);
}

void solveCase(ifstream & input, ofstream & output) {
    int rows, columns, mines;
    input >> rows >> columns >> mines;
    cerr << "Rows : " << rows << " Columns: " << columns << " Mines: " << mines << endl;
    findGrid(rows, columns, mines, output);
}

void solveAllCases(ifstream & input, ofstream & output) {
    int cases;
    input >> cases;
    cout << "Testcases to run: " << cases << endl;
    for (int i = 1; i <= cases; i++) {
        output << "Case #" << i << ": " << endl;
        cerr << "Case #" << i << ": ";
        solveCase(input, output);
    }
}

int main()
{
    ifstream input(INPUT_FILE.c_str(), ios::in);
    ofstream output(OUTPUT_FILE.c_str(), ios::out);
    solveAllCases(input, output);
    input.close();
    output.close();
    return 0;
}
