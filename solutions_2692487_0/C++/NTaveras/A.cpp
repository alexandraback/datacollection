#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long llong;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("ou.txt", "w", stdout);
	
	int tc;
	cin >> tc;
	
	for(int i = 1; i <= tc; ++i)
	{
		llong cur, n;
		cin >> cur >> n;
		
		llong arr[n];
		for(int j = 0; j < n; ++j)
			cin >> arr[j];
		sort(arr, arr+n);
		llong ret = 1e12;
		
		for(int k = n; k >= 0; k--)
		{
			// Quitando hasta k
			llong need = 0;
			llong curmote = cur;
			int j = 0;
			
			while( j < k )
			{
				if( curmote > arr[j] ) 
				{
					curmote += arr[j];
					j++;
				}
				else if( curmote + (curmote-1) == curmote )
				{
					need = 1e12;
					break;
				}
				else
				{
					curmote += (curmote - 1);
					need++;
				}
			}
			ret = min(ret, need + (n-k));
		}
		
		cout << "Case #" << i << ": " << ret << endl;
	}
	return 0;
}
