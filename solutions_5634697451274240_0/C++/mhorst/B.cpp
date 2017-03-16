#include <iostream>
#include <vector>

using namespace std;

void solve(int r)
{
  int result = 0;
  string l;
  int idx;
  char c;
  
  cin >> l;
  
  /* Count number of transitions */
  idx = l.size()-1;
  c = '+';
  while (idx >= 0)
  {
    if (l[idx] != c)
    {
      result++;
      c = l[idx];
    }
    idx--;
  }
  
  cout << "Case #" << r << ": ";
  cout << result;
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
