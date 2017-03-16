#include<string>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int T;
vector<string> a;

void init() {
	a.clear();
	while (a.size() < 4) {
		string s = "";
		cin >> s;
		if (s.length() > 1)
			a.push_back(s);
	}
}

bool check(char c) {
	bool flag;
	for (int i=0; i<4; i++) {
		flag = true;
		for (int j=0; j<4; j++) {
			if (a[i][j] != c && a[i][j] != 'T')
				flag = false;
		}
		if (flag)
			return true;

		flag = true;
		for (int j=0; j<4; j++) {
			if (a[j][i] != c && a[j][i] != 'T')
				flag = false;
		}
		if (flag)
			return true;
	}
	flag = true;
	for (int i=0; i<4; i++)
		if (a[i][i] != c && a[i][i] != 'T')
			flag = false;
	if (flag)
		return true;
	flag = true;
	for (int i=0; i<4; i++)
		if (a[i][4-i-1] != c && a[i][4-i-1] != 'T')
			flag = false;
	if (flag)
		return true;
	return false;
}

string work() {
	if (check('X'))
		return "X won";
	else if (check('O'))
		return "O won";
	else {
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				if (a[i][j]=='.')
					return "Game has not completed";
		return "Draw";
	}
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (int i=1; i<=T; i++) {
		init();
		cout << "Case #" << i << ": " << work() << endl;
	}
	return 0;
}