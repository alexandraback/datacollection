#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;

//data for prob:

string inttostr(int dbl)
{
	stringstream ss;ss<<fixed<<setprecision(5);
	ss << dbl;
	string res;
	ss>>fixed>>setprecision(5);
	ss >> res;
	return res;
}
#define MID 500
int wall[1000];
int n;
struct nomad{
	int di, ni, wi, ei, si, ddi, dpi, dsi;
};
struct attack{
	int day, west, east, str;
	bool operator < (const attack & oth) const {
		if (day  < oth.day) return true;
		if (day > oth.day) return false;
		return str < oth.str;
	}
};
map<int, vector <int> > attacks_grouped_by_days;
vector<int>  days;
vector <attack> attacks;

void read()
{
	days.clear();
	memset(wall, 0, sizeof(wall));
	attacks.clear();
	attacks_grouped_by_days.clear();
	nomad buf;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> buf.di >> buf.ni >> buf.wi >> buf.ei >> buf.si >> buf.ddi >> buf.dpi >> buf.dsi;
		attack tmp;
		for (int j = 0; j < buf.ni; ++j)
		{
			tmp.day = buf.di + j * buf.ddi;
			tmp.east = buf.ei + j*buf.dpi;
			tmp.west = buf.wi + j*buf.dpi;
			tmp.str = buf.si + j * buf.dsi;
			attacks.push_back(tmp);
		}
	}
}



string solve()
{
	sort(attacks.begin(), attacks.end());
	for (int i = 0; i < (int)attacks.size(); ++i)
	{
		attacks_grouped_by_days[attacks[i].day].push_back(i);
	}
	for (map<int, vector<int> > ::const_iterator it = attacks_grouped_by_days.begin();
		it != attacks_grouped_by_days.end(); ++it)
	{
		days.push_back(it->first);
	}
	sort(days.begin(), days.end());
	int res = 0;
	for (int i = 0; i < days.size(); ++i)
	{
		int den = days[i];
		for (int j = 0; j < attacks_grouped_by_days[den].size(); ++j)
		{
			attack atk = attacks[attacks_grouped_by_days[den][j]];
			bool succ = false;
			for (int k = 2*atk.west + MID; k <= 2*atk.east + MID; ++k)
			{
				if (wall[k] < atk.str) succ = true;
			}
			if (succ) {
				res++;
			}
		}
		for (int j = 0; j < attacks_grouped_by_days[den].size(); ++j)
		{
			attack atk = attacks[attacks_grouped_by_days[den][j]];
			for (int k = 2*atk.west + MID; k <= 2*atk.east + MID; ++k)
			{
				if (wall[k] < atk.str) wall[k] = atk.str;
			}
		}
	}
	return inttostr(res);
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	//program
	int tests;
	scanf("%d\n", &tests);
	for (int CASE = 1; CASE <= tests; ++CASE)
	{
		read();
		printf("Case #%d: %s\n", CASE, solve().c_str());
	}
	//end program
	return 0;
}




