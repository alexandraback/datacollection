#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

void doCase();

int main()
{
  int cases;
  cin >> cases;

  for(int c=0; c<cases; c++)
    {
      cout << "Case #" << c+1 << ": ";
      doCase();
    }
}

struct node
{
  node(int i, int j, int time) : i(i), j(j), time(time) {}
  int time;
  int i;
  int j;
  bool operator<(const node &other) const
  {
    return time > other.time;
  }
};

void doCase()
{
  int H, N, M;
  cin >> H >> N >> M;
  int *ceil = new int[N*M];
  int *floor = new int[N*M];
  int *timeten = new int[N*M];
  bool *e = new bool[N*M];
  bool *s = new bool[N*M];

  for(int i=0; i<N; i++)
    {
      for(int j=0; j<M; j++)
	{
	  int ceilh;
	  cin >> ceilh;
	  ceil[i*M + j] = ceilh;
	}
    }
  for(int i=0; i<N; i++)
    {
      for(int j=0; j<M; j++)
	{
	  int floorh;
	  cin >> floorh;
	  floor[i*M+j] = floorh;
	}
    }

  for(int i=0; i<N; i++)
    {
      for(int j=0; j<M; j++)
	{
	  if(j==M-1)
	    e[i*M+j] = false;
	  else
	    {
	      e[i*M+j] = ( ceil[i*M+j] >= 50 + floor[i*M+j+1]
			   && ceil[i*M+j+1] >= 50 + floor[i*M+j]);
	    }
	  if(i==N-1)
	    s[i*M+j] = false;
	  else
	    {
	      s[i*M+j] = ( ceil[i*M+j] >= 50 + floor[(i+1)*M+j]
			   && ceil[(i+1)*M+j] >= 50 + floor[i*M+j]);
	    }

	  timeten[i*M+j] = H+50-ceil[i*M+j];
	}
    }

  priority_queue<node> toprocess;
  toprocess.push(node(0,0,0));

  bool *visited = new bool[M*N];
  int *mintime = new int[M*N];

  for(int i=0; i<M*N; i++)
    visited[i] = false;

  while(!visited[M*N-1])
    {
      assert(!toprocess.empty());
      node n = toprocess.top();
      toprocess.pop();
      if(!visited[n.i*M+n.j])
	{
	  //	  cout << "popped " << n.i << ", " << n.j << ", " << n.time << endl;
	  visited[n.i*M + n.j] = true;
	  mintime[n.i*M + n.j] = n.time;
	  int curtime = n.time;
	  assert(curtime >= timeten[n.i*M+n.j]);
	  vector<int> moves;
	  if(e[n.i*M+n.j])
	    moves.push_back(n.i*M+n.j+1);
	  if(n.j != 0 && e[n.i*M+n.j-1])
	    moves.push_back(n.i*M+n.j-1);
	  if(s[n.i*M+n.j])
	    moves.push_back((n.i+1)*M+n.j);
	  if(n.i != 0 && e[(n.i-1)*M+n.j])
	    moves.push_back((n.i-1)*M+n.j);
	  for(int k=0; k<moves.size(); k++)
	    {
	      int accesstime = max(curtime,timeten[moves[k]]);
	      int cost = (H-accesstime-floor[n.i*M+n.j] >= 20 ? 10 : 100);
	      if(accesstime == 0)
		cost = 0;
	      int j = moves[k]%M;
	      int i = (moves[k]-j)/M;
	      //  cout << "pushing " << i << ", " << j << ", " << accesstime+cost << endl;
	      toprocess.push(node(i,j,accesstime+cost));
	    }	  
	}
      else
	assert(n.time >= mintime[n.i*M+n.j]);
    }

  cout << double(mintime[M*N-1])/10.0 << endl;

  delete[] ceil;
  delete[] floor;
  delete[] timeten;
  delete[] e;
  delete[] s;
  delete[] visited;
  delete[] mintime;
}
