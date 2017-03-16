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

#define IN_THE_SET(_set,_val) (_set.find(_val) != _set.end())

int cases , Case = 1;
////////////

struct Item
{
	long long val;
	int idx;
}item[2][128];

int n , m;
long long ans;

void dfs(int curA, long long A, int curB , long long B , long long done)
{
	if( curA == n || curB == m)
	{
		ans = max(done, ans);
		return;
	}

	if( item[0][curA].idx == item[1][curB].idx )
	{
		long long good = min( A , B);
		done += good;
		A-=good;
		B-=good;
	}
	if( B)
	dfs( curA+1 , item[0][curA+1].val , curB , B , done);

	if(A)
	dfs( curA , A , curB+1 , item[1][curB+1].val  , done);

	dfs( curA+1 , item[0][curA+1].val , curB+1, item[1][curB+1].val  , done);
}

int main()
{	
	scanf("%d" , &cases);

	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   

		cin >> n >> m;

		for(int i = 0 ; i < n; ++i)
		{
			cin >> item[0][i].val;
			cin >> item[0][i].idx;
		}

		for(int i = 0 ; i < m; ++i)
		{
			cin >> item[1][i].val;
			cin >> item[1][i].idx;
		}

		ans = 0;
		dfs( 0 , item[0][0].val , 0 , item[1][0].val , 0);

		cout << ans << endl;
	}


	return 0;
}
