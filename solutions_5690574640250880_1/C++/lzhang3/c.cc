#include <iostream>

#include <cstdio>
#include <cstdlib>

#include <vector>
#include <algorithm>

#include <queue>
#include <cassert>

using namespace std;

struct Pos {
	int i, j;
	Pos(int ii = 0, int jj = 0): i(ii), j(jj) {}
	Pos operator+(const Pos &p) const 
	{
		return Pos(i + p.i, j + p.j);
	}
};

Pos dir[] = {
	{-1,  0},
	{ 0,  1},
	{ 1,  0},
	{ 0, -1},
	{-1,  1},
	{ 1,  1},
	{ 1, -1},
	{-1, -1}
};

int r, c, m; 
int ci, cj;

inline bool check(const Pos &p, const int r, const int c)
{
	return (0 <= p.i && p.i < r && 0 <= p.j && p.j < c);
}

void tryit(vector<vector<char> > &conf, int k)
{
	queue<Pos> q; q.push(Pos(ci, cj)); conf[ci][cj] = 'c';
	int left = r * c - m - 1;
	while (!q.empty() && left)
	{
		Pos u = q.front(); q.pop();
		int breakflag = 0;
		for (int i = 0; i < k; ++i)
		{
			Pos v  = u + dir[i];
			if (check(v, r, c) && conf[v.i][v.j] == '*')
			{
				conf[v.i][v.j] = '.';
				if (--left == 0)
				{
					breakflag = 1;
					break;
				}
				q.push(v);
			}
		}
		if (breakflag)
			break;
	}
}

bool TEST(vector<vector<char> > &conf)//, vector<vector<int> > &w)
{
	int cnt = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (conf[i][j] == '*') ++cnt;
	if (cnt != m)
		return 0;


	vector<vector<int> > z(r, vector<int>(c, 0));
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			if (conf[i][j] == '*') 
				z[i][j] = 1;
			Pos u(i, j);
			for (int k = 0; k < 8; ++k)
			{
				Pos v = u + dir[k];
				if (check(v, r, c) && conf[v.i][v.j] == '*')
				{
					++z[i][j];
				}
			}
		}

	
	queue<Pos> q; q.push(Pos(ci, cj));
	vector<vector<int> > used(r, vector<int>(c));
	used[ci][cj] = 1;
	cnt = 1;
	while (!q.empty())
	{
		Pos u = q.front();  q.pop();
		if (z[u.i][u.j] > 0) continue;
		for (int i = 0; i < 8; ++i)
		{
			Pos v = u + dir[i];
			if (check(v, r, c) && !used[v.i][v.j])
			{
				used[v.i][v.j] = 1;
				++cnt;
				if (z[v.i][v.j] == 0)
					q.push(v);
			}
		}
	}
	return (cnt == c * r - m);
}


// bool testit(vector<vector<char> > &conf)//, vector<vector<int> > &w)
// {
// 	int cnt = 0;
// 	for (int i = 0; i < r; ++i)
// 		for (int j = 0; j < c; ++j)
// 			if (conf[i][j] == '*') ++cnt;
// 	if (cnt != m)
// 		return 0;


// 	vector<vector<int> > z(r, vector<int>(c, 0));
// 	for (int i = 0; i < r; ++i)
// 		for (int j = 0; j < c; ++j)
// 		{
// 			if (conf[i][j] == '*') continue;
// 			Pos u(i, j);
// 			for (int k = 0; k < 8; ++k)
// 			{
// 				Pos v = u + dir[k];
// 				if (check(v, r, c) && conf[v.i][v.j] == '*')
// 				{
// 					++z[i][j];
// 				}
// 			}
// 		}


// 	bool fail = 0;

