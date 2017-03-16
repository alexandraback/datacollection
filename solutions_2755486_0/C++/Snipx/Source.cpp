# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <math.h>
# include <algorithm>
# include <string.h>
# include <stack>
# include <queue>
# include <sstream>
# include <set>
# include <map>
# include <assert.h>
using namespace std;

const int maxn = 1111;
int di[maxn];
int ni[maxn];
int wi[maxn], ei[maxn];
int si[maxn];
int delta_d[maxn];
int delta_p[maxn];
int delta_s[maxn];

struct attack
{
	int w;
	int e;
	int s;
};

int main()
{
    //ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
	
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++)
	{
		int N;
		cin >> N;
		map<int, vector<attack> > attacks;
		set<int> days;
		for (int i  =0; i < N; i++)
		{
			cin >> di[i] >> ni[i] >> wi[i] >> ei[i] >> si[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
			for (int j = 0; j < ni[i]; j++)
			{
				int day = di[i] + j * delta_d[i];
				days.insert(day);
				int west = wi[i] + delta_p[i] * j;
				int east = ei[i] + delta_p[i] * j;
				int strength = si[i] + delta_s[i] * j;
				attack curAttack;
				curAttack.w = west;
				curAttack.e = east;
				curAttack.s = strength;
				attacks[day].push_back(curAttack);
			}
		}
		int ans = 0;
		map<int, int> wall;
		for (set<int>::iterator it = days.begin(); it != days.end(); it++)
		{
			int day = (*it);
			for (int i = 0; i < attacks[day].size(); i++)
			{
				bool succeed = false;
				attack curAttack = attacks[day][i];
				for (int j = curAttack.w; j < curAttack.e; j++)
					if (wall[j] < curAttack.s)
						succeed = true;
				if (succeed)
					ans++;
			}

			// update wall;
			for (int i = 0; i < attacks[day].size(); i++)
			{
				attack curAttack = attacks[day][i];
				for (int j = curAttack.w; j < curAttack.e; j++)
					wall[j] = max(wall[j], curAttack.s);
			}
		}
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
    
    //system("pause");
    return 0;
}
