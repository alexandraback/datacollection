#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;

const int N = 500;
int n;
int matrix [N][N];

int dl[N];
bool used[N];


void dfs( int _i )
{
	//if( used[_i])
		dl[_i]++;
	//else used[_i] = 1;
	for( int i = 0; i < n; i++ )
	{
		if( matrix[_i][i] == 1 )
		dfs( i );
	}
}

int main()
{
	freopen("a.txt","r",stdin); 
	freopen("output.txt","w",stdout);
	int nofcases;
	cin>>nofcases; 

	for( int nc = 1; nc <= nofcases; nc++ )
	{
		bool flag = false;
		cin>>n;
		for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
		{
			matrix[i][j] = 0;
		}
	

		for( int i = 0; i < n; i++ )
		{
			int k,a;
			cin>>k;
			for( int j = 0; j < k; j++ )
			{
				
				cin>>a;
				matrix[i][a-1] = 1;
			}
		}

		for( int k = 0; k < n; k++ )
		{
			for( int i = 0; i < n; dl[i] = 0, i++ );
			for( int i = 0; i < n; used[i] = 0, i++ );
			dfs(k);
			for( int i = 0; i < n; i++ )
			{
				if( dl[i] > 1 && i != k)
				{
					//printf("Case #%d: Yes", nc);
					flag = true;
					//break;
				}
			}
			if(flag)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		if(flag)
		{
			printf("Case #%d: Yes", nc);
		}
		else
		{
			printf("Case #%d: No", nc);
		}


		cout<<endl;
	}
	
	return 0;
}


/*
1
3
1 2
1 3
0
*/

/*
1
5
2 2 3
1 4
1 5
1 5
0
*/