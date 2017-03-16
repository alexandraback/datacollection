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

string in[32];
int n , m;
char g[32][32];

char f[32][32];

string ans , t , tmp;

int path[32];

int vvv[32];
void dfs(int cur, int lv, int vis, char needed, int track )
{
	if(needed)
		path[lv++] = cur;
	if( vis == n )
	{
		tmp.clear(); 
		
		int idd = 0;
		for(int i = 0 ; i < lv; ++i)
		{	
			tmp += in[ path[i]-1 ] ;
		}
		if( t.empty() )
			t = tmp;
		else
			t = min(t,tmp);
		return;
	}
	if( track >=1000 ) return;

	++vvv[cur];
	for(int i = 1 ; i <= n; ++i)
	{
		if( g[cur][i] && f[cur][i] != 1 && vvv[i] < 256 )
		{
			if( f[i][cur] == 0 )
			{
				f[cur][i] = 1;
				f[i][cur] = 2;
			}
			
			dfs( i , lv , vis+(!vvv[i]) , !vvv[i] , track+1 );

			if( f[i][cur] == 2 )
			{
				f[cur][i] = 0;
				f[i][cur] = 0;
			}

		}
	}
//	--vvv[cur];

}

int main()
{	


	scanf("%d" , &cases);	
	while( cases-- )
	{			
		printf("Case #%d: " , Case++ );


		cin >> n >> m;

		for(int i = 0 ; i < n; ++i)
			cin >> in[i];
	//	sort(in,in+n);

		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		for(int i = 0; i < m; ++i)
		{
			int s , t;
			cin >> s >> t;
			g[s][t] = g[t][s] = 1;
		}

		ans = string();
		for(int i = 1 ; i <= n; ++i)
		{
			memset(vvv,0,sizeof(vvv));
			t.clear();
			dfs(i,0 , 1 , 1 , 0);
			if( ans.empty() )
				ans = t;
			else
				ans = min(ans,t);
		}

		cout << ans << endl;
	}

	

	return 0;
}

