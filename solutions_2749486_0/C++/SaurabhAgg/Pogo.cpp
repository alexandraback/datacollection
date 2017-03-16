#include<iostream>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	
	int X, Y;
	
	for(int t = 1; t <= cases; t++)
	{
		cin >> X >> Y;
		cout << "Case #" << t << ": ";
		if(X > 0)
		{
			for(int i = 0; i < X; i++)
				cout << "WE";
		}
		else
		{
			X *= -1;
			for(int i = 0; i < X; i++)
				cout << "EW";
		}
		
		if(Y > 0)
		{
			for(int i = 0; i < Y; i++)
				cout << "SN";
		}
		else
		{
			Y *= -1;
			for(int i = 0; i < Y; i++)
				cout << "NS";
		}
		cout << endl;
	}
	
	return 0;
}
