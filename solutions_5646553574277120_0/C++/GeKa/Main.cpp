#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <memory.h>


using namespace std;
#define MAX 31
bool mas[MAX];
bool available[MAX];

int C, D, V;

bool ok(vector<int> & v)
{
	int N = v.size();
	int NN = 1 << N;
	bool m[MAX];
	for (int i = 0; i < MAX; i++)
		m[i] = false;
	for (int i = 0; i < NN; i++)
	{
		int s = 0;
		for (int j = 0; j < N; j++)
			if (i & (1 <<j))
			{
				s += v[j];				
			}
		if (s < MAX)
			m[s] = true;

	}
	for (int i = 1; i <= V; i++)
		if (!(mas[i] || m[i]))
			return false;
	return true;
}

int f(int pos, vector<int> & v)
{
	if (v.size() > 5)
		return 1000;
	if (ok(v))
		return 0;
	int res = 1000;
	for (int i = pos; i <= V; i++)		
	{
		v.push_back(i);
		int a = f(i+1, v);
		if (available[i])
			a++;
		res = min(res, a);
		v.pop_back();
	}
	return res;
	
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T;
	cin>>T;
	for (int t = 0; t < T; t++)
	{
		
		cin >> C >> D >> V;
		for (int i = 0; i < MAX; i++)
		{
			mas[i] = false;
			available[i] = true;
		}
		vector<int> ex;
		for (int i = 0; i < D; i++)
		{
			int a;
			cin >> a;
			ex.push_back(a);
			if (a < MAX)
				available[a] = false;
		}
		
		for (int i = 0; i < (1<<D); i++)
		{
			int s = 0;
			for (int j = 0; j < D; j++)
				if (i &(1<<j))
					s += ex[j];
			if (s < MAX)
				mas[s] = true;
		}
		vector<int> v;
		int res = f(1, v);
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}