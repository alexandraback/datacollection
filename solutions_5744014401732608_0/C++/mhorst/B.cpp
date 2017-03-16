#include <iostream>
#include <vector>

using namespace std;

static int matrix[50][50];

void solve(int r)
{
  int B;
  long long M;
  long long p;
  int i,j;
  
  cin >> B >> M;
  
  p = 1;
  for (i = 0; i < (B-2); i++) p = p*2;
  
  if (M <= p)
  {
    /* Possible */
    if (p == M)
    {
      for (i = 1; i < B; i++) matrix[0][i] = 1;
    } else {
      p = M;
      i = B-1;
      while (i > 0)
      {
	if ((p%2) == 1) matrix[0][i] = 1;
	else matrix[0][i] = 0;
	p = p / 2;
	if (i == (B-1)) {
          i--;
          matrix[0][i] = 0;
	}
	i--;
      }
    }
    
    cout << "Case #" << r << ": POSSIBLE\n";
    // Print solution
    for (i = 0; i < B; i++)
    {
      for (j = 0; j < B; j++)
      {
        cout << matrix[i][j];
      }
      cout << "\n";
    }
  } else {
    /* Impossible */
    cout << "Case #" << r << ": IMPOSSIBLE\n";
  }
}

int main (void)
{
  int runs=0;
  int r = 1;
  int i,j;

  /* Reset matrix */
  for (i = 0; i < 50; i++)
  {
    for (j = 0; j < 50; j++)
    {
      if (j>i) matrix[i][j] = 1;
      else matrix[i][j] = 0;
    }
  }


  cin >> runs;
  while (r <= runs)
  {
    solve(r);
    r++;
  }
  return 0;
}
