
#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <utility>
#include <functional>

using namespace std;

#define forl(i,a,b) for(int i = a; i < b; ++i)

int main()
{
	int numCases;
	cin >> numCases;
	forl(i,1,numCases+1)
	{
		int64_t a,b,k;
		cin >> a >> b >> k;
		int64_t ans = 0;
		forl(i,0,a)
			forl(j,0,b)
			{
				if ((i & j) < k) ans++;
			}

		cout << "Case #" << i << ": " << ans << endl;
	}
}
