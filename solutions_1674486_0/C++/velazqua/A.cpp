#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void graphSearch( vector<vector<int> > &G, vector<int> &visited, int node )
{
	int size = G[node].size();
	visited[node]++;
	REP( i, size )
	{
		graphSearch( G, visited, G[node][i] );
	}
}

int main ()
{
	int T;
	cin >> T;
	REP( i, T )
	{
		int numClasses;
		cin >> numClasses;
		vector<vector<int> > G( numClasses+1, vector<int>() );
		REP( j, numClasses )
		{
			int edges;
			cin >> edges;
			REP( k, edges )
			{
				int E;
				cin >> E;
				G[j+1].push_back( E );
			}
		}
		// do graph search
		bool found = false;
		FOR( j, 1, numClasses+1 )
		{
			vector<int> visited( numClasses+1, 0 );
			graphSearch( G, visited, j );
			//cout << "j: " << j << endl;
			FOR( k, 1, numClasses+1 )
			{
				//cout << "\tk: " << k << ". visited[k]: " << visited[k] << endl;
				if( visited[k] > 1 )
				{
					found = true;
					break;
				}
			}
			if( found ) 
				break;
		}
		cout << "Case #" << i+1 << ": ";
		if( found )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
