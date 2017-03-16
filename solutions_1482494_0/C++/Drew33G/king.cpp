#include <iostream>

using namespace std;

int calc(int r[][2], int n);
int next(int r[][2], bool g[][2], int n, int s);
bool done(bool g[][2], int n);

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int lev;
		cin >> lev;
		int req[lev][2];
		for(int j = 0; j < lev; j++)
		{
			cin >> req[j][0] >> req[j][1];
		}
		int res = calc(req, lev);
		cout << "Case #" << i << ": ";
		if(res >= 0)
		{
			cout << res << endl;
		}
		else
		{
			cout << "Too Bad" << endl;
		}
	}
}

int calc(int r[][2], int n)
{
	int star = 0, nlvl, comp, cnt = 0;
	bool game[n][2];
	for(int i = 0; i < n; i++)
	{
		game[i][0] = false;
		game[i][1] = false;
	}
	while(!done(game, n))
	{
		nlvl = next(r, game, n, star);
		if(nlvl == -1)
			return -1;
		if(nlvl >= n)
		{
			nlvl -= n;
			if(!game[nlvl][0])
			{
				star++;
				game[nlvl][0] = true;
			}
			star++;
			game[nlvl][1] = true;
		}
		else
		{
			star++;
			game[nlvl][0] = true;
		}
		cnt++;
	}
	return cnt;
}

bool done(bool g[][2], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(!(g[i][0] && g[i][1]))
			return false;
	}
	return true;
}

int next(int r[][2], bool g[][2], int n, int s)
{
	for(int i = 0; i < n; i++)
	{
		if(s >= r[i][1] && !g[i][1])
			return i+n;
	}
	int ind = -1;
	for(int i = 0; i < n; i++)
	{
		if(!g[i][0] && s >= r[i][0])
		{
			if(ind == -1 || r[i][1] > r[ind][1])
				ind = i;
		}
	}
	return ind;
}