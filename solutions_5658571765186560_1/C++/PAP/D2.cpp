#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		int r, c, x;
		cin >> x >> r >> c;
		if(r < c)
			swap(r, c);
		cout << "Case #" << tt << ": ";
		if(x >= 7)
			cout << "RICHARD" << endl;
		else if(x == 1)
			cout << "GABRIEL" << endl;
		else if(x == 2)
		{
			if(r * c % 2 == 0)
				cout << "GABRIEL" << endl;
			else
				cout << "RICHARD" << endl;
		}
		else if(x == 3)
		{
			if(r < 3 || c < 2 || r * c % 3 != 0)
				cout << "RICHARD" << endl;
			else
				cout << "GABRIEL" << endl;
		}
		else if(x == 4)
		{
			if(r < 4 || c < 3 || r * c % 4 != 0)
				cout << "RICHARD" << endl;
			else
				cout << "GABRIEL" << endl;
		}
		else if(x == 5)
		{
			if(r < 5 || c < 3 || r * c % 5 != 0)
				cout << "RICHARD" << endl;
			else
				cout << "GABRIEL" << endl;
		}
		else
		{
			if(r < 6 || c < 4 || r * c % 6 != 0)
				cout << "RICHARD" << endl;
			else
				cout << "GABRIEL" << endl;
		}
	}
	return 0;
}
