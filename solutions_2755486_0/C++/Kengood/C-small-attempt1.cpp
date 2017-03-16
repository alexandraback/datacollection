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

int cases , Case = 1;
////////////


struct Tr
{
	int d;
	int n;
	int w ,e;
	int s;
	int dd;
	int dp;
	int ds;

	int nextDay;
	int moved;
}tr[100];;


int main()
{	
	

	scanf("%d" , &cases);	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   
		
		//memset( tr , 0 , sizeof(tr));
		int n; cin >> n;
		set<int> days;
		for(int i = 0; i < n; ++i)
		{
			cin >> tr[i].d
				>> tr[i].n
				>> tr[i].w >>tr[i].e
				>> tr[i].s
				>> tr[i].dd
				>> tr[i].dp
				>> tr[i].ds;

			tr[i].nextDay = tr[i].d;
			tr[i].moved = 0;

			for(int j = 0 ; j < tr[i].n; ++j)
			{
				days.insert( tr[i].d + j*tr[i].dd);
			}
		}

		char done = 0;

		int ans = 0;
		int day = 0;

		unordered_map<int,int> wall;
		for(auto daysIter = days.begin(); daysIter!=days.end(); ++daysIter)
		{
			unordered_map<int,int> wall2 = wall;

			done = 1;
			for(int i = 0; i < n; ++i)
			{
				if( tr[i].moved < tr[i].n )
					done = 0;

				if( *daysIter == tr[i].nextDay )
				{
					if( tr[i].s > 0 )
					{
						char shit = 0;
						for(int d = tr[i].w*2; d <= tr[i].e*2; ++d)
						{
							if( wall[d] < tr[i].s)
							{
								if( wall2[d] < tr[i].s )
									wall2[d] = tr[i].s;
								shit = 1;
							}
						}
						
						if(shit)++ans;
					}


					++tr[i].moved;
					if( tr[i].moved < tr[i].n )
					{
						tr[i].nextDay += tr[i].dd;
						tr[i].w +=  tr[i].dp;
						tr[i].e +=  tr[i].dp;
						tr[i].s +=  tr[i].ds;

					}
					else
					{
						tr[i].nextDay = -1;
					}
				}
				
			}


			wall = wall2;
			++day;
		}
		
		
		cout << ans << endl;
	}


	return 0;
}
