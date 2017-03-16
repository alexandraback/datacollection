#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>

using namespace std;
int i , j,  k , n , ans;
int A , B , K;
int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);

	int test;
	cin>>test;
	for (int t = 1; t <= test; t++)
	{
		
		cout<<"Case #"<<t<<": ";
		cin>>A>>B>>K;
		int ans = 0;
		for (i = 0; i < A; i++)
			for (j = 0 ;j < B; j++)
			{
				if ((i & j) < K)
				{
					ans++;
				}
			}

		cout<<ans<<endl;

	}
	return 0;
}