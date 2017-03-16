#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

const int MAXN = 25;
bool map[MAXN][MAXN];
bool visited[MAXN][MAXN];

int minamount[MAXN][MAXN][MAXN];

int BFS(const int & n, const int & m){
	fill((bool*)visited, (bool*)visited + MAXN*MAXN, false);
	queue< pair<int,int> > eile;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if( (i == 0 || i == n-1 || j == 0 || j == m-1) && !map[i][j] )
				eile.push( (pair<int,int>){i,j} ),	visited[i][j] = true;
	
	while(!eile.empty()){
		pair<int,int> w = eile.front();
		eile.pop();
		
		for(int di = -1; di<=1; di++)
			for(int dj = -1; dj<=1; dj++)
				if(abs(di) + abs(dj) == 1 && w.first+di >= 0 && w.first+di < n && w.second+dj >= 0 && w.second+dj < m && !map[w.first+di][w.second+dj] && !visited[w.first+di][w.second+dj])
					eile.push( (pair<int,int>){w.first+di,w.second+dj} ),	visited[w.first+di][w.second+dj] = true;
		}
	
	//~ bool answ = false;
	//~ for(int di = -1; di<=1; di++)
	//~ for(int dj = -1; dj<=1; dj++)
		//~ if(abs(di) + abs(dj) == 1 && i+di >= 0 && i+di < n && j+dj >= 0 && j+dj < m && !map[i+di][j+dj] && !visited[i+di][j+dj])
			//~ answ = (answ || DFS(i+di, j+dj, n, m));
	
	int ttt = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!visited[i][j])
				ttt++;
	
	return ttt;
	}

double h = 0;

void check(int n, int m){
	int tt=0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(map[i][j]) tt++;
			
	//~ cout << (h/1157353 * 100) << "%" << endl;
	h+=1;
	
	int enclosed = BFS(n, m);
	minamount[n][m][enclosed] = min(minamount[n][m][enclosed], tt);
	}

void filled(int i, int j, int n, int m){
	if(i >= n){
			check(n, m);
		return;
		}
	
	int nextj = (j+1)%m;
	int nexti = i + (j+1)/m;
	
	map[i][j] = false;
	filled(nexti, nextj, n, m);
	map[i][j] = true;
	filled(nexti, nextj, n, m);
	map[i][j] = false;
	}

void solve(int test){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	
	int q = min(n, m), w = max(n, m);

	printf("Case #%d: %d\n", test, minamount[w][q][k]);
	}

int main(){	
	int testcases;
	scanf("%d", &testcases);
	
	fill((int*)minamount, (int*)minamount + MAXN*MAXN*MAXN, MAXN*MAXN*MAXN);
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= 20; j++)
			if(i*j <= 20)
				filled(0, 0, i, j);
	
	for(int test = 0; test < testcases; test++)
		solve(test+1);
	
	return 0;
}
