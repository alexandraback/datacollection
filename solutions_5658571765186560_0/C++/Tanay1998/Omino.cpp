#include <bits/stdc++.h>

using namespace std;

int X, R, C;

bool bigger(int x, int y)
{
	if (R >= x && C >= y)
		return true;
	if (C >= x && R >= y)
		return true;
	return false;
}

bool solve()
{
	if (X > 6)
		return false;
	if (X > (R * C))
		return false;
	if ((R * C) % X > 0)
		return false;
	if (X == 1 || X == 2)	// (X == 2 and odd cells Covered in previous case)
		return true;
	if (X == 3)				// Covered for 3.
	{
		 if (bigger(2, 2))
			return true;
		return false;
	}
	if (X == 4)
	{
		if (!bigger(3, 3))	// (2, 3) is for the L piece, and (3, 3) because any 2 row one can fail.
			return false;
		return true;		// True all other times. 
	}
		
	if (X == 5 && !bigger(3, 3))
		return false;
	if (X == 6 && !bigger(3, 4))
		return false;
	return true;
}


int main()
{
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int T;
	cin >> T;	
	for (int t = 1; t <= T; t++)
	{
		cin >> X >> R >> C;
		if (solve())
			printf("Case #%d: GABRIEL\n", t);
		else
			printf("Case #%d: RICHARD\n", t);
	}
}
