#include <iostream>
#include <set>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <functional>
#include <sstream>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		string ans;
		if (n > 0) while (n--) ans += "WE";
		else while(n++) ans += "EW";
		if (m > 0) while (m--) ans += "SN";
		else while (m++) ans += "NS";
		cout << "Case #" << i + 1 << ": " << ans << endl;
		ans = "";
	}
	return 0;
}