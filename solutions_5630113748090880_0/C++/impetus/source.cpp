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
    	int n;
    	cin >> n;
    	map<int, int> a;
    	for (int i = 0; i < n * (2 * n - 1); i++)
    	{
    		int d;
    		cin >> d;
    		a[d]++;
    	}
    	vector<int> result;
    	for (auto p : a)
    		if (p.second % 2)
    			result.push_back(p.first);
    	cout << "Case #" << tc + 1 << ": ";
        for (auto v: result)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}