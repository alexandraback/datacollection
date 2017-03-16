#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#ifndef MAXN
#define MAXN 102
#endif

int C[MAXN][MAXN];
int F[MAXN][MAXN];
bool MAP[MAXN][MAXN];

struct point {
	int x;
	int y;
	int w;
	point (){};
	point (int _x, int _y, int _w) : x(_x), y(_y), w(_w){}
};

typedef pair < double, point > NODE;

bool operator < (point a, point b){
	return a.w < b.w;
}

bool move_test (double &water, point a, point b){
	if (C[a.x][a.y] - 50 >= F[b.x][b.y]){
		if (F[a.x][a.y] <= C[b.x][b.y] - 50){
			if (F[b.x][b.y] <= C[b.x][b.y] - 50){
				water = C[b.x][b.y] - 50;
				return true;
			}
		}
	}
	return false;
}

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		int H, N, M;
		cin >> H >> N >> M;
		for (int i = 0 ; i < N ; i++){
			for (int j = 0 ; j < M ; j++){
				cin >> C[i][j];
			}
		}
		
		for (int i = 0 ; i < N ; i++){
			for (int j = 0 ; j < M ; j++){
				cin >> F[i][j];
			}
		}
		
		memset (MAP, 0, sizeof(bool) * MAXN * MAXN);
		
		point start = point(0,0,H);
		
		priority_queue < NODE > Q;
		Q.push(make_pair(0, start));
		NODE node;

		while(!Q.empty()){
			node = Q.top();
			Q.pop();
			
			if (MAP[node.second.x][node.second.y]) continue;
			// cout << node.second.x << " " << node.second.y << " " << node.first << endl;	
			if (node.second.x == (N - 1) && node.second.y == (M - 1)) break;
			MAP[node.second.x][node.second.y] = true;
			
			// North
			point next(0,0, 0);
			double water_level;
			if (node.second.x > 0){
				// cout << "NORTH" << endl;				
				next = node.second;
				next.x -= 1;
				if (move_test(water_level, node.second, next)){
					NODE tnode = node;
					tnode.second = next;					
					if (water_level >= H && tnode.first == 0){
						Q.push(tnode);						
					}
					else{
						if (tnode.second.w > water_level){
							tnode.first -= (tnode.second.w - water_level) / 10.0;
							tnode.second.w = water_level;
						}
						if (tnode.second.w - 20 >= F[node.second.x][node.second.y]){
							tnode.first -= 1;
							tnode.second.w -= 10;
						}else{
							tnode.first -= 10;
							tnode.second.w -= 100;
						}	
						Q.push(tnode);
					}
				}
			}
			// South
			if (node.second.x < N - 1){
				// cout << "SOUTH" << endl;				
				next = node.second;
				next.x += 1;
				if (move_test(water_level, node.second, next)){
					NODE tnode = node;
					tnode.second = next;
					if (water_level >= H && tnode.first == 0){
						Q.push(tnode);						
					}
					else{
						if (tnode.second.w > water_level){
							tnode.first -= (tnode.second.w - water_level) / 10.0;
							tnode.second.w = water_level;
						}
						if (tnode.second.w - 20 >= F[node.second.x][node.second.y]){
							tnode.first -= 1;
							tnode.second.w -= 10;
						}else{
							tnode.first -= 10;
							tnode.second.w -= 100;
						}	
						Q.push(tnode);
					}					
				}
			}
			// West
			if (node.second.y > 0){
				// cout << "WEST" << endl;				
				next = node.second;
				next.y -= 1;
				if (move_test(water_level, node.second, next)){
					NODE tnode = node;
					tnode.second = next;
					if (water_level >= H && tnode.first == 0){
						Q.push(tnode);						
					}
					else{
						if (tnode.second.w > water_level){
							tnode.first -= (tnode.second.w - water_level) / 10.0;
							tnode.second.w = water_level;
						}
						if (tnode.second.w - 20 >= F[node.second.x][node.second.y]){
							tnode.first -= 1;
							tnode.second.w -= 10;
						}else{
							tnode.first -= 10;
							tnode.second.w -= 100;
						}	
						Q.push(tnode);
					}					
				}
			}
			// East
			if (node.second.y < M - 1){
				// cout << "EAST" << endl;
				next = node.second;
				next.y += 1;
				if (move_test(water_level, node.second, next)){
					NODE tnode = node;
					tnode.second = next;
					if (water_level >= H && tnode.first == 0){
						Q.push(tnode);						
					}
					else{
						if (tnode.second.w > water_level){
							tnode.first -= (tnode.second.w - water_level) / 10.0;
							tnode.second.w = water_level;
						}
						if (tnode.second.w - 20 >= F[node.second.x][node.second.y]){
							tnode.first -= 1;
							tnode.second.w -= 10;
						}else{
							tnode.first -= 10;
							tnode.second.w -= 100;
						}	
						Q.push(tnode);
					}				
				}
			}
			
		}
		cout << "Case #" << casen + 1 << ": ";
		
		cout << ((node.first<0)?-node.first:0.0)  << endl;
	}
	

	return 0;
}
