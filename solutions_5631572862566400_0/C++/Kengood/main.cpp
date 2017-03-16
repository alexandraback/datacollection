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




int main(int aN, char **aG)
{	
	int Case, cases = 0;
	scanf("%d" , &Case);
	while (Case--)	
	{
		int n;
		cin >> n;

		vector<int> to(n);
		vector<int> from(n);

		vector<int> dumb;
		for (int i = 0 ; i < n; ++i)
		{
			cin >> to[i];
			to[i]--;
			from[ to[i] ]  = i;

			dumb.push_back(i);
		}

		printf("Case #%d: " , ++cases );


        int ans = 1;
		do
		{
			for (int k = 2; k <= n; ++k)
			{
				vector<bool> ok(k);
				int nnn = 0;
				for (int i = 0; i < k; ++i)
				{
					int here = dumb[i];
					int back  = dumb[ (k+(i-1)) %k];
					int fw = dumb[(i+1)%k];
					if ( to[here] == back || to[here] == fw)
					{
						ok[i] = true;
						++nnn;
					}
				}

				if (nnn == k)
				{
					ans = max(ans, k);
					/*if ( ans == k)
					{
						for (int i = 0; i < k; ++i)
							cout << dumb[i] << " ";
						cout << endl;
					}*/
				}

			}


		}while( ::next_permutation(dumb.begin(), dumb.end()) );
		//puts("-----------");
		cout << ans << endl;
	}

	return 0;
}

