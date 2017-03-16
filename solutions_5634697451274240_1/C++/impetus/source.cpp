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
    	int cnt = 0;
    	for (int i = 1; i < s.length(); i++)
    		cnt += s[i] != s[i - 1];
    	cnt += s[s.length() - 1] == '-';
    	cout << "Case #" << tc + 1 << ": " << cnt << endl;
    }
    return 0;
}