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
		int sMax ;
		string s ;
		cin >> sMax >> s ;
		int ans = 0 ;
		int sum = 0 ;
		for(int i=0;i+1<s.size();i++)
		{
			sum += s[i]-'0' ;
			if(s[i+1]!='0')
				ans = max(ans, i+1-sum) ;
		}
		cout << "Case #" << c << ": " << ans << endl ;
	}
	
	return 0 ;
}
