#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

vector< vector<char> > field;

template<class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
	cerr << "Case #" << caseNumber << endl;
    cout << "Case #" << caseNumber << ":" << endl;
    if (ans) {
        for (size_t i = 0; i < field.size(); i++) {
            for (size_t j = 0; j < field[i].size(); j++) {
                cout << field[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << "Impossible" << endl;
    }
}

vector< vector<char> > Transpose(const vector< vector<char> >& table) {
    vector< vector<char> > res(table[0].size(), vector<char>(table.size()));
    for (size_t i = 0; i < table.size(); i++) {
        for (size_t j = 0; j < table[i].size(); j++) {
            res[j][i] = table[i][j];
        }
    }
    return res;
}

template <class AnswerType>
AnswerType SolveTestCase() {
    int rows;
    int columns;
    int mines;
    cin >> rows >> columns >> mines;
    int noMines = rows * columns - mines;
    bool isTransposed = false;
    if (rows > columns) {
        isTransposed = true;
        swap(rows, columns);
    }
    field = vector< vector<char> >(rows, vector<char>(columns, '*'));
    if (noMines != 1) {
        if (rows == 1) {
            if (noMines > 1) {
                for (int i = 0; i < noMines; i++) {
                    field[0][i] = '.';
                }
            }
        }
        if (rows == 2) {
            if ((noMines & 1) != 0) {
                return false;
            }
            if (noMines == 2 && mines > 0) {
                return false;
            }
            for (int i = 0; 2 * i < noMines; i++) {
                field[0][i] = '.';
                field[1][i] = '.';
            }
        }
        if (rows >= 3) {
            if (noMines < 4 || noMines == 5 || noMines == 7) {
                return false;
            }
            if (noMines <= 2 * columns + 1) {
                for (int i = 0; i < noMines / 2 - 1; i++) {
                    field[0][i] = '.';
                    field[1][i] = '.';
                }
                if ((noMines & 1) != 0) {
                    field[2][0] = '.';
                    field[2][1] = '.';
                    field[2][2] = '.';
                }
                else {
                    field[0][noMines / 2 - 1] = '.';
                    field[1][noMines / 2 - 1] = '.';
                }
            }
            else {
                int lines = noMines / columns;
                for (int j = 0; j < lines; j++) {
                    for (int i = 0; i < columns; i++) {
                        field[j][i] = '.';
                    }
                }
                for (int i = 0; i < noMines % columns; i++) {
                    field[lines][i] = '.';
                }
                if ((noMines % columns) == 1) {
                    field[lines][1] = '.';
                    field[lines - 1][columns - 1] = '*';
                }
            }
        }
    }
    field[0][0] = 'c';
    if (isTransposed) {
        field = Transpose(field);
    }
	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	freopen("C-large.in", "r", stdin);
	//freopen("large.in", "r", stdin);

	freopen("output.txt", "w", stdout);

	int numCases;
	cin >> numCases;

	for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
		PrintAnswerToTestCase(caseNumber, SolveTestCase<bool>() );

	return 0;
}