#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T;
  cin >> T;

  int R, N, M, K;
  cin >> R >> N >> M >> K;

  cout << "Case #1:" << endl;
  for (int r = 1; r <= R; ++r)
  {
    vector<int> prod(K);
    for (int k = 0; k < K; ++k)
      cin >> prod[k];

    bool found_one = false;
    for (int i = 2; i <= 5; ++i)
    {
      for (int j = 2; j <= 5; ++j)
      {
	for (int l = 2; l <= 5; ++l)
	{
	  int p = i * j * l;
	  bool impossible = false;
	  for (int k = 0; k < K; ++k)
	    if ((prod[k] != 1) && (prod[k] != i) && (prod[k] != j) && (prod[k] != l) &&
		(prod[k] != i*j) && (prod[k] != i*l) && (prod[k] != j*l) && (prod[k] != i*j*l))
	    {
	      impossible = true;
	      break;
	    }

	  if (!impossible)
	  {
	    found_one = true;
	    cout << i << j << l << endl;
	    break;
	  }
	}
	if (found_one) break;
      }
      if (found_one) break;
    }
  }
  return 0;
}
