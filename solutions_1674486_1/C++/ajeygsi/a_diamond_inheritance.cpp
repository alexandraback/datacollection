#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cfloat>
#include <climits>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define INF 1000000007
#define EPS (1e-8)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
typedef long long LL;

using namespace std;


void dfs( vector< vector<int > >& tree , set<int>& seen_nodes , stack<int>& dfs_stack ,bool& found )
{
  int curr = dfs_stack.top();
  
  for(int j = 0;j < tree[curr-1].size() ;j++ )
    {
      if( seen_nodes.count( tree[curr-1][j] ) > 0 )
	{
	  found = true;
	  return;
	}

      dfs_stack.push( tree[curr-1][j] );
      seen_nodes.insert( tree[curr-1][j] );
      
      dfs( tree , seen_nodes, dfs_stack , found );
      dfs_stack.pop();
    }
}
      


main()
{
  int tests;
  scanf("%d",&tests);

  int num_classes;  
  for(int tc = 1; tc <= tests ;tc++)
    {
      scanf("%d",&num_classes);

      vector<vector<int> > tree( num_classes );
      
      int tmp1;
      int num_parents;
      vector<int> num_children(num_classes);
      for(int i = 0;i < num_classes;i++)
	{
	  scanf("%d",&num_parents);
	  
	  for(int j = 0;j < num_parents;j++)
	    {
	      scanf("%d",&tmp1);
	      num_children[tmp1-1]++;
	      tree[i].pb(tmp1);
	    }

	}

      bool found = false;
      for(int i = 0;i < num_classes;i++)
	{
	  if( num_children[i] == 0 )
	    {
	      // Start a dfs.
	      set<int> seen_nodes;
	      stack<int> dfs_stack;
	      seen_nodes.insert(i+1);
	      dfs_stack.push(i+1);
	      dfs( tree , seen_nodes, dfs_stack , found );
	      
	      if( found )
		{
		  break;
		}
	    }
	}

      if( found )
	{
	  printf("Case #%d: Yes\n",tc);
	}
      else
	{
	  printf("Case #%d: No\n",tc);
	}
    }
}
