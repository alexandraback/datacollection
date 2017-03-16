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


struct BruteMF
{
	pair<int,int> now;
	int step;
	string path;
};


int main()
{	
	

	scanf("%d" , &cases);	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   

		int X , Y;
		cin >> X >> Y;
		pair<int,int> endIt = make_pair(X,Y);

		BruteMF cur;
		cur.now.first = 0;
		cur.now.second = 0;
		cur.step  = 0 ;

		queue<BruteMF> q;
		q.push(cur);
		set< pair< int, pair<int,int> > > vis;
		while(!q.empty())
		{
			cur = q.front(); q.pop();
			pair< int, pair<int,int> > aaa = make_pair( cur.step , cur.now) ;
			if( vis.find( aaa ) != vis.end() )
				continue;
			if( cur.step > 500 ) continue;
			vis.insert( aaa );

			if( cur.now == endIt)
			{
				cout << cur.path << endl; break;
			}

			// north (increasing y), south (decreasing y), east (increasing x) or west (decreasing x). 

			BruteMF next = cur;
			++next.step;
			next.now.second += next.step;
			next.path.push_back('N');
			q.push(next);
			

			next = cur;
			++next.step;
			next.now.second -= next.step;
			next.path.push_back('S');
			q.push(next);

			next = cur;
			++next.step;
			next.now.first += next.step;
			next.path.push_back('E');
			q.push(next);

			next = cur;
			++next.step;
			next.now.first -= next.step;
			next.path.push_back('W');
			q.push(next);
			

		}
		
		
		
	}


	return 0;
}
