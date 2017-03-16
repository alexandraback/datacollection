// CodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

#define rep(i, b, n) for(int i=(b); i<(n); ++i)
#define repd(i, b, n) for(int i=(b); i>(n); --i)
#define trav(it, col) for(typeof((col).begin()) it = (col).begin(); it != (col).end(); ++it)
#define clr(pt) memset((pt), 0, sizeof(pt))
#define EPS 1e-8
#define IFD if(DEBUG)
#define dbg(x) DEBUG && cerr << __LINE__ << ": " << x << endl
#define DL cerr << __LINE__ << endl;
#define mp make_pair

#define DEBUG true

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef stringstream ss;

int INMODE = 0; // 0 specify cases, 1 single run, 2 indefinite runs

bool solve(int cn){
	int H,N,M;
	cin >> H >> N >> M;

	int** floor = new int*[N];
	rep(i,0,N) floor[i] = new int[M];

	int** celing = new int*[N];
	rep(i,0,N) celing[i] = new int[M];
	
	rep(i,0,N) rep(j,0,M) cin >> celing[i][j];
	rep(i,0,N) rep(j,0,M) cin >> floor[i][j];

	bool** visited = new bool*[N];
	rep(i,0,N) visited[i] = new bool[M];
	rep(i,0,N) rep(j,0,M) visited[i][j] = false;

	typedef pair<double,pii> p3;
	priority_queue<p3> q;
	q.push(p3(0,pii(0,0)));
	while(!q.empty())
	{
		p3 c = q.top(); q.pop();
		int x = c.second.first;
		int y = c.second.second;
		double t = -c.first;

		//cout << x << " " << y << " " << t << endl;

		if(visited[x][y]) continue;
		visited[x][y] = true;

		if(x == N-1 && y == M-1)
		{
			double time = c.first;
			if(time < 0) time = -time;
			cout << "Case #" << cn << ": " << time << endl;
			return 1;
		}

		rep(i,0,4)
		{
			int nx = x, ny = y;
			if(i == 0 && nx > 0) nx--;
			if(i == 1 && nx < N-1) nx++;
			if(i == 2 && ny > 0) ny--;
			if(i == 3 && ny < M-1) ny++;
			if(nx == x && ny == y) continue;

			if(floor[nx][ny] > celing[nx][ny] - 50) continue;
			if(floor[x][y] > celing[nx][ny] - 50) continue;
			if(floor[nx][ny] > celing[x][y] - 50) continue;

			double minTime = (H - (celing[nx][ny] - 50)) / 10.0;
			double time = max(t, minTime);
			double timeWaterCurrent = (H - (floor[x][y] + 20)) / 10.0;

			if(time != 0)
			{
				if(time > timeWaterCurrent + EPS) time += 10;
				else time += 1;
			}
			
			q.push(p3(-time, pii(nx,ny)));
		}
	}

	cout << "FAIL FAIL FAIL" << endl;

    return 1;
}

int main(){
    //cout << setiosflags(ios::fixed) << setprecision(10);
    int cases = 1 << 30;
    if(INMODE == 0) cin >> cases;
    if(INMODE == 1) cases = 1;
    for(int cn = 1; cn <= cases; ++cn)
        if(!solve(cn) && INMODE == 2) break;
    return 0;
}


