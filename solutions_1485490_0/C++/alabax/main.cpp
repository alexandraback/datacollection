#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef __int64 ll;

int N, M;
ll a[100];
int at[100];
ll b[100];
int bt[100];

map<pair<ll,ll>, ll> st[100][100];

typedef map<pair<ll,ll>, ll>::iterator iter;

void dump()
{
	return;
	for (int i=0;i<N;++i)
	{
		for (int j=0;j<M;++j)
		{
			cout << '{';
			for (iter p = st[i][j].begin(); p!=st[i][j].end(); ++p)
			{
				cout << '(' << p->first.first << ',' << p->first.second << ':' << p->second << ')';
			}
			cout << "} ";
		}
		cout << endl;
	}
}

void solve()
{
	st[0][0][make_pair(a[0],b[0])] = 0;
	for (int d=0; d<N+M; ++d)
	{
		for (int o=0; o<=d; ++o)
		{
			int i=d-o;
			int j=o;
			if (i<N && i>=0 && j<M && j>=0)
			{
				for (iter p=st[i][j].begin(); p!=st[i][j].end(); ++p)
				{
					ll score;
					if (at[i] == bt[j])
						score = min(p->first.first, p->first.second);
					else
						score = 0;
						
					if (i+1 < N)
					{
						pair<ll, ll> newPair = make_pair(a[i+1], p->first.second - score);
						
						if (st[i+1][j].find(newPair) == st[i+1][j].end() ||
							st[i+1][j][newPair] < p->second + score)
						{
							st[i+1][j][newPair] = p->second + score;
						}
					}
					if (j+1 < M)
					{
						pair<ll, ll> newPair = make_pair(p->first.first - score, b[j+1]);
						
						if (st[i][j+1].find(newPair) == st[i][j+1].end() ||
							st[i][j+1][newPair] < p->second + score)
						{
							st[i][j+1][newPair] = p->second + score;
						}						
					}
				}
			}
		}
		dump();
	}
	
	ll res = st[N-1][M-1].begin()->second;
	for (iter p = st[N-1][M-1].begin(); p!=st[N-1][M-1].end(); ++p)
	{
		ll score = p->second;
		if (at[N-1] == bt[M-1]) score += min(p->first.first, p->first.second);
		if (res < score)
			res = score;
	}
	fout << res;
}

int main()
{
	int T;
	fin >> T;
	for (int i=0;i<T;++i)
	{
		fin >> N >> M;
		
		for (int k=0; k<N; ++k)
		{
			fin >> a[k] >> at[k];
		}
		for (int k=0; k<M; ++k)
		{
			fin >> b[k] >> bt[k];
		}
		
		for (int k=0;k<100;++k) for (int j=0;j<100;++j) st[k][j].clear();
		
		fout << "Case #" << i+1 << ": ";
		solve();
		fout << endl;
	}
	return 0;
}