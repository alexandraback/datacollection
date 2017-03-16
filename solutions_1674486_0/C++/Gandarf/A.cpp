#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define N 1005

int h, i, j, test;
int n, m, k, x, si, so, cnt;
int deg[N], check[N], t;
vector<int> a[N], in, out;
queue<int> Q;

bool hh();
void process(int p, int d);

int main()
{
	//FILE *fp1 = fopen("input.txt", "r");
	FILE *fp1 = fopen("A-small-attempt2.in", "r");
	FILE *fp2 = fopen("output.txt", "w");

	fscanf(fp1, "%d", &test);
	for(h = 1; h <= test; h++)
	{
		// init
		for(i = 0; i < N; i++)
		{
			deg[i] = check[i] = 0;
			a[i].clear();
		}
		cnt = 0;
		in.clear();
		out.clear();
		
		// input
		fscanf(fp1, "%d", &n);
		for(i = 1; i <= n; i++)
		{
			fscanf(fp1, "%d", &m);
			if(m > 1)
				out.push_back(i);
			for(j = 1; j <= m; j++)
			{
				fscanf(fp1, "%d", &k);
				a[i].push_back(k);
				deg[k]++;
				//outdeg[i]++;
				if(deg[k] >= 2)
					in.push_back(k);
			}
		}

		if(hh())
			fprintf(fp2, "Case #%d: Yes\n", h);
		else
			fprintf(fp2, "Case #%d: No\n", h);

		// output
	}

	fcloseall();
	return 0;
}

bool hh()
{
	si = in.size();
	so = out.size();
	for(i = 0; i < so; i++)
	{
		for(j = 0; j < si; j++)
		{
			cnt = 0;
			process(out[i], in[j]);
			if(cnt >= 2)
				return true;
		}
	}
	return false;
}

void process(int p, int d)
{
	if(p == d)
	{
		cnt++;
		return;
	}

	int j;
	for(j = 0; j < a[p].size(); j++)
	{
		process(a[p][j], d);
		if(cnt >= 2)
			return;
	}
}

/*
bool process(int d)
{
	Q.push(out[i]);
	while(!Q.empty())
	{
		x = Q.front();
		Q.pop();
		t = a[x].size();
		for(k = 0; k < t; k++)
		{
			Q.push(a[x][k]);
			if(check[a[x][k]] > 0)
				return true;
			check[a[x][k]]++;
		}
	}
	return false;
}*/
/*
bool process()
{
	for(i = 1; i <= n; i++)
	{
		if(deg[i] == 0)
		{
			Q.push(i);
			while(!Q.empty())
			{
				x = Q.front();
				Q.pop();
				s = a[x].size();
				for(j = 0; j < s; j++)
				{
					if(check[a[x][j]] > 0)
						return true;
					check[a[x][j]]++;
					Q.push(a[x][j]);
				}
			}
		}		
		for(i = 1; i <= n; i++)
			check[i] = 0;
	}
	return false;
}*/