#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef long long ll;

typedef pair<int, int> Pll;

int main(void)
{

	ifstream cin("A-small-attempt0.in");//m.txt
	ofstream cout("A_small");

	int T;
	cin >> T;

	forn(i, T)
	{
		int R, C, W;
		cin >> R >> C >> W;

		int cp = C / W;
		int num;
		if (C-W*cp>0) num = cp*R + W;
		else num = cp*R + W-1;
		cout << "Case #" << i + 1 << ": " << num << endl;
	}
	return 0;
}