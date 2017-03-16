#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#define MaxLength INT_MAX
#define MaxNode 12
#define MN 105
using namespace std;

int M,T,N,H;
int c[MN][MN];
int h[MN][MN];
int mem[MN][MN];
int dr[4] = {0,-1,1,0};
int dc[4] = {1,0,0,-1};
int main(){
	int i,j,k,l,tt,a,b,d;
	int r1,c1,r2,c2;
	long long res;
	scanf("%d",&T);
	for(tt=1; tt<=T;tt++){
		res = INT_MAX;
		scanf("%d %d %d",&H,&N,&M);
		for(i=0; i<N ;i++)
			for(j=0; j<M;j++){
				mem[i][j] = 10000000;
				scanf("%d",&c[i][j]);
			}
		for(i=0; i<N ;i++)
			for(j=0; j<M;j++)
				scanf("%d",&h[i][j]);
		mem[0][0] = 0;
		queue<pair<int, int> > q;
		q.push(make_pair(0,0));
		while(!q.empty()){
			r1 = q.front().first;
			c1 = q.front().second;
			q.pop();
			if(mem[r1][c1] >= mem[N-1][M-1])
				continue;
			for(i=0; i<4; i++){
				r2 = r1 + dr[i];
				c2 = c1 + dc[i];
				if(c2>=0 && c2<M && r2>=0 && r2<N
				&& h[r1][c1]+50<=c[r2][c2]
				&& h[r2][c2]+50<=c[r2][c2]
				&& h[r2][c2]+50<=c[r1][c1]
				&& H+50<=c[r2][c2]){
					if(mem[r2][c2]>0){
						mem[r2][c2] = 0;
						q.push(make_pair(r2,c2));
					}
				}
			}
		}
		for(i=0; i<N; i++)
			for(j=0; j<M; j++)
				if(mem[i][j]==0)
					q.push(make_pair(i,j));
		while(!q.empty()){
			r1 = q.front().first;
			c1 = q.front().second;
			q.pop();
			if(mem[r1][c1] >= mem[N-1][M-1])
				continue;
			for(i=0; i<4; i++){
				r2 = r1 + dr[i];
				c2 = c1 + dc[i];
				if(c2>=0 && c2<M && r2>=0 && r2<N
				&& h[r1][c1]+50<=c[r2][c2]
				&& h[r2][c2]+50<=c[r2][c2]
				&& h[r2][c2]+50<=c[r1][c1]
				){
					//int time = mem[r1][c1];
					//c[r2][c2] >= (H - mem[r1][c1] - d)+50;
					d = max(0,H - mem[r1][c1] - c[r2][c2] + 50);
					if(H - mem[r1][c1] - d  >= h[r1][c1] + 20){
						if(mem[r2][c2]>mem[r1][c1]+10+d){
							mem[r2][c2] = mem[r1][c1]+10+d;
							q.push(make_pair(r2,c2));
						}
					}
					else if(mem[r2][c2]>mem[r1][c1]+100+d){
						mem[r2][c2] = mem[r1][c1]+100+d;
						q.push(make_pair(r2,c2));
					}
				}
			}
		}
		printf("Case #%d: %d.%d\n",tt,mem[N-1][M-1]/10,mem[N-1][M-1]%10);
	}
	return 0;
}
