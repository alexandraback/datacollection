/*
 	Team Proof
	IIT Delhi
 
	C++ Template
 */


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair

int totalCases, testNum;
int M, N, H;
int C[105][105];
int F[105][105];

double t;
set <pair <int, pair <int, int> > > visit;

int dx[] = {	1, -1, 0, 0		};

int dy[] = {	0, 0, 1, -1		};

bool isVert(int i, int j)
{
	return (i >= 0 && j >= 0 && i < M && j < N && C[i][j] >= F[i][j]+50);
}

void preprocess()
{
	
}

bool input()
{
	s(H);
	s(M);
	s(N);
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			s(C[i][j]);
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			s(F[i][j]);
	return true;
}

int soln()
{
	set <pair<int, pair <int, int> > > dijk;
	dijk.insert(mp(0, mp(0, 0)));
	visit.clear();
	//visit.insert(mp(0, mp(0,0)));
	
	while(!dijk.empty())
	{
		pair <int, pair<int, int> > arg = *dijk.begin();
		visit.insert(arg);
		
		dijk.erase(dijk.begin());
		int curt;
		int curx, cury;
		
		curt = arg.first;
		curx = arg.second.first;
		cury = arg.second.second;
		
		if(curx == M-1 && cury == N-1)
			return curt;
		
		//printf("%d %d %d\n", curt, curx, cury);
		
		int nx, ny;
		for(int dir = 0; dir < 4; dir++)
		{
			nx = curx + dx[dir];
			ny = cury + dy[dir];
			
			if(!isVert(nx, ny))
				continue;
			//immediate?
			int h = H-curt;
			if(F[curx][cury] > C[nx][ny] - 50)
				continue;
			if(F[nx][ny] > C[curx][cury] - 50)
				continue;
			
			pair<int, pair<int, int> > narg;
			
			if(h <= C[nx][ny]-50)
			{
				if(curt > 0)
				{
					if(h >= F[curx][cury] + 20)
						narg = (mp(curt+10, mp(nx, ny)));
					else 
						narg = (mp(curt+100, mp(nx, ny)));
				}
				else 
				{
					narg = (mp(curt, mp(nx, ny)));
				}
			}
			else 
			{
				int nt = H - (C[nx][ny]-50);
				narg = (mp(nt, mp(curx, cury)));
			}
			
			if(visit.find(narg) == visit.end())
				dijk.insert(narg);
		}
	}
}

void solve()
{
	printf("Case #%d: %lf\n", testNum, soln()/10.0);
}

int main()
{
	preprocess();
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		solve();
	}
}
