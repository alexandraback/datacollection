#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <numeric>

#define all(x) x.begin(), x.end()
#define INF 0x7fffffff
#define PI acos(-1)

using namespace std;

const char *op[] = {
	"X won",
	"O won",
	"Draw",
	"Game has not completed"
};

int solve(vector<string> &G) {
	int R[4] = {0};
	int C[4] = {0};
	int TR[4] = {4,4,4,4};
	int TC[4] = {4,4,4,4};
	int ndots = 0;

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (G[i][j] == 'X') R[i]++, C[j]++;
			if (G[i][j] == 'O') R[i]--, C[j]--;
			if (G[i][j] == 'T') TR[i]--, TC[j]--;
			if (G[i][j] == '.') ndots++;
		}
	}

	for (int i=0; i<4; i++) {
		if (R[i] == TR[i] || C[i] == TC[i]) return 0;
		if (R[i] == -TR[i] || C[i] == -TC[i]) return 1;
	}

	//diagonals
	int x = 0, o = 0, t = 0;
	for (int i=0; i<4; i++) {
		if (G[i][i] == 'X') x++;
		if (G[i][i] == 'O') o++;
		if (G[i][i] == 'T') t++;
	}
	if (x == 4-t) return 0;
	if (o == 4-t) return 1;

	x = 0; o = 0; t = 0;
	for (int i=0; i<4; i++) {
		if (G[i][3-i] == 'X') x++;
		if (G[i][3-i] == 'O') o++;
		if (G[i][3-i] == 'T') t++;
	}
	if (x == 4-t) return 0;
	if (o == 4-t) return 1;

	if (!ndots) return 2;
	return 3;
}	

int main() {
	int testcases;
	cin >> testcases;
	cin.ignore();
	for (int t = 1; t <= testcases; t++) {
		vector<string> G(4, "");
		for (int i=0; i<4; i++) {
			cin >> G[i];
		}
		cout << "Case #" << t << ": " << op[solve(G)] << endl;
		cin.ignore();
	}
	return 0;
}
