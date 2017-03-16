#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <string.h>
#include <numeric>
using namespace std;

 typedef vector<int> vi; 
 typedef vector<vi> vvi; 
 typedef pair<int,int> ii; 
 typedef long long ll;
 #define sz(a) int((a).size()) 
 #define pb push_back 
 #define all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 

int grid[55][55];

int main ()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int TC;
	cin >> TC;
	int CC = 1;
	while (TC--)
	{
		printf("Case #%d: ",CC++);
		ll B,M;
		cin >> B >> M;
		if (M > (1LL<<(B-2)))
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		else
		{
			cout << "POSSIBLE" << endl;
			memset(grid,0,sizeof grid);
			
			for (int i=0 ; i<B-1 ; i++)
			{
				for (int j=i+1 ; j<B ; j++)
					grid[i][j] = 1;
			}
			
			
			ll edges_to_remove = (1LL<<(B-2)) - M;
			for (ll i=3, j = 1; i<=B ; i++, j++)
			{
				if (edges_to_remove >= (1LL<<(B-i)))
				{
					grid[0][j] = 0;
					edges_to_remove -= (1LL<<(B-i));
				}
			}
			
			for (int i=0 ; i<B ; i++)
			{
				for (int j=0 ; j<B ; j++)
					cout << grid[i][j];
				cout << endl;
			}
		}
			
	}
	
}
