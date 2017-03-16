#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <utility>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	for(int q = 1;q <=t;q++)
	{
		int a,b,k;
		cin >> a >> b >> k;
		int ans=0;
		if (a>b) swap(a,b);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
			{
				int y = i&j;
				if (y<k && y >=0) 
				{
				
						ans++;
				}
				
			}
		cout << "Case #" << q << ": " << ans << endl;
	}
	return 0;
}