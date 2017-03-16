//compiled in vc
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
// C++
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>
using namespace std;


int cases , Case = 1;


pair<int,int> input[1024];
int N;

struct State
{
	int vis;
	int level2;
	int step;
	int star;

	State()
	{
		memset(this , 0 , sizeof(State));
	}
};


int main()
{	
	scanf("%d" , &cases);

	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   

		cin >> N;
		int limit = 0;
		for(int i = 0 ; i < N; ++i)
		{
			cin >> input[i].first >> input[i].second;

			limit = max( limit , input[i].first);
			limit = max( limit , input[i].second);
		}

		//brute the motherfuck
		queue<State> q;
		int ans = -1;
		q.push(State());
		set< pair<int,int> > viss;
		while(!q.empty())
		{
			State cur = q.front(); q.pop();

			if( cur.level2 == (1<<N)-1)
			{
				if( ans == -1)
					ans = cur.step;
				else
					ans = min( ans , cur.step);
				continue;
			}
			pair<int,int> ccc = make_pair( cur.vis , cur.level2 );
			if( viss.find( ccc ) != viss.end() )
				continue;
			viss.insert( ccc );


			for(int i = 0 ; i < N; ++i)
			{
				if( cur.vis&(1<<i) )
				{
					if( cur.star >= input[i].first )
					{
						State next = cur;
						next.vis|=(1<<i);
						++next.star;
						++next.step;
						//if( next.star <= limit ) 
							q.push(next);
					}

					if( cur.star >= input[i].second )
					{
						State next = cur;
						next.vis|=(1<<i);
						next.level2|=(1<<i);
						++next.star; 
						++next.step;
						//if( next.star <= limit ) 
							q.push(next);
					}

				}
				else //no vis
				{
					if( cur.star >= input[i].first )
					{
						State next = cur;
						next.vis|=(1<<i);
						++next.star;
						++next.step;
						q.push(next);
					}

					if( cur.star >= input[i].second )
					{
						State next = cur;
						next.vis|=(1<<i);
						next.level2|=(1<<i);
						++next.star; ++next.star;
						++next.step;
						q.push(next);
					}


				}
			}


		}


		if( ans == -1 )
		{
			puts("Too Bad");
		}
		else
			printf("%d\n" , ans);

	}


	return 0;
}
