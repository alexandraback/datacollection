#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T, count;
	int X, Y;
	string s;

	cin >> T;
	count = T;

	while(T--)
	{
		cin >> X >> Y;
		s = "";

		if(X > 0)
		{
			for(int i = 0 ; i < X ; i++)
				s += "WE";
		}
		else if(X < 0)
		{
			for(int i = 0 ; i < -X ; i++)
				s += "EW";
		}
		else {}

		if(Y > 0)
		{
			for(int i = 0 ; i < Y ; i++)
				s += "SN";
		}
		else if(Y < 0)
		{
			for(int i = 0 ; i < -Y ; i++)
				s += "NS";
		}
		else {}

		cout << "Case #" << count-T << ": " << s << endl;
	}
}