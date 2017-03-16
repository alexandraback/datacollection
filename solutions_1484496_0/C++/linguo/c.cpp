#include <iostream>
using namespace std;

std::pair<int, int> x[50];
int N;

void read()
{
  char c[20];
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
    scanf("%s %d %d\n", c, &x[i].first, &x[i].second);
}

int main()
{
  int k; scanf("%d", &k);
  for (int j = 1; j <= k; ++j)
    {
      read();
      for (int i = 0; i < N; ++i)
	x[i].second = -x[i].second;
      sort(x, x+N);
      for (int v = 0; v < N; ++v)
	for (int w = 0; w < N; ++w)
	  for (int z = 0; z < N; ++z)
	    {
	      if ((x[v].second < x[w].second) && (x[w].second < x[z].second))
		{
		  if (x[v].first != x[z].first)
		    {
		      double t = (x[z].second + 5 - x[v].second) / (x[z].first - x[v].first);
		    }
		}
	    }
    }
}
