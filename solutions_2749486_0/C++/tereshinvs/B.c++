#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

const int C1 = 1000, C2 = 500;

int res[C1][C1];
char pr[C1][C1];
bool alr[C1][C1];

int lastx = 0, lasty = 0;

priority_queue< pair<int, pair<int, int> > > q;

void try_step(int x, int y, int val) {
	if (x >= 0 && y >= 0 && x < C1 && y < C1 && res[x][y] > val) {
		res[x][y] = val;
		q.push(make_pair(-res[x][y], make_pair(x, y)));
		if (x < lastx)
			pr[x][y] = 'W';
		if (x > lastx)
			pr[x][y] = 'E';
		if (y < lasty)
			pr[x][y] = 'S';
		if (y > lasty)
			pr[x][y] = 'N';
	}
}

void dijkstra() {
	for (int i = 0; i < C1; i++)
		for (int j = 0; j < C1; j++) {
			res[i][j] = 1000000000;
			pr[i][j] = ' ';
			alr[i][j] = false;
		}
//	cout << "a";
	res[C2][C2] = 0;
	q.push(make_pair(0, make_pair(C2, C2)));
	for (int i = 0; i < C1 * C1; i++) {
		int curx = -1, cury = -1, curmin = 1000000001;
/*		for (int j1 = 0; j1 < C1; j1++)
			for (int j2 = 0; j2 < C1; j2++)
				if (!alr[j1][j2] && res[j1][j2] < curmin) {
					curmin = res[j1][j2];
					curx = j1;
					cury = j2;
				}*/
		//cout << "1";
		while (true) {
		//	cout << "2";
			if (q.empty())
				return;
			auto t = q.top();
			if (alr[t.second.first][t.second.second]) {
				q.pop();
				continue;
			}
			curx = t.second.first;
			cury = t.second.second;
			curmin = -t.first;
			break;
		}
		if (curx == -1 || cury == -1)
			break;
		alr[curx][cury] = true;

		if (curmin == 1000000000)
			continue;

		lastx = curx; lasty = cury;
		try_step(curx + curmin + 1, cury, curmin + 1);
		try_step(curx - curmin - 1, cury, curmin + 1);
		try_step(curx, cury + curmin + 1, curmin + 1);
		try_step(curx, cury - curmin - 1, curmin + 1);
	}
//	cout << "b";
}

int main() {
	int t;
	cin >> t;

	dijkstra();
	//return 0;

	for (int q = 0; q < t; q++) {
		int _x, _y;
		cin >> _x >> _y;

		string sres = "";
		for (int x = _x + C2, y = _y + C2; x != C2 || y != C2; ) {
			sres += pr[x][y];
	//		cout << x << " " << y << endl;
			switch (pr[x][y]) {
				case 'S': y += res[x][y]; break;
				case 'N': y -= res[x][y]; break;
				case 'E': x -= res[x][y]; break;
				case 'W': x += res[x][y]; break;
				default: break;
			}
		}

		cout << "Case #" << q + 1 << ": ";
		for (auto it = sres.rbegin(); it != sres.rend(); it++)
			cout << *it;
		cout << endl;
	}
}