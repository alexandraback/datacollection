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
    	long long n, nn;
    	cin >> nn;
    	n = nn;
    	cout << "Case #" << tc + 1 << ": ";
    	if (n)
    	{
    		set<int> used;
    		while (1)
    		{
    			int cur = n;
    			while (cur)
    			{
    				used.insert(cur % 10);
    				cur /= 10;
    			}
    			if (used.size() == 10)
    				break;
    			n += nn;
    		}
    		cout << n;
    	}
    	else
    		cout << "INSOMNIA";
    	cout << endl;
    }
    return 0;
}