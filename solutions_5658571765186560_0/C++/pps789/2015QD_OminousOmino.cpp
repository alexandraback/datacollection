#include<iostream>
#include<algorithm>
using namespace std;

bool res[4][4][4] = {
	{ // X=1
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 }
	},
	{ // X=2
		{ 0, 1, 0, 1 },
		{ 1, 1, 1, 1 },
		{ 0, 1, 0, 1 },
		{ 1, 1, 1, 1 }
	},
	{ // X=3
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 1, 0 },
	},
	{ // X=4
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 1 }
	}
};

int main(){
	freopen("small.in", "r", stdin);
	freopen("small.txt", "w", stdout);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		int x, r, c;
		cin >> x >> r >> c;
		if (res[x - 1][r - 1][c - 1])
			cout << "GABRIEL" << endl;
		else cout << "RICHARD" << endl;
	}
}