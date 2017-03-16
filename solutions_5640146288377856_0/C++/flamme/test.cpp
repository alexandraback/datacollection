#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
using namespace std;



int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int r, c, w;
		cin >> r >> c >> w;
		int result = 0;
		result = result + r * (c - 1) / w + w;
		cout << "Case #" << tt << ": " << result << endl;
	}
	return 0;
}