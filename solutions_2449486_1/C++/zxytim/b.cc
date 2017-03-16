/*
 * $File: b.cc
 * $Date: Sat Apr 13 12:15:39 2013 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <cstdio>
#include <cstring>

struct Entity
{
	int x, y;
	int dx, dy;
	int same;
	int num;
};

const int N = 200;
int board[N][N];
int n, m;
Entity entity[N * 2];
Entity create_entity(int x, int y, int dx, int dy)
{
	Entity ret;
	ret.x = x;
	ret.y = y;
	ret.dx = dx;
	ret.dy = dy;
	int max_nm = (n > m ? n : m);
	int c0 = board[x][y];
	for (int i = 1; i < max_nm; i ++)
	{
		int tx = x + dx * i,
			ty = y + dy * i;
		if (!(tx >= 0 && tx < n && ty >= 0 && ty < m))
			break;
		int c1 = board[tx][ty];
		if (c0 == 0)
		{
			if (c1 == 0)
				continue;
			c0 = c1;
			continue;
		}

		// c0 != 0
		if (!(c0 == c1 || c1 == 0))
		{
			ret.same = false;
			ret.num = 0;
			return ret;
		}
	}
	ret.same = true;
	ret.num = c0;
	return ret;
}

bool hash[N * 2];
int find_entity_same(Entity *entity, int n_entity)
{
	int num = 1000;
	int ret = -1;
	for (int i = 0; i < n_entity; i ++)
	{
		if (hash[i])
			continue;
		Entity e = entity[i];
		if (e.same == true)
		{
			if (e.num < num)
				num = e.num, ret = i;
		}
	}
	return ret;
}

int get_min_num()
{
	int num = 10000;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (board[i][j] != 0)
				if (board[i][j] < num)
					num = board[i][j];
	if (num == 10000)
		return 0;
	return num;
}

void cover(Entity e)
{
	int max_nm = (n > m ? n : m);
	for (int i = 0; i < max_nm; i ++)
	{
		int tx = e.x + e.dx * i,
			ty = e.y + e.dy * i;
		if (!(tx >= 0 && tx < n && ty >= 0 && ty < m))
			break;
		board[tx][ty] = 0;
	}
}

void solve()
{
	scanf("%d%d", &n, &m);
	memset(hash, 0, sizeof(hash));
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			scanf("%d", &board[i][j]);
	int n_remain = n + m;
	while (n_remain)
	{
		int n_entity = 0;
		for (int i = 0; i < n; i ++)
			entity[n_entity ++] = create_entity(i, 0, 0, 1);
		for (int i = 0; i < m; i ++)
			entity[n_entity ++] = create_entity(0, i, 1, 0);
		int id = find_entity_same(entity, n_entity);
		int min_num = get_min_num();
		if (id == -1 || (entity[id].num != min_num))
		{
			printf("NO\n");
			return;
		}
		n_remain --;
		hash[id] = true;
		cover(entity[id]);
	}
	printf("YES\n");
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int i = 1; i <= ncase; i ++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}


/**
 * vim: syntax=cpp11 foldmethod=marker
 */

