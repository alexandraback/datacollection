#include <iostream>
#include <string>
#include <algorithm>

using namespace std ;

int main(void)
{
	int tc ;
	cin >> tc ;
	
	for(int c=1;c<=tc;c++)
	{
		int n ;
		cin >> n ;
		
		int cakes[1100] ;
		int maxCake = 0 ;
		for(int i=0;i<n;i++)
		{
			cin >> cakes[i] ;
			maxCake = max(maxCake, cakes[i]) ;
		}
			
		int ans = maxCake ;
		for(int eatTimes=1;eatTimes<maxCake && eatTimes<ans;eatTimes++)
		{
			int swapTimes = 0 ;
			for(int i=0;i<n;i++)
				swapTimes += (cakes[i]-1)/eatTimes ;
			ans = min(ans, eatTimes+swapTimes) ;
		}
		
		cout << "Case #" << c << ": " << ans << endl ;
	}
	
	return 0 ;
}
