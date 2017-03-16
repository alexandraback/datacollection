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
using namespace std;

int cases , Case = 1;
////////////

char vv[128];

char input[1000000+10];

char noway(char *a,int n)
{
	int cur = 0;
	for(int i = 0 ; a[i]; ++i)
	{
		if( vv[ a[i]] )
			cur = 0;
		else
			cur++;
		if( cur >= n ) return 1;
	}
	return cur >=n ;
}
int main()
{	
	vv['a'] = 1;vv['e'] = 1;vv['i'] = 1;vv['o'] = 1;vv['u'] = 1;

	scanf("%d" , &cases);	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   

		int n;
		cin >> input >> n;

		int ans = 0;
		int cur = 0;
		int len = strlen(input);

		for(int i = 0 ; i < len; ++i)
		{
			for(int j = i ; j < len; ++j)
			{
				char t = input[j+1];
				input[j+1]=0;
				if( noway(input+i,n) )
					++ans;

				input[j+1] = t;
			}
		}

		
		
		cout << ans << endl;
	}


	return 0;
}
