#include <iostream>
#include <map>
using namespace std;

typedef map<int, char> cols;
typedef map<char, int> countRowCols;
typedef map<char, int> countColCols;
typedef map<char, int> countDiaCols;

int main() {
	int n;
	int size = 4;
	int caseCount = 0;

	cin >> n;
	while (n--) {
		map<int, cols> table;
		map<int, countRowCols> countRow;
		map<int, countColCols> countCol;
		map<int, countDiaCols> countDia;
		bool oWin = false;
		bool xWin = false;
		bool havePoint = false;

		for (int i=0; i<size; i++) {
			for (int j=0; j<size; j++) {
				cin >> table[i][j];
				if (table[i][j] == 'O') {
					countRow[i]['O']++;
					countCol[j]['O']++;
					if (i == j)
						countDia[0]['O']++;
					else if (i + j == 3)
						countDia[1]['O']++;
				}
				else if (table[i][j] == 'X') {
					countRow[i]['X']++;
					countCol[j]['X']++;
					if (i == j)
						countDia[0]['X']++;
					else if (i + j == 3)
						countDia[1]['X']++;
				}
				else if (table[i][j] == 'T') {
					countRow[i]['T']++;
					countCol[j]['T']++;
					if (i == j)
						countDia[0]['T']++;
					else if (i + j == 3)
						countDia[1]['T']++;
				}
				else if (table[i][j] == '.')
					havePoint = true;
			}
		}

		for (int i=0; i<size; i++) {
			if (countRow[i]['X'] == 4 || (countRow[i]['X'] == 3 && countRow[i]['T'] == 1))
				xWin = true;
			else if (countRow[i]['O'] == 4 || (countRow[i]['O'] == 3 && countRow[i]['T'] == 1))
				oWin = true;
			else if (countCol[i]['X'] == 4 || (countCol[i]['X'] == 3 && countCol[i]['T'] == 1))
				xWin = true;
			else if (countCol[i]['O'] == 4 || (countCol[i]['O'] == 3 && countCol[i]['T'] == 1))
				oWin = true;
		}
		for (int i=0; i<2; i++) {
			if (countDia[i]['X'] == 4 || (countDia[i]['X'] == 3 && countDia[i]['T'] == 1))
				xWin = true;
			else if (countDia[i]['O'] == 4 || (countDia[i]['O'] == 3 && countDia[i]['T'] == 1))
				oWin = true;
		}

		cout << "Case #" << ++caseCount;
		if (xWin)
			 cout << ": X won";
		else if (oWin)
			 cout << ": O won";
		else if (havePoint)
			cout << ": Game has not completed";
		else
			cout << ": Draw";
		cout << endl;
	}

	return 0;
}
