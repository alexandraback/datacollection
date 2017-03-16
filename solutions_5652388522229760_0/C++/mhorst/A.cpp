#include <iostream>
#include <vector>

using namespace std;

void solve(int r)
{
  long n;
  long result;
  bool digits[10];
  int nr_digits = 0;
  long i;
  
  cin >> n;
  result = n;
  
  //cout << "N = " << n << "\n";
  
  if (n != 0)
  {
    for (i = 0; i < 10; i++) digits[i] = false;

    i = 0;  
    while ((nr_digits < 10) && (result <= (1000000*n)))
    {
      long t = result;
      while (t > 0)
      {
	if (!digits[t % 10]) {
          digits[t % 10] = true;
	  nr_digits++;
	}
	t = t / 10;
      }
      result = result + n;
    }
  }

  cout << "Case #" << r << ": ";
  if (nr_digits < 10) cout << "INSOMNIA";
  else cout << (result-n);
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
