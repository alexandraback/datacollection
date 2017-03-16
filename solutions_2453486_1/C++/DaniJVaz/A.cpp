#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		char arr[4][5];
		const char * state = "Draw";

		for (int i=0; i<4; i++) {
			scanf("%s", &arr[i][0]);
			for (int j=0; j<4; j++)
				if (arr[i][j] == '.')
					state = "Game has not completed";
		}

		bool finished = false;

		if (!finished) {
			for (int i=0; i<4; i++) {
				bool O = true, X = true;
				for (int j=0; j<4; j++) {
					if (arr[i][j] == '.')
						O = X = false;
					else if (arr[i][j] == 'X')
						O = false;
					else if (arr[i][j] == 'O')
						X = false;
				}
				if (X) {
					state = "X won";
					finished = true;
					break;
				}
				if (O) {
					state = "O won";
					finished = true;
					break;
				}
			}
		}

		if (!finished) {
			for (int i=0; i<4; i++) {
				bool O = true, X = true;
				for (int j=0; j<4; j++) {
					if (arr[j][i] == '.')
						O = X = false;
					else if (arr[j][i] == 'X')
						O = false;
					else if (arr[j][i] == 'O')
						X = false;
				}
				if (X) {
					state = "X won";
					finished = true;
					break;
				}
				if (O) {
					state = "O won";
					finished = true;
					break;
				}
			}
		}

		if (!finished){
			bool O = true, X = true;
			for (int i=0; i<4; i++) {
				if (arr[i][i] == '.')
					O = X = false;
				else if (arr[i][i] == 'X')
					O = false;
				else if (arr[i][i] == 'O')
					X = false;
			}
			
			if (X) {
				state = "X won";
				finished = true;
			}
			if (O) {
				state = "O won";
				finished = true;
			}
		}

		if (!finished){
			bool O = true, X = true;
			for (int i=0; i<4; i++) {
				if (arr[i][3-i] == '.')
					O = X = false;
				else if (arr[i][3-i] == 'X')
					O = false;
				else if (arr[i][3-i] == 'O')
					X = false;
			}
			
			if (X) {
				state = "X won";
				finished = true;
			}
			if (O) {
				state = "O won";
				finished = true;
			}
		}

		printf("Case #%d: %s\n", iC, state);
	}
	return 0;
}
