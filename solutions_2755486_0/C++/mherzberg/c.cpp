#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

const int OFFSET = 210000000;

using namespace std;

struct tribe
{
	int d;
	int n;
	int w, e;
	int s;
	int delta_d;
	int delta_p;
	int delta_s;
};

struct attack
{
	int w, e, h;
};

int wall[420000000];

bool doesSucceed(int w, int e, int s)
{
	for (int i = w * 2; i <= e * 2; ++i)
	{
		if (wall[i + OFFSET] < s) return true;
	}
	
	return false;
}

void higherWall(vector<attack> & attacks)
{
	for (auto it = attacks.begin(); it != attacks.end(); ++it)
	{
		for (int i = it->w * 2; i <= it->e * 2; ++i)
		{
			wall[i + OFFSET] = max(wall[i + OFFSET], it->h);
		}
	}
}

int main()
{
	int cases;
	cin >> cases;
	
	for (int i = 1; i <= cases; ++i)
	{
		int nrTribes;
		cin >> nrTribes;
		
		vector<tribe> tribes;
		int maxDay = 0;
		for (int t = 0; t < nrTribes; ++t)
		{
			tribe tr;
			cin >> tr.d >> tr.n >> tr.w >> tr.e >> tr.s >> tr.delta_d >> tr.delta_p >> tr.delta_s;
			maxDay = max(maxDay, tr.d + (tr.n - 1) * tr.delta_d);
			
			tribes.push_back(tr);
		}
		
		memset(wall, 0, 420000000 * sizeof(int));
		int successfulAttacks = 0;
		
		for (int day = 0; day <= maxDay; ++day)
		{
			vector<attack> attacks;
			
			for (auto it = tribes.begin(); it != tribes.end(); ++it)
			{
				if (it->d <= day && (day - it->d) % it->delta_d == 0 && day <= it->d + (it->n - 1) * it->delta_d)
				{
					if (doesSucceed(it->w, it->e, it->s))
					{
						++successfulAttacks;
						
						attack at;
						at.w = it->w; at.e = it->e; at.h = it->s;
						attacks.push_back(at);
					}
					
					it->w += it->delta_p;
					it->e += it->delta_p;
					it->s += it->delta_s;
				}
			}
			
			higherWall(attacks);
		}
		
		cout << "Case #" << i << ": " << successfulAttacks << endl;
		
	}
	
	return 0;
}
