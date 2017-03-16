#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define MM(a , x) memset(a , x , sizeof(a))
#define sqr(x) ((x) * (x))
#define abs(x) ((x > 0) ? (x) : -(x))
#define REP(i , n) for ((i) = 0; (i) < (n); ++(i))
#define FOR(i , a , b) for ((i) = (a); (i) <= (b); ++(i))
#define FORD(i , a , b) for ((i) = (a); (i) >= (b); --(i))
typedef long long LL;

const double precision = 1e-6;

inline int cmp(const double& x)
{
	return ((x < -precision) ? -1 : (x > precision));
}

struct Tdata
{
	double pos , v;
	bool operator <(const Tdata& data) const
	{
		return cmp(pos - data.pos) < 0;
	}
};

int n , testcase , T;
double ans;
vector<Tdata> lane[2];
bool can;

void init()
{
	lane[0].clear(); lane[1].clear();
	cin >> n;
	int i;
	string st;
	Tdata data;
	FOR (i , 1 , n)
	{
		cin >> st;
		cin >> data.v >> data.pos;
		if (st[0] == 'L') lane[0].push_back(data); else lane[1].push_back(data);
	}
	sort(lane[0].begin() , lane[0].end());
	sort(lane[1].begin() , lane[1].end());
	/*
	printf("L\n");
	REP (i , lane[0].size()) printf("%.6lf %.6lf\n" , lane[0][i].v , lane[0][i].pos);
	printf("R\n");
	REP (i , lane[1].size()) printf("%.6lf %.6lf\n" , lane[1][i].v , lane[1][i].pos);
	*/
}

void dfs(int depth , double t , vector<Tdata>* lane)
{
	vector<Tdata> new_lane[2];
	int i , j , k , min_car , min_lane;
	double min_t;
	if (can) return;
	if (depth > 1000)
	{
		ans = max(ans , t);
		return;
	}
	bool flag = 1;
	REP (k , 2) FOR (i , 0 , (int)lane[k].size() - 2)
	{
		if (cmp(lane[k][i].v - lane[k][i + 1].v) > 0)
		{
			flag = 0;
			break;
		}
	}
	if (flag) can = 1;
	if (can) return;
	min_t = 1e20;
	double tmp_t;
	REP (k , 2) FOR (i , 0 , (int)lane[k].size() - 2)
	{
		if (cmp(lane[k][i].v - lane[k][i + 1].v) <= 0) continue;
		tmp_t = (lane[k][i + 1].pos - lane[k][i].pos - 5) / (lane[k][i].v - lane[k][i + 1].v);
		if (cmp(tmp_t - min_t) < 0)
		{
			min_t = tmp_t;
			min_lane = k;
			min_car = i;
		}
	}
	if (cmp(min_t) == 0)
	{
		depth++;
	}
	REP (k , 2) REP (i , lane[k].size()) lane[k][i].pos += lane[k][i].v * min_t;
	//car i change lane
	flag = 1;
	double p1 = lane[min_lane][min_car].pos - 5.0 , p2 = lane[min_lane][min_car].pos + 5.0;
	REP (i , lane[1 - min_lane].size())
	{
		if (cmp(lane[1 - min_lane][i].pos - p1) > 0 && cmp(lane[1 - min_lane][i].pos - p2) < 0)
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		new_lane[0].clear(); new_lane[1].clear();
		REP (k , 2)
		{
			REP (i , lane[k].size())
			{
				if (i == min_car)
				{
					if (k == min_lane) new_lane[1 - k].push_back(lane[k][i]);
					else new_lane[k].push_back(lane[k][i]);
					continue;
				}
				new_lane[k].push_back(lane[k][i]);
			}
		}
		REP (k , 2) sort(new_lane[k].begin() , new_lane[k].end());
		dfs(depth , t + min_t , new_lane);
	}
	else
	{
	//car i + 1 change lane
		flag = 1;
		p1 = lane[min_lane][min_car + 1].pos - 5.0 , p2 = lane[min_lane][min_car + 1].pos + 5.0;
		REP (i , lane[1 - min_lane].size())
		{
			if (cmp(lane[1 - min_lane][i].pos - p1) > 0 && cmp(lane[1 - min_lane][i].pos - p2) < 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			new_lane[0].clear(); new_lane[1].clear();
			REP (k , 2)
			{
				REP (i , lane[k].size())
				{
					if (i == min_car + 1)
					{
						if (k == min_lane) new_lane[1 - k].push_back(lane[k][i]);
						else new_lane[k].push_back(lane[k][i]);
						continue;
					}
					new_lane[k].push_back(lane[k][i]);
				}
			}
			REP (k , 2) sort(new_lane[k].begin() , new_lane[k].end());
			dfs(depth , t + min_t , new_lane);
		}
		else
		{
			ans = max(ans , t + min_t);
			return;
		}
	}
}

void work()
{
	printf("Case #%d: " , T);
	/*
	if (n <= 2)
	{
		printf("Possible\n");
		return;
	}
	*/
	ans = 0.0; can = 0;
	dfs(0 , 0.0 , lane);
	if (can) printf("Possible\n"); else printf("%.6lf\n" , ans);
}

int main()
{
	freopen("c.in" , "r" , stdin);
	freopen("c.out" , "w" , stdout);
	cin >> testcase;
	FOR (T , 1 , testcase)
	{
		init();
		work();
	}
	return 0;
}
