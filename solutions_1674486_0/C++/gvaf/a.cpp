#include <iostream>
#include <stack>
using namespace std;

int diagram[1001][11];

bool solve(int N);

int main()
{
  int T;

  cin >> T;

  for(int ti = 0; ti < T; ++ti)
    {
      int N;

      cin >> N;
      
      for(int ni = 1; ni <= N; ++ni)
	{
	  int M;
	  cin >> M;

	  diagram[ni][0] = M;

	  for(int i = 1; i <= M; ++i)
	    {
	      cin >> diagram[ni][i];
	    }
	}

      bool result = solve(N);
      cout << "Case #" << (ti+1) << ": " 
	   << (result ? "Yes" : "No") << endl;
    }

  return 0;
}

bool hasDiamond(int cm)
{
  bool parent[2000] = {false};
  stack<int> check;

  const int M = diagram[cm][0];
  for(int i = 1; i <= M; ++i)
    {
      int p = diagram[cm][i];
      check.push(p);
      parent[p] = true;
    }

  while( !check.empty() )
    {
      int gp = check.top();
      check.pop();

      const int M = diagram[gp][0];
      for(int i = 1; i <= M; ++i)
	{
	  int p = diagram[gp][i];

	  if( parent[p] )
	    return true;
	  else
	    {
	      check.push(p);	  
	      parent[p] = true;
	    }
	}      
    }
  
  return false;
}

bool solve(int N)
{
  for(int i = 1; i <= N; ++i)
    {
      if( hasDiamond(i) )
	return true;
    }

  return false;
}
