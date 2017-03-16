#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


bool fullHorizontal(char c, string data[], int row) {
	bool valid = true;
	for (int i=0; i<4; i++) {
		if (!(data[row][i] == c || data[row][i] == 'T')) {
			valid = false;
		}
	}
	return valid;
}
bool fullVertical(char c, string data[], int column) {
	bool valid = true;
	for (int i=0; i<4; i++) {
		if (!(data[i][column] == c || data[i][column] == 'T')) {
			valid = false;
		}
	}
	return valid;
}

bool fullDiagonal(char c, string data[], int x) {
	bool valid = true;
	int row,col,dx,dy;
	if (x==0) { // kiriatas->kananbawah
		row = 0;
		col = 0;
		dx = 1;
		dy = 1;
	} else {
		row = 0;
		col = 3;
		dx = 1;
		dy = -1;
	}
	for (int i=0; i<4;i++) {
		if (!(data[row][col] == c || data[row][col] == 'T')) {
			valid = false;
		}
		row+=dx;
		col+=dy;
	}
	return valid;
}


bool win(char c, string data[]) {
	bool w = false;
	for (int i=0; !w && i<4; i++) {
		w |= fullHorizontal(c,data,i);
	}
	for (int i=0; !w && i<4; i++) {
		w |= fullVertical(c,data,i);
	}
	for (int i=0; !w && i<2; i++) {
		w |= fullDiagonal(c,data,i);
	}
	return w;
}

bool full(string data[]) {
	bool valid = true;
	for (int i=0; valid && i<4; i++) {
		for (int j=0; valid && j<4; j++) {
			valid &= (data[i][j]!='.');
		}
	}
	return valid;
}

void execute(int tc) {
	string k[4];
	for (int i=0; i<4; i++) {
		getline(cin,k[i]);
		cerr << k[i] << endl;
	}
	scanf("\n");
	if (win('X', k)) {
		printf("Case #%d: X won\n", tc);
	} else if (win('O', k)) {
		printf("Case #%d: O won\n", tc);
	} else if (full(k)) {
		printf("Case #%d: Draw\n", tc);
	} else {
		printf("Case #%d: Game has not completed\n", tc);
	}
}

int main() {
	int tc;
	scanf("%d\n",&tc);
	for (int i=1; i <= tc; i++) {
		execute(i);
	}
	return 0;
}
