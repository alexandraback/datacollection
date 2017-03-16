/*
 * A.cpp
 *
 *  Created on: May 5, 2012
 *      Author: alexei
 */

#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

#define NMAX 1024

vector< int > G[NMAX];
int viz[NMAX];
int ans;

void df( int node, int father )
{
	if( viz[node] || ans )
		return;

	viz[node] = father;

	int i,j;
	for( i = 0; i < G[node].size(); ++i )
	{
		if( !viz[G[node][i]] )
			df( G[node][i], node );
		else
			if( G[node][i] != father )
			{
				ans = 1;
				return;
			}
	}
}


int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);

	int T;
	scanf("%d",&T);

	for( int t = 1; t <= T; ++t )
	{

		ans = 0;

		int N,count,link;

		scanf("%d",&N);

		for( int i = 1; i <=N; ++i )
		{
			G[i].clear();

			scanf("%d",&count);

			for( int j = 1; j <= count; ++j )
			{
				scanf("%d",&link);
				G[i].push_back(link);
			}
		}

		for( int i = 1; i <= N; ++i )
		{
			memset( viz, 0, sizeof(viz) );
			df(i,i);
		}

		if( !ans )
			cout << "Case #" << t << ": No\n";
		else
			cout << "Case #" << t << ": Yes\n";
	}

	return 0;
}
