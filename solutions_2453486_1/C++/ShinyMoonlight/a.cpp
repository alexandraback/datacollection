#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

char tic[5][1001];
char line[1001];


bool x_win();
bool o_win();

int main() {


    int i, j, k, n;

    cin >> n;
    cin.getline(line, 1000);
    for (int test=1; test<=n; ++test) {
	for (int i=0; i<4; ++i) {
	    cin >> tic[i];
	}
	cin.getline(line, 1000);

	cout << "Case #" << test << ": ";
	bool x = x_win();
	bool o = o_win();
	if (x) {
	    cout << "X won";
	}
	else if(o) {
	    cout << "O won";
	}
	else {
	    bool finished = true;
	    for (int i=0; i<4; ++i) for (int j=0; j<4; ++j) if (tic[i][j] == '.') finished = false;

	    if (finished) {
		cout << "Draw";
	    }
	    else {
		cout << "Game has not completed";
	    }
	}
	cout << endl;

    }
    return 0;
}

bool x_win() {
    int i, j, r, c, dl, dr;

    dl = dr = 0;
    for (int i=0; i<4; ++i) {
	r = c = 0;
	for (int j=0; j<4; ++j) {
	    if (tic[i][j] == 'X' || tic[i][j] == 'T') {
		++r;
	    }
	    if (tic[j][i] == 'X' || tic[j][i] == 'T') {
		++c;
	    }
	}
	if (r == 4 || c == 4) {
	    return true;
	}
	if (tic[i][i] == 'X' || tic[i][i] == 'T') {
	    ++dl;
	}
	if (tic[i][4-i-1] == 'X' || tic[i][4-i-1] == 'T') {
	    ++dr;
	}
	if (dl == 4 || dr == 4) {
	    return true;
	}
    }
    return false;
}

bool o_win() {
    int i, j, r, c, dl, dr;

    dl = dr = 0;
    for (int i=0; i<4; ++i) {
	r = c = 0;
	for (int j=0; j<4; ++j) {
	    if (tic[i][j] == 'O' || tic[i][j] == 'T') {
		++r;
	    }
	    if (tic[j][i] == 'O' || tic[j][i] == 'T') {
		++c;
	    }
	}
	if (r == 4 || c == 4) {
	    return true;
	}
	if (tic[i][i] == 'O' || tic[i][i] == 'T') {
	    ++dl;
	}
	if (tic[i][4-i-1] == 'O' || tic[i][4-i-1] == 'T') {
	    ++dr;
	}
	if (dl == 4 || dr == 4) {
	    return true;
	}
    }
    return false;
}
