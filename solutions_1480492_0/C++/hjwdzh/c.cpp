#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
char c[100];
int v[100], p[100];
char hashnode[100];
double gb_min;
int flag;
struct line
{
	double t1, t2;
	int v1, v2;
	line(double _t1, double _t2, int _pos, int _pos2)
	{
		if (_t1 < 0)
			_t1 = 0;
		t1 = _t1, t2 = _t2, v1 = _pos, v2 = _pos2;
	}
};
vector<line> lines;
char judge[50][2];

void qqsort(int l, int r)
{
	int i = l, j = r, k;
	int m = v[(i + j) / 2];
	while (i < j)
	{
		while (v[i] < m)
			i++;
		while (v[j] > m)
			j--;
		if (i <= j)
		{
			k = c[i], c[i] = c[j], c[j] = k;
			k = v[i], v[i] = v[j], v[j] = k;
			k = p[i], p[i] = p[j], p[j] = k;
			i++, j--;
		}
	}
	if (i < r)
		qqsort(i, r);
	if (j > l)
		qqsort(l, j);
}

void searchit(int depth)
{
	if (depth == lines.size())
	{
		double minnum = 1e60;
		for (int i = 0; i < depth; i++)
			for (int j = 0; j < depth; j++)
				if (lines[i].t1 < lines[j].t2 + 1e-6 && lines[i].t2 > lines[j].t1 - 1e-6 ||
					lines[i].t1 > lines[j].t2 - 1e-6 && lines[i].t2 < lines[j].t1 + 1e-6)
				{
					if (lines[i].v1 == lines[j].v1 && judge[i][0] != judge[j][0])
						minnum = min(minnum, max(lines[j].t1, lines[i].t1));
					if (lines[i].v1 == lines[j].v2 && judge[i][0] != judge[j][1])
						minnum = min(minnum, max(lines[j].t1, lines[i].t1));
					if (lines[i].v2 == lines[j].v1 && judge[i][1] != judge[j][0])
						minnum = min(minnum, max(lines[j].t1, lines[i].t1));
					if (lines[i].v2 == lines[j].v2 && judge[i][1] != judge[j][1])
						minnum = min(minnum, max(lines[j].t1, lines[i].t1));
				}
		if (minnum > 1e10)
		{
			cout << "Possible\n";
			flag = 1;
		}
		else
			gb_min = max(gb_min, minnum);
		return;
	}
	judge[depth][0] = 'L';
	judge[depth][1] = 'R';
	if (lines[depth].t1 != 0 || c[lines[depth].v1] == 'L' && c[lines[depth].v2] == 'R')
		searchit(depth + 1);
	if (flag)
		return;
	judge[depth][0] = 'R';
	judge[depth][1] = 'L';
	if (lines[depth].t1 != 0 || c[lines[depth].v1] == 'R' && c[lines[depth].v2] == 'L')
		searchit(depth + 1);
	if (flag)
		return;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int t, n, i, j;
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++)
	{
		lines.clear();
		cin >> n;
		for (i = 1; i <= n; i++)
			cin >> c[i] >> v[i] >> p[i];
		qqsort(1, n);
		gb_min = 0;
		flag = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = i + 1; j <= n; j++)
				if (p[j] < p[i] + 5)
				{
					lines.push_back(line((p[i] - p[j] - 5) / double(v[j] - v[i]), (p[i] + 5 - p[j]) / double (v[j] - v[i]), i, j));
				}
		}
		memset(judge, 0, sizeof(judge));
		memset(hashnode, 0, sizeof(hashnode));
		cout << "Case #" << t1 << ": ";
		searchit(0);
l1:
		if (!flag)
			printf("%.6lf\n", gb_min);
	}
}