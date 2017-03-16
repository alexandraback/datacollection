#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int R, C, M;
bool mirror;
vector<string> v;
int visited[50][50];
int countVisited;

int getMine(int i, int j) {
	if (i < 0 || i >= R || j < 0 || j >= C) return 0;
	return (v[i][j] == '*' ? 1 : 0);
}

void dfs(int i, int j) {
	if (i < 0 || i >= R || j < 0 || j >= C) return;
	if (v[i][j] == '*') return;
	if (visited[i][j]) return;
	visited[i][j] = true;
	countVisited++;
	int mines = 0;
	for (int x = -1; x <= 1; x++)
		for (int y = -1; y <= 1; y++)
			mines += getMine(i + x, j + y);
	if (mines == 0) {
		for (int x = -1; x <= 1; x++)
			for (int y = -1; y <= 1; y++)
				dfs(i + x, j + y);
	}
}

void verifySolution() {
	assert((int) v.size() == R);
	int countClick = 0;
	int countEmpty = 0;
	int countMine = 0;
	int xC = -1;
	int yC = -1;
	for (int i = 0; i < R; i++) {
		assert((int) v[i].size() == C);
		for (int j = 0; j < C; j++) {
			assert(v[i][j] == 'c' || v[i][j] == '.' || v[i][j] == '*');
			if (v[i][j] == 'c') {
				countClick++;
				xC = i;
				yC = j;
			}
			if (v[i][j] == '.') countEmpty++;
			if (v[i][j] == '*') countMine++;
		}
	}
	assert(countClick + countEmpty + countMine == R * C);
	assert(countMine == M);
	assert(countClick == 1);
	assert(xC >= 0 && xC < R);
	assert(yC >= 0 && yC < C);
	memset(visited, 0 ,sizeof visited);
	countVisited = 0;
	dfs(xC, yC);
	assert(countVisited == countClick + countEmpty);
}

void doPrintStuff() {
	assert(v.back().size() == 0);
	v.pop_back();
	verifySolution();
	if (mirror) {
		for (int j = 0; j < C; j++) {
			for (int i = 0; i < R; i++)
				cout << v[i][j];
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < R; i++) {
			cout << v[i] << endl;
		}
	}
}

bool doSpecialCases() {
	if (R >= 3)
		return false;
	if (R == 2) {
		if ((M % 2) != 0) {
			cout << "Impossible" << endl;
			return true;
		}
		int vol = M / 2;
		int leeg = C - vol;
		assert(leeg >= 1 && leeg <= C);
		assert(vol >= 0 && vol < C);
		// eerste rij
		for (int j = 1; j < leeg; j++) v.back().push_back('.');
		for (int j = 0; j < vol; j++) v.back().push_back('*'); v.push_back("");
		// tweede rij
		for (int j = 0; j < leeg; j++) v.back().push_back('.');
		for (int j = 0; j < vol; j++) v.back().push_back('*'); v.push_back("");
	}
	else {
		for (int j = 1; j < C - M; j++) v.back().push_back('.');
		for (int j = 0; j < M; j++) v.back().push_back('*'); v.push_back("");
	}
	doPrintStuff();
	return true;
}

void solve() {
	cin >> R >> C >> M;
	assert(R > 0 && R <= 50);
	assert(C > 0 && C <= 50);
	int RC = R * C;
	assert(M >= 0 && M < RC);
	mirror = false;
	v.clear();
	v.push_back("c");
	if (R > C) {
		swap(R, C);
		mirror = true;
	}
	int rest = RC - M;
	if (rest == 1) {
		for (int j = 1; j < C; j++) v.back().push_back('*'); v.push_back(""); // brackets missing on purpose
		for (int i = 1; i < R; i++) {
			for (int j = 0; j < C; j++) v.back().push_back('*'); v.push_back("");
		}
		doPrintStuff();
		return;
	}
	if (R > 1 && (rest == 2 || rest == 3 || rest == 5 || rest == 7)) {
		cout << "Impossible" << endl;
		return;
	}
	if (doSpecialCases()) return;
	if (rest == 4 || rest == 6) {
		int a = rest / 2;
		// eerste rij
		for (int j = 1; j < a; j++) v.back().push_back('.');
		for (int j = a; j < C; j++) v.back().push_back('*'); v.push_back("");
		// tweede rij
		for (int j = 0; j < a; j++) v.back().push_back('.');
		for (int j = a; j < C; j++) v.back().push_back('*'); v.push_back("");
		// overige rijen
		for (int i = 2; i < R; i++) {
			for (int j = 0; j < C; j++) v.back().push_back('*'); v.push_back("");
		}
		doPrintStuff();
		return;
	}
	int vollerijen = min(M / C, R - 3);
	assert(vollerijen >= 0);
	int halverijen = R - vollerijen;
	rest = M - vollerijen * C;
	assert(rest >= 0);
	assert(rest < C || (vollerijen == R - 3 && rest < 3 * C));
	if (vollerijen == R - 3 && rest >= C - 1) {
		int drie = 2 + ((C + rest) % 2);
		int eentwee = (rest + drie - C) / 2;
		assert(2 * eentwee + (C - drie) == rest);
		// eerste rij
		for (int j = 1; j < C - eentwee; j++) v.back().push_back('.');
		for (int j = 0; j < eentwee; j++) v.back().push_back('*'); v.push_back("");
		// tweede rij
		for (int j = 0; j < C - eentwee; j++) v.back().push_back('.');
		for (int j = 0; j < eentwee; j++) v.back().push_back('*'); v.push_back("");
		// derde rij
		for (int j = 0; j < drie; j++) v.back().push_back('.');
		for (int j = drie; j < C; j++) v.back().push_back('*'); v.push_back("");
	}
	else {
		// eerste rij
		for (int j = 1; j < C; j++) v.back().push_back('.'); v.push_back("");
		// rijen 2 tot en met halverijen - 2
		for (int i = 1; i < halverijen - 2; i++) {
			for (int j = 0; j < C; j++) v.back().push_back('.'); v.push_back("");
		}
		int een = (rest == C - 1 ? 2 : 0);
		int twee = rest - een;
		// rij nummer halverij - 1
		for (int j = 0; j < C - een; j++) v.back().push_back('.');
		for (int j = 0; j < een; j++) v.back().push_back('*'); v.push_back("");
		// rij nummer halverij
		for (int j = 0; j < C - twee; j++) v.back().push_back('.');
		for (int j = 0; j < twee; j++) v.back().push_back('*'); v.push_back("");
	}
	for (int i = 0; i < vollerijen; i++) {
		for (int j = 0; j < C; j++) v.back().push_back('*'); v.push_back("");
	}
	doPrintStuff();
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ":" << endl;
		solve();
	}
	return 0;
}
