#include <fstream>
#include <iostream>

using namespace std;

char Check(char line[4]) {
	if ((line[0] == 'X' || line[0] == 'T') &&
		(line[1] == 'X' || line[1] == 'T') &&
		(line[2] == 'X' || line[2] == 'T') &&
		(line[3] == 'X' || line[3] == 'T')) {
			return 'X';
	} else if ((line[0] == 'O' || line[0] == 'T') &&
		(line[1] == 'O' || line[1] == 'T') &&
		(line[2] == 'O' || line[2] == 'T') &&
		(line[3] == 'O' || line[3] == 'T')) {
			return 'O';
	} else if (line[0] != '.' && line[1] != '.' && line[2] != '.' && line[3] != '.') {
		return 'N';
	} else {
		return 'E';
	}

}
void TicTacToeTomek(char * fileInput, char * fileOutput) {
	ifstream input(fileInput);
	ofstream output(fileOutput);

	char buffer[4];
	input.getline(buffer, 8);
	int testcaseCount = atoi(buffer);

	cout << testcaseCount;
	for (int i = 0; i < testcaseCount; i++) {
		
		char hLine1[4], hLine2[4], hLine3[4], hLine4[4], vLine1[4], vLine2[4], vLine3[4], vLine4[4], dLine1[4], dLine2[4];
		input.getline(hLine1, 8);
		input.getline(hLine2, 8);
		input.getline(hLine3, 8);
		input.getline(hLine4, 8);

		if (i < testcaseCount - 1)
			input.getline(buffer, 8);
		vLine1[0] = hLine1[0]; vLine1[1] = hLine2[0]; vLine1[2] = hLine3[0]; vLine1[3] = hLine4[0];
		vLine2[0] = hLine1[1]; vLine2[1] = hLine2[1]; vLine2[2] = hLine3[1]; vLine2[3] = hLine4[1];
		vLine3[0] = hLine1[2]; vLine3[1] = hLine2[2]; vLine3[2] = hLine3[2]; vLine3[3] = hLine4[2];
		vLine4[0] = hLine1[3]; vLine4[1] = hLine2[3]; vLine4[2] = hLine3[3]; vLine4[3] = hLine4[3];
		dLine1[0] = hLine1[0]; dLine1[1] = hLine2[1]; dLine1[2] = hLine3[2]; dLine1[3] = hLine4[3];
		dLine2[0] = hLine1[3]; dLine2[1] = hLine2[2]; dLine2[2] = hLine3[1]; dLine2[3] = hLine4[0];
		
		char results[10];
		cout << hLine1 << endl;
		cout << hLine2 << endl;
		cout << hLine3 << endl;
		cout << hLine4 << endl;
		results[0] = Check(hLine1);
		results[1] = Check(hLine2);
		results[2] = Check(hLine3);
		results[3] = Check(hLine4);
		results[4] = Check(vLine1);
		results[5] = Check(vLine2);
		results[6] = Check(vLine3);
		results[7] = Check(vLine4);
		results[8] = Check(dLine1);
		results[9] = Check(dLine2);
		bool xWon = false, oWon = false, draw = true;
		for (int j = 0; j < 10; j++) {
			if (results[j] == 'X') {
				xWon = true;
				break;
			}
			if (results[j] == 'O') {
				oWon = true;
				break;
			}
			if (results[j] != 'N') draw = false;
		}
		if (xWon) {
			output << "Case #" << (i + 1) << ": " << "X won" << endl;
		} else if (oWon) {
			output << "Case #" << (i + 1) << ": " << "O won" << endl;
		} else if (draw) {
			output << "Case #" << (i + 1) << ": " << "Draw" << endl;
		} else {
			output << "Case #" << (i + 1) << ": " << "Game has not completed" << endl;
		}
	}
	
	input.close();
	output.close();
}

int main() {
	TicTacToeTomek("A-large.in", "A-large.out");
	
}
