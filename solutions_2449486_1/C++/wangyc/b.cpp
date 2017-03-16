#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int a[100][100];
int n, m;
int time;

bool check(const int &limit)
{
	set<int> row, col;
	row.clear();
	col.clear();
	for (int i = 0; i < n; ++i) {
		bool flag = 1;
		for (int j = 0; j < m; ++j)
			if (a[i][j] > limit)
				flag = 0;
		if (flag) row.insert(i);
	}
	for (int j = 0; j < m; ++j) {
		bool flag = 1;
		for (int i = 0; i < n; ++i)
			if (a[i][j] > limit)
				flag = 0;
		if (flag) col.insert(j);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] <= limit && row.count(i) + col.count(j) <= 0)
				return 0;
	return 1;
}

int main()
{
	ifstream read("b.in");
	ofstream write("b.out");
	read >> time;
	for (int ite = 0; ite < time; ++ite) {
		read >> n >> m;
		int high = 0;
		bool possible = 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				read >> a[i][j];
				if (a[i][j] > high)
					high = a[i][j];
			}
		for (int limit = high - 1; limit >= 1; --limit)
			if (!check(limit)) {
				possible = 0;
				break;
			}
		write << "Case #" << ite + 1 << ": ";
		if (possible) write << "YES" << endl;
		else write << "NO" << endl;
	}
	return 0;
}
