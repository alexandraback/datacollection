#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef long long int64;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= a; --i)
#define SIZE(a) ((a).size())

template<typename T> T gcd(T a, T b) { if (!b) return a; else return gcd(b, a%b);}
template<typename T> void ext_euclid(T a, T b, T& x, T& y) { if (!b) {x=1; y=0;} else {int xx, yy; ext_euclid(b, a%b, xx, yy); x=yy; y=-yy*(a/b)+xx;}}

int maxSteps;
int targetX;
int targetY;

string res = "";
string finalRes = "";
bool found = false;

int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, -1, 0, 1};
char dir[] = {'E', 'S', 'W', 'N'};

void go(int x, int y, int step)
{
	if (step > maxSteps)
		return;
	if (found)
		return;
	if (x == targetX && y == targetY)
	{
		finalRes = res;
		found = true;
		return;
	}
	
	for (int d = 0; d < 4; ++d)
	{
		int newX = x + step * dirX[d];
		int newY = y + step * dirY[d];
		
		res += dir[d];
		go(newX, newY, step + 1);
		res = res.substr(0, res.length() - 1);
	}
}

int main()
{
	const char* inFile = "in.txt";
	const char* outFile = "out.txt";
	freopen(inFile, "r", stdin);
	freopen(outFile, "w", stdout);

	int T;
	cin >> T;

	for (int t=1; t<=T; t++)
	{
		cin >> targetX >> targetY;

		found = false;
		res = finalRes = "";
		for (maxSteps = 1; maxSteps <= 7; ++maxSteps)
		{
			go(0, 0, 1);
			if (found)
			{
				printf("Case #%d: %s\n", t, finalRes.c_str());
				break;
			}
		}
		
		if (found)
			continue;
		
		int n = 0;
		int sum = 0;
		while (sum < abs(targetX) + abs(targetY) || (sum - abs(targetX) - abs(targetY)) % 2 != 0)
			sum += (++n);

		int toMinus = (sum - abs(targetX) - abs(targetY)) / 2;

		int* coef = new int[n + 1];
		char* dir = new char[n + 1];
		for (int i = 0; i < n + 1; ++i)
		{
			coef[i] = 1;
			dir[i] = 'v';
		}
		
		int nn = n;
		while (toMinus > nn)
		{
			coef[nn] = -1;
			toMinus -= nn;
			nn--;
		}
		if (toMinus != 0)
			coef[toMinus] = -1;	

		int x = abs(targetX);
		nn = n;
		while (coef[nn] == -1)
			nn--;
		while (x > nn)
		{
			x -= nn;
			coef[nn] = 1;
			dir[nn] = 'h';
			nn--;
			while (coef[nn] == -1)
				nn--;
		}
		
		if (x != 0)
		{
			if (coef[x] == 1)
				dir[x] = 'h';
			else if (x == 1)
				dir[1] = dir[2] = 'h';
			else if (x == 2)
				dir[2] = dir[4] = 'h';
			else
				dir[1] = dir[x - 1] = 'h';
		}

		for (int i = 1; i <= n; ++i)
		{
			if (targetX < 0 && dir[i] == 'h')
				coef[i] *= -1;
			if (targetY < 0 && dir[i] == 'v')
				coef[i] *= -1;
		}


		cout << "Case #" << t << ": ";
		for (int i = 1; i <= n; ++i)
		{
			if (dir[i] == 'h')
				cout << (coef[i] == 1 ? 'E' : 'W');
			else
				cout << (coef[i] == 1 ? 'N' : 'S');
		}
		cout << endl;

		/*printf("Expected: %d %d\n", targetX, targetY);
		int rx = 0, ry = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (dir[i] == 'h')
				rx += i * coef[i];
			else
				ry += i * coef[i];
		}
		printf("Result  : %d %d\n", rx, ry);
		if (rx != targetX || ry != targetY)
		{
			printf("wrong!\n");
		}*/
	}
	
	return 0;
}