#include <iostream>
#include <string>
using namespace std;

bool test(int x, int r, int c)
{
	if (((r*c) % x) != 0) return false;
    if (x < 3) return true;
    if (x > 6) return false;
    int a1 = r; int a2 = c;
    if (a1 > a2) {a1 = c; a2 = r;}
    switch (x)
	{
	case 3:
	    return (a1 > 1);
		break;
	case 4:
	    return (a1 > 2) && (a2 > 3);
		break;
	case 5:
		break;
	case 6:
		break;
	}
}

int main()
{
  int T; cin >> T;
  for (int ii = 0; ii<T; ii++)
  {
    int x, r, c; cin >> x >> r >> c;
	
    cout << "Case #" << ii+1 << ": " << (test(x,r,c) ? "GABRIEL" : "RICHARD") << endl;
  }
  return 0;
}
