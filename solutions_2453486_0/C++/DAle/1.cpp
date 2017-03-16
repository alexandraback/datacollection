#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

#define for if (0) ; else for

bool owin = false;
bool xwin = false;

void check(string s)
{
	int o = count(s.begin(), s.end(), 'O');
	int x = count(s.begin(), s.end(), 'X');
	if (x == 4 || x == 3 && s.find('T') != -1)
		xwin = true;
	if (o == 4 || o == 3 && s.find('T') != -1)
		owin = true;
}


int main()
{
	ifstream ifs("1.in");
	ofstream ofs("1.out");

	int t;
	ifs >> t;

	for (int test = 0; test < t; ++test)
	{
		owin = false;
		xwin = false;
		string a[4];
		bool dot = false;
		for (int i  = 0; i < 4; ++i)
		{
			ifs >> a[i];
			check(a[i]);
			if (a[i].find('.') != -1) dot = true;
		}
		for (int i = 0; i < 4; ++i)
		{
			string t;
			for (int j = 0; j < 4; ++j)
				t += a[j][i];
			check(t);
		}
		string t;
		for (int i = 0; i < 4; ++i)
		{
			t += a[i][i];
		}
		check(t);
		t = "";
		for (int i = 0; i < 4; ++i)
		{
			t += a[i][3-i];
		}
		check(t);
		ofs << "Case #" << test+1 << ": ";
		if (xwin)
			ofs << "X won\n";
		if (owin)
			ofs << "O won\n";
		if (dot && !xwin && !owin)
			ofs << "Game has not completed\n";
		if (!dot && !xwin && !owin)
			ofs << "Draw\n";
	}
	
	return 0;
}