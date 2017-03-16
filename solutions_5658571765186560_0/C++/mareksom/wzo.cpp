#include <cstdio>
#include <algorithm>

using namespace std;

int r, c;

int us[25][25];

const int xx[4] = {-1, 0, 1, 0};
const int yy[4] = {0, 1, 0, -1};

bool zaz[25][25];

int dfs(int x, int y)
{
	if(zaz[x][y])
		return 0;
	zaz[x][y] = true;
	int wyn = 1;
	for(int i = 0; i < 4; i++)
		wyn += dfs(x + xx[i], y + yy[i]);
	return wyn;
}

bool niszczy()
{
	for(int i = 0; i <= r + 1; i++)
		for(int j = 0; j <= c + 1; j++)
			zaz[i][j] = true;
	int x = 0;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			if(zaz[i][j] = us[i][j])
				x++;
	
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			if(dfs(i, j) % x)
				return true;
	return false;
}

bool dorzuc(int x)
{
	if(x == 0)
		return niszczy();
	
	vector< pair<int, int> > poz;

	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			if(us[i][j])
			{
				for(int s = 0; s < 4; s++)
				{
					const int x = i + xx[s];
					const int y = j + yy[s];
					if(!us[x][y])
						poz.emplace_back(x, y);
				}
			}
		}
	}

	sort(poz.begin(), poz.end());
	poz.resize(unique(poz.begin(), poz.end()) - poz.begin());

	for(auto & i : poz)
	{
		us[i.first][i.second] = true;
		if(dorzuc(x - 1))
			return true;
		us[i.first][i.second] = false;
	}
	return false;
}

bool sprawdz(int x)
{
	for(int i = 0; i <= r + 1; i++)
		for(int j = 0; j <= c + 1; j++)
			us[i][j] = true;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			us[i][j] = false;
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			us[i][j] = true;
			if(dorzuc(x - 1))
				return true;
			us[i][j] = false;
		}
	}
	return false;
}

bool przyp()
{
	int x;
	scanf("%d%d%d", &x, &r, &c);
	if(r > c)
		swap(r, c);
	if((r * c) % x)
		return true;
	if(x <= 2)
		return false;
	if(r == 1)
		return true;
	if(x == 3)
		return false;
	if(r == 2)
		return true;
	
	if(x >= 7)
		return true;
	
	return sprawdz(x);
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
		printf("Case #%d: %s\n", i, przyp() ? "RICHARD" : "GABRIEL");
	return 0;
}
