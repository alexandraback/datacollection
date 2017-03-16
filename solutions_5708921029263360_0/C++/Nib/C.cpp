#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void)
{
	vector<vector<vector<vector<int>>>> memo(4, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(12, -1))));

	int t;
	scanf("%d", &t);
	for(int tt = 1;tt <= t;tt++) {
	int J, P, S, K;
	scanf("%d%d%d%d", &J, &P, &S, &K);
	vector<vector<int>> poss;
	for(int i = 0;i < J;i++)
	{
		for(int j = 0;j < P;j++)
		{
			for(int k = 0;k < S;k++)
			{
				poss.push_back({i, j, k});
			}
		}
	}

	int inf = 170;
	int mask = 0, res = 0, v = 0;

	for(mask = 0;mask < inf;mask++)
	{
		bool done = true;
		vector<vector<int>> cur;
		for(int i = 0;i < int(poss.size());i++)
		{
			if(mask&(1<<i))
			{
				cur.push_back(poss[i]);
			}
		}

		vector<vector<int>> A(J+1, vector<int>(P+1)), B(P+1, vector<int>(S+1)), C(J+1, vector<int>(S+1));

		for(int i = 0;i < int(cur.size());i++)
		{
			A[cur[i][0]][cur[i][1]]++;
			B[cur[i][1]][cur[i][2]]++;
			C[cur[i][0]][cur[i][2]]++;
			if(A[cur[i][0]][cur[i][1]] > K) done = false;
			if(B[cur[i][1]][cur[i][2]] > K) done = false;
			if(C[cur[i][0]][cur[i][2]] > K) done = false;
		}
		if(done)
		{
			res = max(res, int(cur.size()));
			if(res == int(cur.size())) v = mask;
		}
	
	}
	printf("%d\n", res);
	for(int i = 0;i < int(poss.size());i++)
	{
		if(v&(1<<i))
		{
			printf("%d %d %d\n", poss[i][0]+1, poss[i][1]+1, poss[i][2]+1);
		}
	} }
}