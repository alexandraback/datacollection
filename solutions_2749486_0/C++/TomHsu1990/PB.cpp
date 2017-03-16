#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
char s[5] = "NSEW";
int dx[5] = {0,0,-1,1};
int dy[5] = {-1,1,0,0};
struct node{
	int x, y, jump;
	vector<int> step;
};
bool vis[200][200];
int main(){
	int T, n;
	scanf("%d", &T);
	for(int t=1;t<=T;++t){
		for(int i=0;i<201;++i)
			for(int j=0;j<201;++j)
				vis[i][j] = false;
		struct node now;
		scanf("%d%d", &now.x, &now.y);
		printf("Case #%d: ", t);
		now.x += 100;
		now.y += 100;
		now.jump = 1;
		now.step.clear();
		vis[now.x][now.y] = true;
		queue<struct node> q;
		q.push(now);
		bool find = false;
		while(!q.empty() && !find){
			now = q.front(); q.pop();
			for(int i=0;i<4;++i){
				int tx = now.x+dx[i]*now.jump;
				int ty = now.y+dy[i]*now.jump;
				if(tx == 100 && ty == 100){
					// find path;
					if(now.step.size()+1 <= 500){
						for(unsigned int j=0;j<now.step.size();++j){
							printf("%c", s[now.step[j]]);
						}
						printf("%c\n", s[i]);
						find = true;
					}
					break;
				}
				if(tx >= 0 && tx < 201 && ty >= 0 && ty < 201 && !vis[tx][ty]){
					vis[tx][ty] = true;
					struct node nxt;
					nxt.x = tx;
					nxt.y = ty;
					nxt.jump = now.jump + 1;
					for(unsigned int j=0;j<now.step.size();++j){
						nxt.step.push_back(now.step[j]);
					}
					nxt.step.push_back(i);
					
					q.push(nxt);
				}
			}
		}
	}
}
