#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char a[4][4];

void check(vector <char> c, bool &xwin, bool &owin)
{
	sort(c.begin(), c.end());
	string s = "";
	for (int i = 0; i < c.size(); i++)
		s += c[i];
	
	xwin |= (s == "XXXX" || s == "TXXX");
	owin |= (s == "OOOO" || s == "OOOT");
}

int main()
{
	ifstream cin ("input.txt");
	ofstream cout("output.txt");

	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		bool fill = true, xwin = false, owin = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == '.')
					fill = false;
			}
		
			
		vector <char> c(4);
		for (int i = 0; i < 4; i++)
		{
			// -
			for (int j = 0; j < 4; j++)
				c[j] = a[i][j];
			check(c, xwin, owin);

			// |
			for (int j = 0; j < 4; j++)
				c[j] = a[j][i];
			check(c, xwin, owin);
		}
		
		for (int i = 0; i < 4; i++)
			c[i] = a[i][i];
		check(c, xwin, owin);
		
		for (int i = 0; i < 4; i++)
			c[i] = a[i][3 - i];
		check(c, xwin, owin);

		cout << "Case #" << test + 1 << ": ";
		if (xwin)
			cout << "X won";
		else if (owin)
			cout << "O won";
		else if (fill)
			cout << "Draw";
		else
			cout << "Game has not completed";
		cout << endl;
	}
}