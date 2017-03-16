#pragma comment(linker, "/STACK:300000000")
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <set>
#include <math.h>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#pragma warning(disable : 4996)

using namespace std;
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007ull
#define INF 999999999

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int X, R, C;
		cin >> X >> R >> C;
		if (R > C)
			swap(R, C);
		if (X == 1)
			cout << "Case #" << t + 1 << ": GABRIEL" << endl;
		else
		if (X == 2)
		if (R * C % 2)
			cout << "Case #" << t + 1 << ": RICHARD" << endl;
		else
			cout << "Case #" << t + 1 << ": GABRIEL" << endl;
		else
		if (X == 3)
		if (R == 1 || R * C % 3)
			cout << "Case #" << t + 1 << ": RICHARD" << endl;
		else
			cout << "Case #" << t + 1 << ": GABRIEL" << endl;
		else
		if (X == 4)
		if (R < 3 || R * C % 4)
			cout << "Case #" << t + 1 << ": RICHARD" << endl;
		else
			cout << "Case #" << t + 1 << ": GABRIEL" << endl;
		else
		if (X == 5)
		if (R < 3 || (R == 3 && C == 5) || R * C % 5 )
			cout << "Case #" << t + 1 << ": RICHARD" << endl;
		else
			cout << "Case #" << t + 1 << ": GABRIEL" << endl;
		else
		if (X == 6)
		if (R < 4)
			cout << "Case #" << t + 1 << ": RICHARD" << endl;
		else
			cout << "Case #" << t + 1 << ": GABRIEL" << endl;
		else
			cout << "Case #" << t + 1 << ": RICHARD" << endl;
	}
	//system("PAUSE");
	return 0;
}