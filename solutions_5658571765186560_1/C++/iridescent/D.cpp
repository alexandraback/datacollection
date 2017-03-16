#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		int X, R, C;
		cin >> X >> R >> C;
		if(R > C) swap(R, C);
		bool ans = true;
		if((R * C) % X) ans = false;
		if(X == 3)
		{
			if(R <= 1 || C < 3) ans = false;
		}
		if(X == 4)
		{
			if(R <= 1 || C < 4 || R == 2) ans = false;
		}
		if(X == 5)
		{
			if(R <= 2 || C < 5 || (R == 3 && C == 5)) ans = false;
		}
		if(X == 6)
		{
			if(R <= 2 || C < 6 || R == 3) ans = false;
		}
		if(X >= 7) ans = false;
		printf("Case #%d: ", i);
		cout << (ans ? "GABRIEL" : "RICHARD") << endl;
	}
}
