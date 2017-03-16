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
	vector<bool> vis;
	vector<bool> level2;
	int step;
	int star;

	State()
	{
		step = 0; star = 0;
		vis.resize(N);
		level2.resize(N);
	}
};


void testcase()
{
	cout << 1 << endl;
	cout << 1000 << endl;
	int n = 1000;
	while( n-- )
	{
		cout << 0 << " " << 2001 << endl;
	}
}

char fin(vector<bool>& a)
{
	for(int i = 0 ; i < N; ++i)
		if( !a[i]) return 0;
	return 1;
}

pair<int,int> secondOnly[1024];;
int main()
{	
	//testcase();
	scanf("%d" , &cases);

	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   

		cin >> N;
		int limit = 99999;
		for(int i = 0 ; i < N; ++i)
		{
			cin >> input[i].first >> input[i].second;

			limit = min( limit , input[i].first);
			limit = min( limit , input[i].second);

			secondOnly[i].first = input[i].second;
			secondOnly[i].second = i;
		}
		if( limit != 0 )
		{
			puts("Too Bad"); continue;
		}

		//brute the motherfuck
		queue<State> q;
		int ans = INT_MAX;

		
		for(int i = 0 ; i < N; ++i)
		{
			if( input[i].second == 0 )
			{
				State cur;
				cur.level2[i] = 1;
				cur.vis[i] = 1;
				++cur.star; ++cur.star;
				++cur.step;
				q.push( cur );
			}
			else if( input[i].first == 0 )
			{
				State cur;
				cur.vis[i] = 1;
				++cur.star; 
				++cur.step;
				q.push( cur );
			}
		}

		sort(secondOnly , secondOnly +N);
		while( !q.empty() )
		{
			State cur = q.front(); q.pop();
			int t = cur.step;
			int star = cur.star;
			for(int i = 0 ; i <N; ++i)
			{
				if( cur.level2[i] )
				{
				}
				else
				{
					int need = secondOnly[i].first - star;
					if( need > 0 )
					{
						t+=need;
						star += need;
					}
					++t;
					star+=2;
				}

			}


			ans = min(t , ans);
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
