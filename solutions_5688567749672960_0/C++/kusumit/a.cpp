#include <bits/stdc++.h>

using namespace std;

int reverse(int n)
{
  int n2 = 0;
  while (n != 0) {
    n2 *= 10;
    n2 += n % 10;
    n /= 10;
  }
  return n2;
}

int main()
{
  ios_base::sync_with_stdio(false);
  ifstream in("a.in");
  ofstream out("sol.out");
  int _c;
  in >> _c;

  for(int _cc = 1; _cc <= _c; ++_cc)	{
    out << "Case #" << _cc << ": ";

    int n, count = 0, i = 0;
    in >> n;

    while (i != n) {
      for (int j = 1; j <= 10; ++j) {
	if (j == 10 || reverse(i + j) > n) {
	  if (i + j - 1 != reverse(i + j - 1)) {
	    count += j - 1;
	    i = reverse(i + j - 1); 
	    ++count;
	  }	
	  break;
	}
      }
      if (i == 0) {
	count += min(n, 10) - i;
	i = min(n, 10);
      } else {
	count += min(n, int(pow(10, int(log10(i)) + 1))) - i;
	i = min(n, int(pow(10, int(log10(i)) + 1)));
      }
//      cout << n << ' ' << i << ' ' << count << endl;
    }
    out << count << endl;
  }

  return 0;
}

