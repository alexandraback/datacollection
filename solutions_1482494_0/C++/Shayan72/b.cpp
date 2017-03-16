#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

int main(){	
	
	int T;
	cin >> T;
		
	for (int o = 1; o <= T; o++)
	{
		int n;
		cin >> n;
		pair<int,int> ab[n];
		pair<bool,bool> check[n];
		
		for (int i = 0; i < n; i++)
		{
			check[i].first = false;
			check[i].second = false;
		}
		
		
		int t = 0;
		int stars = 0;
		
		for (int i = 0; i < n; i++)
		{
			cin >> ab[i].first >> ab[i].second;
		}
		
		sort( ab, ab+n );
		reverse( ab, ab+n );
		
		bool findSec = false;
		
		int secNum = 0;
		bool searchSec = true;
		bool searchForEmpty = true;
		
		for (int i = 0; i < n; i++)
		{
			if( secNum == n )
				break;
			
			if( searchSec )
			{
				if( check[i].second == false && ab[i].second <= stars )
				{					
					if( check[i].first == true )
						stars++;
					else
						stars += 2;
						
					check[i].first = true;
					check[i].second = true;
					
					findSec = true;
					searchForEmpty = true;
					secNum++;
					
					i=-1;
					t++;
				}
			}
			else
			{
				if( check[i].first == false && ab[i].first <= stars )
				{
					stars++;
					
					check[i].first = true;
					
					searchSec = true;
					searchForEmpty = true;
					
					i=-1;
					
					t++;
				}
			}

			if( i ==  n-1 ) {
				if( secNum == n ) break;
				
				if( !searchSec )
				{
					t = -1;
					break;
				}
				
				if( findSec ) {
					findSec = false;
					searchSec = true;
					searchForEmpty = true;
				}
				else
				{
					if( searchForEmpty )
						searchForEmpty = false;
					else
						searchSec = false;
				}
						
				i = -1;
			}
		}
		
		
		if( t == -1 )
			cout << "Case #" << o << ": Too Bad" << endl;
		else
			cout << "Case #" << o << ": " << t << endl;
	}
	
	return 0;
}

