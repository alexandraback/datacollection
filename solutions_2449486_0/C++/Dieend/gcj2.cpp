#include <iostream>
using namespace std;

int nr,nc;
int data[110][110];
int cutted[110][110];

bool noHigherInSameRow(int row, int value) {
	bool ret = true;
	for (int i=0; ret && i<nc; i++) {
		if (data[row][i] > value) {
			ret = false;
		}
	}
	return ret;
}
void cutRow(int row, int value) {
	for (int i=0; i<nc; i++) {
		cutted[row][i] = value;
	}
}

bool noHigherInSameColumn(int col, int value) {
	bool ret = true;
	for (int i=0; ret && i<nr; i++) {
		if (data[i][col] > value) {
			ret = false;
		}
	}
	return ret;
}
void cutColumn(int col, int value) {
	for (int i=0; i<nr; i++) {
		cutted[i][col] = value;
	}
}

void execute(int tc){
	scanf("%d %d", &nr, &nc);
	for (int i=0; i<nr; i++) {
		for (int j=0; j<nc; j++) {
			scanf("%d", &data[i][j]);
			cutted[i][j] = 100;
		}
	}
	for (int val=99; val>=0; val--) {
		for (int i=0; i<nr; i++) {
			if (noHigherInSameRow(i,val)) {
				cutRow(i, val);
			}		
		}
		for (int i=0; i<nc; i++) {
			if (noHigherInSameColumn(i,val)) {
				cutColumn(i, val);
			}
		}
	}
	bool valid = true;
	for (int i=0; valid && i<nr; i++) {
		for (int j=0; valid && j<nc; j++) {
			if (data[i][j] != cutted[i][j]) {
				valid = false;
			}
		}
	}
	printf("Case #%d: ", tc);
	if (valid) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int i=1; i<=tc; i++) {
		execute(i);
	}
	return 0;
}
