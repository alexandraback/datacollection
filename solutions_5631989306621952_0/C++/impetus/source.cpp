#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <queue>
#include <complex>
#include <functional>
#include <sstream>
#include <tuple>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	string s;
    	cin >> s;
    	string cur = "";
    	for (int i = 0; i < s.length(); i++)
    		cur = max(cur + s[i], s[i] + cur);
    	cout << "Case #" << tc + 1 << ": " << cur << endl;
    }
    return 0;
}