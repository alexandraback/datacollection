#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
#define MOD 1000000007

void solve(int x, int y, int i, int j)
{
	if(x != i){
		if(x > i){
			cout << "WE";
			solve(x, y, i+1, j);
		}
		else{
			// x < i
			cout << "EW";
			solve(x, y, i-1, j);
		}
	}
	else if(y != j){
		if(y > j){
			cout << "SN";
			solve(x, y, i, j+1);
		}
		else{
			// y < j
			cout << "NS";
			solve(x, y, i, j-1);
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	freopen("B-small-attempt3.in","r",stdin);
	freopen("output.txt","w",stdout);

	int t, x, y, k;
	cin >> t;

	for(k=1; k<=t; ++k)
	{
		cin >> x >> y;

		cout << "Case #" << k << ": ";
		solve(x, y, 0, 0);
		cout << endl;
	}

	return 0;
} 