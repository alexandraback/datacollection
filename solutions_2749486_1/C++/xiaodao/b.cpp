#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <vector>
using namespace std;

string X = "WE", Y = "SN"; //-1/+1

int n, x, y;

const int MAX_N = 100000;
int who[MAX_N], how[MAX_N];

//X:0,Y:1
void addMove(int i, int wh, int hw) {
	who[i] = wh;
	how[i] = hw;
}

void check(string a) {
	int X = 0, Y = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == 'N')
			Y += i + 1;
		else if (a[i] == 'S')
			Y -= i + 1;
		else if (a[i] == 'W')
			X -= i + 1;
		else
			X += i + 1;
	}
	cerr << X << " " << Y << endl;
}

void check(int n, int x, int y) {
	//[1..n]
	int tot = abs(x) + abs(y);
	int have = n * (n + 1) / 2;

	int over = (have - tot) / 2;
	int sigx = x < 0, sigy = y < 0;
	x = abs(x), y = abs(y);
	//take over to -x
	fill(who, who + n + 1, -1);
	addMove(over, 0, 0);
	x += over;

	//make x
	if (x > y) {
		for (int i = n; i >= 1; --i) {
			if (who[i] == -1) {
				if (i <= x) {
					addMove(i, 0, 1); //X
					x -= i;
				} else {
					addMove(i, 1, 1); //Y
				}
			}
		}
	} else {
		for (int i = n; i >= 1; --i) {
			if (who[i] == -1) {
				if (i <= y) {
					addMove(i, 1, 1); //Y
					y -= i;
				} else {
					addMove(i, 0, 1); //X;
				}
			}
		}
	}

	//write
	string ret;
	for (int i = 1; i <= n; ++i) {
		if (who[i] == 0) //X
			ret += X[sigx ^ how[i]];
		else
			ret += Y[sigy ^ how[i]];
	}
	cout << ret << endl;
//	check(ret);
}

void work() {
	int X, Y;
	cin >> X >> Y;
	int tot = abs(X) + abs(Y);

	for (int n = 1;; ++n) {
		int have = n * (n + 1) / 2;
		if (have < tot)
			continue;
		if ((have - tot) % 2 == 1)
			continue;
		check(n, X, Y);
		return;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		work();
	}
}
