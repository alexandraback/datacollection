#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
using namespace std;

bool path[2001];

int main()
{
	int T, count;
	int X, Y;
	int step;
	string s;
	char shortest;

	cin >> T;
	count = T;

	while(T--)
	{
		cin >> X >> Y;
		s = "";

		int toStp = abs(X) + abs(Y);
		for(step = 1 ; step <= 2001 ; step++)
		{
			if(step * (step+1) / 2 > toStp) break;
		}

		if(abs(step * (step+1) / 2 - toStp) >= abs(step * (step-1) / 2 - toStp)) step -= 1;

		int tmp;
		if(abs(X) < abs(Y))
		{
			tmp = abs(X);
			shortest = 'X';
		}
		else
		{
			tmp = abs(Y);
			shortest = 'Y';
		}

		memset(path, 0, sizeof(path));
		for(int i = step ; i >= 1 ; i--)
		{
			if(tmp >= i)
			{
				tmp -= i;
				path[i] = true;

				if(tmp == 0) break;
			}
		}

		int dx, dy;
		int rest = (step+1) * step / 2;
		if(shortest == 'X')
		{
			dx = tmp;
			dy = toStp - rest - dx;
		}
		else
		{
			dy = tmp;
			dx = toStp - rest - dy;
		}

		for(int i = 1 ; i <= step ; i++)
		{
			if(path[i])
			{
				if(shortest == 'X')
				{
					if(X >= 0) s += "E";
					else s += "W";
				}
				else
				{
					if(Y >= 0) s += "N";
					else s += "S";
				}
			}
			else
			{
				if(shortest == 'X')
				{
					if(Y >= 0) s += "N";
					else s += "S";
				}
				else
				{
					if(X >= 0) s += "E";
					else s += "W";
				}
			}
		}

		if(dx)
		{
			if(X >= 0) 
				for(int i = 0 ; i < dx ; i++)
					s += "WE";
			else
				for(int i = 0 ; i < dx ; i++)
					s += "EW";
		}

		if(dy)
		{
			if(Y >= 0) 
				for(int i = 0 ; i < dy ; i++)
					s += "SN";
			else
				for(int i = 0 ; i < dy ; i++)
					s += "NS";
		}

		cout << "Case #" << count-T << ": " << s << endl;
	}
}