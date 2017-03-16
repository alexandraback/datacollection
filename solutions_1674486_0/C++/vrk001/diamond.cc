#include <iostream>
#include <queue>
using namespace std;
int process_test()
{ int gives[1001][1001] = {{0}};
  int bases[1001] = {0}, base_count = 0;
  int m, n, i, j, k;
  cin >> n;
  for ( i = 1 ; i <= n ; ++i )
  { cin >> m;
    if ( !m )
      bases[ base_count++ ] = i;
    for ( j = 0 ; j < m ; ++j )
    {
      cin >> k;
      gives[k][ ++gives[k][0] ] = i;
    }
  }
  for ( i = 0 ; i < base_count ; ++i )
  { int visited[1001] = {0};
    queue<int> q;
    q.push( bases[i] );
    while ( q.size() )
    { j = q.front();
      q.pop();
      if ( visited[j] )
        return 1;
      visited[j] = 1;
      for ( k = 1 ; k <= gives[j][0] ; ++k )
        q.push( gives[j][k] );
    }
  }
  return 0;
}
  
int main()
{ int t;
  cin >> t;
  for ( int i = 1 ; i <= t ; ++i )
  { if ( process_test() )
    { cout << "Case #" << i << ": Yes" << endl;
    }
    else
    { cout << "Case #" << i << ": No" << endl;
    }
  }
}
