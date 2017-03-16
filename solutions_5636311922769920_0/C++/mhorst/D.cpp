#include <iostream>
#include <vector>

using namespace std;

void solve(int r)
{
  int K, C, S;
  int i;
  
  cin >> K >> C >> S;
  
  cout << "Case #" << r << ":";
  
  /* The expansion tree has paths of length C that do a logical OR of
   * whether there is gold on one of the nodes on that path.
   * A path can have min(C,K) unique nodes */
  if (min(C,K)*S >= K)
  {
    int nr = 0; /* Nr measured nodes */
    int max_nodes = min(C,K);
    
    while (nr < K)
    {
      long long idx = 1;
      int l;
      cout << " ";
      
      for (l = 0; l < C; l++)
      {
        idx = (K*(idx-1))+1;
	if ((l < max_nodes) && (nr < K))
	{
	  idx = idx + nr;
	  nr++;
	}
      }
      cout << idx;
      
    }
  } else {
      cout << " IMPOSSIBLE";
  }
  
  cout << "\n";

}

int main (void)
{
	int runs=0;
	int r = 1;
	
	cin >> runs;
	while (r <= runs)
	{
	  solve(r);
	  r++;
	}
	return 0;
}
