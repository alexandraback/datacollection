#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	//~ freopen("A-small-attempt1.in","r",stdin);
	//~ freopen("c.out","w",stdout);
	
	int T; cin >> T;
	
	for(int t = 1; t <= T; t++)
	{
		int x;
		
		int m; string s;
		
		cin >> m >> s;
		
		int mins = 1, sum = 1;
		
		for(int i = 1; i <= m; i++)
		{
			sum += 1 - (s[i] - '0');
			
			mins = max(mins, sum);
		}
		
		
		if(mins <= s[0] - '0') x = 0;
		
		else x = mins - (s[0] - '0');
		
		printf("Case #%d: %d\n",t,x);
		
	}
	
	return 0;
	
	
}
