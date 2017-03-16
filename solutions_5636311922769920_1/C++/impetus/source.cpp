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
    	int k, c, s;
    	cin >> k >> c >> s;
    	if (k > c * s)
    		cout << "Case #" << tc + 1 << ": IMPOSSIBLE" << endl;
    	else
    	{
    		set<long long> result;
    		for (int i = 0; i < s; i++)
    		{
    			long long cur = 0;
    			long long d = 1;
    			for (int j = 0; j < c; j++)
    			{
    				cur += (i * c + j) % k * d;
    				d *= k;
    			}
    			result.insert(cur);
    		}
    		cout << "Case #" << tc + 1 << ": ";
    		for (auto t : result)
    			cout << t + 1 << " ";
    		cout << endl;
    	}
    }
    return 0;
}
