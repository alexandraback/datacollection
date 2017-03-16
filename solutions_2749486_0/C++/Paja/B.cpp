#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 211;
const int C = 105;
const int inf = 0x7fffffff;

string answ;

struct _3d{
	int move, x, y;
	};

int dist[MAXN][MAXN][MAXN];
char p[MAXN][MAXN][MAXN];
pair<int, int> par[MAXN][MAXN][MAXN];

char mv[3][3] = { {'x', 'N', 'x'}, {'W', 'x', 'E'}, {'x', 'S', 'x'} };

void solve(){
	fill((int*)dist, (int*)dist + MAXN*MAXN*MAXN, -1);
	
	queue<_3d> eile;
	_3d pt = (_3d){1, 0, 0};
	eile.push(pt);
	dist[1][C][C] = 0;
	
	while(!eile.empty()){
		_3d u = eile.front();
		eile.pop();
		//~ cout << "OK" << endl;
		//~ cout << u.move << " " << u.x << " " << u.y << endl;
		for(int j = -1; j <= 1; j++)
		for(int i = -1; i <= 1; i++)
			
				if(abs(i) + abs(j) == 1 && abs(u.x + i*u.move) < C && abs(u.y + j*u.move) < C && u.move < C)
					if( dist[u.move + 1][C + u.x + i*u.move][C + u.y + j*u.move] == -1){
						
						dist[u.move + 1][C + u.x + i*u.move][C + u.y + j*u.move] = dist[u.move][C + u.x][C + u.y] + 1;
						p[u.move + 1][C + u.x + i*u.move][C + u.y + j*u.move] = mv[1 + i][1 + j];
						par[u.move + 1][C + u.x + i*u.move][C + u.y + j*u.move] = (pair<int,int>){u.x, u.y};
						
						eile.push( (_3d){u.move + 1, u.x + i*u.move, u.y + j*u.move} );
						}
		}
	
	}

int main(){
	int testcases;
	scanf("%d", &testcases);
	
	solve();
	//~ cout << "OK" << endl;
	for(int testcase = 0; testcase < testcases; testcase++){
		int x, y;
		scanf("%d %d", &x, &y);
		
		int answ = -1;
		for(int i = 0; i < 100; i++)
			if(dist[i][C + x][C + y] != -1){
				answ = i;
				break;
				}
		/*
		for(int i = 0; i < 10; i++, printf("\n\n"))
		for(int j = -5; j <= 5; j++, printf("\n"))
		for(int k = -5; k <= 5; k++)
			printf("%+d ", dist[i][C+j][C+k]);
		*/
		string s;
		int dx = x, dy = y, tmpx, tmpy;
		
		while(!(dx == 0 && dy == 0)){
			//~ s += p[answ][C + dx][C + dy];
			
			//~ cout << p[answ][C + dx][C + dy] << endl;;
			//~ cout << answ << " " << dx << " " << dy << endl;
			//~ break;
			tmpx = par[answ][C + dx][C + dy].first;
			tmpy = par[answ][C + dx][C + dy].second;
			if(tmpx < dx)
				s += 'E';
			if(tmpx > dx)
				s += 'W';
			if(tmpy > dy)
				s += 'S';
			if(tmpy < dy)
				s += 'N';
			
			dx = tmpx, dy = tmpy;
			answ--;
			}
		//s += p[answ][C][C];
		
		printf("Case #%d: ", testcase+1);
		for(int j = s.size()-1; j >=0; j--)
			cout << s[j];
		cout << endl;
		}
	
	
	return 0;
}
