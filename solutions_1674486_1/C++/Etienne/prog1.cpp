#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

void doCase();

int main()
{
  int cases;
  cin >> cases;
  cin.ignore();

  for(int c=0; c<cases; c++)
    {
      cout << "Case #" << c+1 << ": ";
      doCase();
    }
}

void doCase()
{
  int N;
  cin >> N;
  vector<vector<int> > inherits;
  bool *in = new bool[N];
  for(int i=0; i<N; i++)
    {
      in[i] = false;
      inherits.push_back(vector<int>());
    }
  for(int i=0; i<N; i++)
    {
      int mi;
      cin >> mi;
      for(int j=0; j<mi; j++)
	{
	  int inherit;
	  cin >> inherit;
	  inherits[i].push_back(inherit-1);
	  in[inherit-1] = true;
	}
    }
  bool *visited = new bool[N];
  for(int i=0; i<N; i++)
    {
      if(!in[i])
	{
	  for(int j=0; j<N; j++)
	    visited[j] = false;
	  queue<int> tovisit;
	  tovisit.push(i);
	  while(!tovisit.empty())
	    {
	      int cur = tovisit.front();
	      tovisit.pop();
	      if(visited[cur])
		{
		  cout << "Yes" << endl;
		  delete[] in;
		  delete[] visited;
		  return;
		}
	      visited[cur] = true;
	      for(int j=0; j<inherits[cur].size(); j++)
		{
		  tovisit.push(inherits[cur][j]);
		}
	    }
	}
    }
  delete[] in;
  delete[] visited;
  cout << "No" << endl;
  return;
}