// 	for (int i = 0; i < r; ++i)
// 		for (int j = 0; j < c; ++j)
// 		{
// 			if (conf[i][j] == '*' || z[i][j] == 0) continue;
// 			Pos u(i, j);
// 			int flag = 0;
// 			for (int k = 0; k < 8; ++k)
// 			{
// 				Pos v = u + dir[k];
// 				if (check(v, r, c) && (conf[v.i][v.j] != '*' && z[v.i][v.j] == 0))
// 				{
// 					flag = 1;
// 					break;
// 				}
// 			}
// 			if (!flag) 
// 			{
// 				//conf[i][j] = '@';
// 				fail = 1;
// 			}
// 		}
// 	//w.swap(z);

// 	if (r * c - m == 1)
// 		return 1;
// 	return !fail;
// }


void vfill(vector<vector<char> > &conf)
{
	conf[0][0] = 'c';
	int left = r * c - m - 1; 
	for (int j = 0; j < c; ++j)
		for (int i = 0; i < r; ++i)
		{
			if (left && conf[i][j] == '*')
			{
				conf[i][j] = '.';
				--left;
			}
		}
}


void hfill(vector<vector<char> > &conf)
{
	conf[0][0] = 'c';
	int left = r * c - m - 1; 
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			if (left && conf[i][j] == '*')
			{
				conf[i][j] = '.';
				--left;
			}
		}
}



void print_conf(vector<vector<char> > &conf)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			cout << conf[i][j];
		cout << endl;
	}
}

bool bf_solver(vector<vector<char> > &conf, int k, int n)
{
	if (k == r * c) {
		if (TEST(conf)) {
			print_conf(conf);
			return 1;
		}
		return 0;
	}

	if (r * c - k < m - n || n > m)
		return 0;

	int ir = k / c;
	int ic = k % c;
	if (conf[ir][ic] == 'c')
		return bf_solver(conf, k + 1, n);

	conf[ir][ic] = '.';
	if (bf_solver(conf, k + 1, n)) 
		return 1;
	conf[ir][ic] = '*';
	return bf_solver(conf, k + 1, n + 1);
}

void solve()
{
	scanf("%d%d%d", &r,&c,&m);
	vector<vector<char> > seed(r, vector<char>(c, '*')), conf;
	vector<vector<int> > z;
	int flag = 0;

	for (int i = 0; i < (r+1)/2; ++i)
	{
		int breakflag = 0;
		for (int j = 0 ; j < (c+1)/2; ++j)
		{
			conf = seed;
			tryit(conf, 4);
			if (TEST(conf))
			{
				flag = breakflag =  1;
				break;
			}
			conf = seed;
			tryit(conf, 8);
			if (TEST(conf))
			{
				flag = breakflag = 1;
				break;
			}
		}
		if (breakflag)
			break;
	}

	ci = cj = 0;
	conf = seed;
	vfill(conf);
	if (TEST(conf))
	{
		flag = 1;
	}
	else
	{
		conf = seed;
		hfill(conf);
		flag = (flag || TEST(conf));
	}

	// for (int i = 0; i < r; ++i)
	// {
	// 	int breakflag = 0;
	// 	for (int j = 0; j < c; ++j)
	// 	{
	// 		conf = seed;
	// 		conf[i][j] = 'c';
	// 		ci = i;
	// 		cj = j;
	// 		if (bf_solver(conf, 0, 0))
	// 		{
	// 			flag = 1;
	// 			breakflag = 1;
	// 			break;
	// 		}
	// 	}
	// 	if (breakflag)
	// 		break;
	// }


	if (!flag)
	{
		cout << "Impossible" << endl;
		return;
	}
	print_conf(conf);
	// int cnt = 0;
	// for (int i = 0; i < r; ++i)
	// {
	// 	for (int j = 0; j < c; ++j)
	// 	{
	// 		//if (conf[i][j] != '*' && conf[i][j] != '@') cout << z[i][j];
	// 		//else cout << conf[i][j];
	// 		if (conf[i][j] == '*')
	// 			++cnt;
	// 		cout << conf[i][j];
	// 	}
	// 	cout << endl;
	// }
	// assert(cnt == m);
}

int main(void)
{
	int t;  scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		printf("Case #%d:\n", i);
		solve();
	}
}