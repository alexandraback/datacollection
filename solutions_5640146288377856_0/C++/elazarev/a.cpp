#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int r,c,w;
void solve()
{
	cin >> r >> c >> w;
	cout << c/w + w - (c % w == 0) << endl;
}

int main()
{
	int t;
//	freopen("input.txt", "r", stdin);	
//	freopen("output.txt", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
}