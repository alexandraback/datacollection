#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;

int cases , Case = 1;
////////////




int main()
{	


	scanf("%d" , &cases);	
	while( cases-- )
	{			
		printf("Case #%d: " , Case++ );

		int a , b , k;
		cin >> a >> b >> k;

		int ans = 0;

		for(int i = 0; i < a; ++i)
		{
			for(int j = 0; j < b; ++j)
			{
				if( (i&j) < k )
					++ans;
			}
		}
		
		cout << ans << endl;
	}

	

	return 0;
}

