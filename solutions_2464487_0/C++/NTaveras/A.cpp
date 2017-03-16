#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("outA.txt", "w", stdout);
	
	int TC;
	cin >> TC;
	
	int idx = 0;
	while(TC--)
	{
		int radius, total;
		cin >> radius >> total;
			
		int ans = 0;
		
		while(true)
		{
			int b = ( radius + 1 ) * ( radius + 1 );
			int w = radius * radius;
			
			if( total < (b - w) )
				break;
				
			radius += 2;
			total -= (b - w);
			ans++;
		}
		
		idx++;
		cout << "Case #" << idx << ": " << ans << endl;
	}
}
