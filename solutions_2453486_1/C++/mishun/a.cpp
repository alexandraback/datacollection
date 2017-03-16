#include <cassert>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

string status(const char f[4][4])
{
	int xs = 0, os = 0, ps = 0, ts = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			switch(f[i][j])
			{
			case 'X': xs++; break;
			case 'O': os++; break;
			case '.': ps++; break;
			case 'T': ts++; break;
			default: assert(false); break;
			}

	assert(ts == 0 || ts == 1);
	assert(xs == os || xs == (os + 1));

	bool x4 = false, o4 = false;

	for(int i = 0; i < 4; i++)
	{
		{
			bool t = true;
			for(int j = 0; j < 4; j++)
				t = t && (f[i][j] == 'X' || f[i][j] == 'T');
			x4 = x4 || t;
		}

		{
			bool t = true;
			for(int j = 0; j < 4; j++)
				t = t && (f[i][j] == 'O' || f[i][j] == 'T');
			o4 = o4 || t;
		}

		{
			bool t = true;
			for(int j = 0; j < 4; j++)
				t = t && (f[j][i] == 'X' || f[j][i] == 'T');
			x4 = x4 || t;
		}

		{
			bool t = true;
			for(int j = 0; j < 4; j++)
				t = t && (f[j][i] == 'O' || f[j][i] == 'T');
			o4 = o4 || t;
		}
	}

	{
		bool t = true;
		for(int i = 0; i < 4; i++)
			t = t && (f[i][i] == 'X' || f[i][i] == 'T');
		x4 = x4 || t;
	}

	{
		bool t = true;
		for(int i = 0; i < 4; i++)
			t = t && (f[i][i] == 'O' || f[i][i] == 'T');
		o4 = o4 || t;
	}

	{
		bool t = true;
		for(int i = 0; i < 4; i++)
			t = t && (f[i][3 - i] == 'X' || f[i][3 - i] == 'T');
		x4 = x4 || t;
	}

	{
		bool t = true;
		for(int i = 0; i < 4; i++)
			t = t && (f[i][3 - i] == 'O' || f[i][3 - i] == 'T');
		o4 = o4 || t;
	}

	assert(!(x4 && o4));
	assert(!(o4 && xs > os));

	if(x4)
		return "X won";
	else if(o4)
		return "O won";
	else if(ps == 0)
		return "Draw";
	else
		return "Game has not completed";
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t = 0;
	scanf("%i\n", &t);

	for(int tn = 1; tn <= t; tn++)
	{
		char field[4][4];

		for(int i = 0; i < 4; i++)
		{
			char buf[1024];
			scanf("%s\n", buf);

			assert(strlen(buf) == 4);
			for(int j = 0; j < 4; j++)
				field[i][j] = buf[j];
		}

		scanf("\n");

		printf("Case #%i: %s\n", tn, status(field).c_str());
	}

	return 0;
}
