#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a,b,k;
		cin >> a >> b >> k;
		int ans = 0;
		for (int x = 0; x < a; x++)
			for (int y = 0; y < b; y++)
			{
				if ((x & y) < k)
					ans++;
			}
			printf ("Case #%d: %d\n",i + 1,ans);
	}
	return 0;
}