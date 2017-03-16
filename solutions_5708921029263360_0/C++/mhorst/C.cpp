#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

static int combosJP[10][10];
static int combosJS[10][10];
static int combosPS[10][10];

void solve(int r)
{
  int J, P, S, K;
  int a,b,c;
  vector<string> result;
  
  cin >> J >> P >> S >> K;

  /* Reset data */
  for (a=0; a<J; a++)
  {
    for (b=0; b<P; b++)
    {
      combosJP[a][b] = 0;
    }
    for (c=0; c<S; c++)
    {
      combosJS[a][c] = 0;
    }
  }
  for (b=0; b<P; b++)
  {
    for (c=0; c<S; c++)
    {
      combosPS[b][c] = 0;
    }
  }

  /* Try combos */
  for (a=0; a<J; a++)
  {
    for (b=0; b<P; b++)
    {
      for (c=0; (c<S) && (combosJP[a][b]<K); c++)
      {
        if ((combosJS[a][c] < K) && (combosPS[b][c] < K))
	{
	  ostringstream s;
	  combosJP[a][b]++;
	  combosJS[a][c]++;
	  combosPS[b][c]++;
	  s << (a+1) << " " << (b+1) << " " << (c+1);
	  result.push_back(s.str());
	}
      }
    }
  }


  cout << "Case #" << r << ": ";
  cout << result.size() << "\n";
  for (a=0; a < result.size(); a++)
  {
    cout << result[a] << "\n";
  }
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
