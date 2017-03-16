#include <iostream>
#include <utility>

using namespace std;

int main()
{
	int cn; cin >> cn;
	for (int cc=1; cc<=cn; cc++)
	{
		int n, x, y;
		cin >> n >> x >> y;
		if (x > y) swap(x, y);
		cout << "Case #" << cc << ": ";

		const int minx[7] = {0, 1, 1, 2, 2, 3, 3};
		if (n >= 7) goto NON_HACK;
		if (x * y % n) goto NON_HACK;
		if (x < minx[n]) goto NON_HACK;
		if (x > minx[n]) goto HACK;
		switch (n)
		{
		case 1:
		case 2:
		case 3:
			goto HACK;
		case 4:
		case 6:
			goto NON_HACK;
		case 5:
			if (y == 5) goto NON_HACK;
			goto HACK;
		default:
			break;
		}			
		
	HACK:
		cout << "GABRIEL" << endl;
		continue;
	NON_HACK:
		cout << "RICHARD" << endl;
		continue;
	}
	return 0;
}
