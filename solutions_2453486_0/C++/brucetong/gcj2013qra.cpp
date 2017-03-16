//Problem: Google Code Jam 2013 Qualification Round A
//Name: Tic-Tac-Toe-Tomek
//Author: Bruce K. B. Tong
//Tag: Ad Hoc

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SMALL
//#define LARGE

void read(char b[4][4]) {
	for (int i = 0; i < 4; i++, cin.ignore())
		for (int j = 0; j < 4; j++)
			cin >> b[i][j];
	cin.ignore();
}

void print(char b[4][4]) {
	for (int i = 0; i < 4; i++, cout << endl)
		for (int j = 0; j < 4; j++)
			cout << b[i][j];
	cout << endl;
}

int check(int count[]) {
	if (count['X'] == 4 || (count['X'] == 3 && count['T'] == 1)) return 1;
	if (count['O'] == 4 || (count['O'] == 3 && count['T'] == 1)) return -1;
	return 2;
}

int solve(char b[4][4]) {
	int empty = 0;
	//row
	for (int i = 0; i < 4; i++) {
		int count['X'+1] = {0};
		for (int j = 0; j < 4; j++)
			count[b[i][j]]++;
		empty += count['.'];
		int ans = check(count);
		if (ans == 1 || ans == -1) return ans;
	}
	//col
	for (int j = 0; j < 4; j++) {
		int count['X'+1] = {0};
		for (int i = 0; i < 4; i++)
			count[b[i][j]]++;
		empty += count['.'];
		int ans = check(count);
		if (ans == 1 || ans == -1) return ans;
	}
	//dia
	int count['X'+1] = {0};
	for (int i = 0; i < 4; i++)
		count[b[i][i]]++;
	empty += count['.'];
	int ans = check(count);
	if (ans == 1 || ans == -1) return ans;
	
	//reverse dia
	count['T'] = count['O'] = count['X'] = count['.'] = 0;
	for (int i = 0; i < 4; i++)
		count[b[i][3-i]]++;
	empty += count['.'];
	ans = check(count);
	if (ans == 1 || ans == -1) return ans;

	return empty == 0? 0: 2;
	//1: X won, -1: O won, 0: draw, 2: not complete
}

int main() {
	freopen("A-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("A-small-attempt1.in", "rt", stdin);
		freopen("A-small-attempt1.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("A-large.in", "rt", stdin);
		freopen("A-large.out", "wt", stdout);
	#endif

	int T;				//1 <= T <= 10 (or 1,000)
	char b[4][4];
	
	cin >> T;
	cin.ignore();
	for (int i = 1; i <= T; i++) {
		read(b);
		//print(b);
		cout << "Case #" << i << ": ";
		int ans = solve(b);
		if (ans == 1)
			cout << "X won";
		else if (ans == -1)
			cout << "O won";
		else if (ans == 0)
			cout << "Draw";
		else
			cout << "Game has not completed";
		cout << endl;
	}
	return 0;
}