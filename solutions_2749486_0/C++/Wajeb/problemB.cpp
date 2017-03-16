#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <ctime>

using namespace std;

string solve(int X, int Y);
string do_x(int i, int &x, int &y, int X, int Y, bool done);
string do_y(int i, int &x, int &y, int X, int Y, bool done);
string do_x2(int x);
string do_y2(int y);

int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("problemB-small.in");
	cout.open("problemB-small-out.txt");

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++)
	{
		int X, Y;
		cin >> X >> Y;

		cout << "Case #" << t << ": " << solve(X, Y) << endl;
	}

	cin.close();
	cout.close();

	return 0;
}

string solve(int X, int Y)
{
	string s = "";
	int x = 0, y = 0;
	// E: x+1 - W: x-1 - N: y+1 - S: y-1

	for(int i = 1; i <= 500; i++)
	{
		//srand(time(0));
		//int j = rand() % 40;
		if(i % 2)
		{
			string t = do_x(i, x, y, X, Y, false);
			if(t == "") break;

			s = s + t;
		}
		else
		{
			string t = do_y(i, x, y, X, Y, false);
			if(t == "") break;

			s = s + t;
		}
	}

	if(x == X && y == Y) return s;
	else
	{
		x = 0; y = 0;
		s = "";
		for(int i = 1; i <= 500; i++)
		{
			//srand(time(0));
			//int j = rand() % 40;
			if(i % 2 == 0)
			{
				string t = do_x(i, x, y, X, Y, false);
				if(t == "") break;

				s = s + t;
			}
			else
			{
				string t = do_y(i, x, y, X, Y, false);
				if(t == "") break;

				s = s + t;
			}
		}
		if(x == X && y == Y) return s;
		else
		{
			x = 0; y = 0;
			s = "";

			if(X == 0)
			{
				return do_y2(Y);
			}
			else
			{
				return do_x2(X);
			}
		}
	}
}

string do_x(int i, int &x, int &y, int X, int Y, bool done)
{
	if(x < X)
	{
		if(x + i > X)
		{
			x = x - i;
			//cout << "x: " << x << endl;
			return "W";
		}
		else
		{
			x = x + i;
			//cout << "x: " << x << endl;
			return "E";
		}
	}
	else if(x > X)
	{
		if(x - i < X)
		{
			x = x + i;
			//cout << "x: " << x << endl;
			return "E";
		}
		else
		{
			x = x - i;
			//cout << "x: " << x << endl;
			return "W";
		}
	}
	else
	{
		if(!done) return do_y(i, x, y, X, Y, true);
		else return "";
	}
}

string do_y(int i, int &x, int &y, int X, int Y, bool done)
{
	if(y < Y)
	{
		if(y + i > Y)
		{
			y = y - i;
			//cout << "y: " << y << endl;
			return "S";
		}
		else
		{
			y = y + i;
			//cout << "y: " << y << endl;
			return "N";
		}
	}
	else if(y > Y)
	{
		if(y - i < Y)
		{
			y = y + i;
			//cout << "y: " << y << endl;
			return "N";
		}
		else
		{
			y = y - i;
			//cout << "y: " << y << endl;
			return "S";
		}
	}
	else
	{
		if(!done) return do_y(i, x, y, X, Y, true);
		else return "";
	}
}

string do_x2(int x)
{
	int now = 0;
	int index = -1;
	string s = "";
	if(x > 0)
	{
		for(int i = 1; i < 1000; i++)
		{
			now += i;
			if(now >= x)
			{
				index = i;
				if(now != x) now -= i;
				break;
			}
		}
		for(int i = 1; i < index; i++)
			s = s + "E";
		if(now == x){
			s = s + "E";
			int counter = 0;
			for(int i = 1; i <= s.length(); i++)
			{
				if(s[i-1] == 'E') counter += i;
				else counter -= i;
			}
			if(counter == x) return s;
			else return "bad";
		}
		for(int i = 0; i < x - now; i++)
			s = s + "WE";
	}
	else
	{
		for(int i = 1; i < 1000; i++)
		{
			now -= i;
			if(now <= x)
			{
				index = i;
				if(now != x) now += i;
				break;
			}
		}
		for(int i = 1; i < index; i++)
			s = s + "W";
		if(now == x){
			s = s + "W";
			int counter = 0;
			for(int i = 1; i <= s.length(); i++)
			{
				if(s[i-1] == 'E') counter += i;
				else counter -= i;
			}
			if(counter == x) return s;
			else return "bad";
			return s;
		}
		for(int i = 0; i < abs(x - now); i++)
			s = s + "EW";
	}
	int counter = 0;
	for(int i = 1; i <= s.length(); i++)
	{
		if(s[i-1] == 'E') counter += i;
		else counter -= i;
	}
	if(counter == x) return s;
	else return "bad";
}
string do_y2(int y)
{
	int now = 0;
	int index = -1;
	string s = "";
	if(y > 0)
	{
		for(int i = 1; i < 1000; i++)
		{
			now += i;
			if(now >= y)
			{
				index = i;
				if(now != y) now -= i;
				break;
			}
		}
		for(int i = 1; i < index; i++)
			s = s + "N";
		if(now == y){
			s = s + "N";
			int counter = 0;
			for(int i = 1; i <= s.length(); i++)
			{
				if(s[i-1] == 'N') counter += i;
				else counter -= i;
			}
			if(counter == y) return s;
			else return "bad";
		}
		for(int i = 0; i < y - now; i++)
			s = s + "SN";
	}
	else
	{
		for(int i = 1; i < 1000; i++)
		{
			now -= i;
			if(now <= y)
			{
				index = i;
				if(now != y) now += i;
				break;
			}
		}
		for(int i = 1; i < index; i++)
			s = s + "S";

		if(now == y){
			s = s + "S";
			int counter = 0;
			for(int i = 1; i <= s.length(); i++)
			{
				if(s[i-1] == 'N') counter += i;
				else counter -= i;
			}
			if(counter == y) return s;
			else return "bad";
		}

		for(int i = 0; i < abs(y - now); i++)
			s = s + "NS";
	}
	int counter = 0;
	for(int i = 1; i <= s.length(); i++)
	{
		if(s[i-1] == 'N') counter += i;
		else counter -= i;
	}
	if(counter == y) return s;
	else return "bad";
}
