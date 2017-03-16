#pragma comment (linker, "/STACK:268435456")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <functional>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <ctime>

using namespace std;
template <class T> T sqr(T a) { return a * a; }

int t, r, n, m, k;
int z[100][3];
int p[3];
int a[10];

int check()
{
	set<int> s;
	for (int i = 0; i < 8; i++)
	{
		int cur = 1;
		for (int j = 0; j < 3; j++)
			if ((i >> j) & 1)
				cur *= p[j];
		s.insert(cur);
	}
	for (int i = 0; i < k; i++)
		if (s.find(a[i]) == s.end())
			return 0;
	return 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t >> r >> n >> m >> k;
	cout << "Case #1: ";
	cout << endl;
	srand(time(0));
	for (int tc = 0; tc < r; tc++)
	{
		for (int i = 0; i < k; i++)
			cin >> a[i];
		int zc = 0;
		for (p[0] = 2; p[0] <= 5; p[0]++)
			for (p[1] = 2; p[1] <= 5; p[1]++)
				for (p[2] = 2; p[2] <= 5; p[2]++)
					if (check())
						z[zc][0] = p[0], z[zc][1] = p[1], z[zc][2] = p[2], zc++;
		int g = rand() % zc;
		for (int i = 0; i < 3; i++)
			cout << z[g][i];
		cout << endl;
	}
	return 0;
}