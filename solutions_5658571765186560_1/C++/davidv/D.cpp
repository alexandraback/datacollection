#include <iostream>
#include <algorithm>

using namespace std;

void doCase()
{
	int X, R, C;
	
	cin >> X >> R >> C;
	
	if (R > C)
		swap(R,C);
	
	if (X == 1 || (X == 2 && (R*C)%2 == 0))
	{
		cout << "GABRIEL" << endl;
		return;
	}
	
	if (X >= R+C-1 || X >= 2*min(R,C)+1 || X >= 8 || (R*C)%X != 0)
	{
		cout << "RICHARD" << endl;
		return;
	}
	
	if (X < 4 || (X == 4 && R == 3 && C == 4) ||
		X <= R+C-4)
	{
		cout << "GABRIEL" << endl;
		return;
	}
	
	cout << "RICHARD" << endl;
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int i=0; i<T; i++)
	{
		cout << "Case #" << i+1 << ": ";
		doCase();
	}
	
	return 0;
}
