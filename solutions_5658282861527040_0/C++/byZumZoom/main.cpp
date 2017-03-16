#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
    
	for(int t = 1; t <= T; ++t)
	{
        int a, b, k, res = 0;
        cin >> a >> b >> k;
        for(int i = 0; i < a; ++i)
        	for(int j = 0; j < b; ++j)
        		if((i & j) < k)
        			++res;

        cout << "Case #" << t << ": " << res << endl;
	}
    
	return 0;
}
