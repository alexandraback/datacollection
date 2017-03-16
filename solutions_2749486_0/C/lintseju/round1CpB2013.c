#include <cstdio>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

int map[300][300];

void walk(int px, int py, int step, char path[])
{
	int v = map[px][py] - 1;
	if(step < 0)
		return;
	//printf("map[%d][%d] = %d\n", px, py, map[px][py]);
	if(px + step < 300 && v == map[px+step][py]){
		walk(px + step, py, step - 1, path);
		path[step-1] = 'W';
	}else if(py + step < 300 && v == map[px][py+step]){
		walk(px, py + step, step - 1, path);
		path[step-1] = 'S';
	}else if(px - step >= 0 && v == map[px-step][py]){
		walk(px - step, py, step - 1, path);
		path[step-1] = 'E';
	}else if(py - step >= 0 && v == map[px][py-step]){
		walk(px, py - step, step - 1, path);
		path[step-1] = 'N';
	}
}

int main()
{
	int i, j, n, c = 1, x, y, step = 0, px, py;
	int r, t;
	char path[600];
	queue<int> bfsx;
	queue<int> bfsy;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &x, &y);
		px = py = 150;
		for(i = 0;i < 300;i++)
			for(j = 0;j < 300;j++)
				map[i][j] = -1;
		x += 150;
		y += 150;	
		while(!bfsx.empty())
			bfsx.pop();
		while(!bfsy.empty())
			bfsy.pop();
		map[px][py] = 0;
		bfsx.push(px);
		bfsy.push(py);
		//step = 1;
		while(!bfsx.empty()){
			px = bfsx.front();
			py = bfsy.front();
			bfsx.pop();
			bfsy.pop();
			//printf("%d %d\n", px, py);
			step = map[px][py] + 1;
			if((px == x && py == y))
				break;
			if(px+step < 300 && map[px+step][py] == -1){
				bfsx.push(px+step);
				bfsy.push(py);
				map[px+step][py] = map[px][py] + 1;
			}
			if(py+step < 300 && map[px][py+step] == -1){
				bfsx.push(px);
				bfsy.push(py+step);
				map[px][py+step] = map[px][py] + 1;
			}
			if(px-step >= 0 && map[px-step][py] == -1){
				bfsx.push(px-step);
				bfsy.push(py);
				map[px-step][py] = map[px][py] + 1;
			}
			if(py-step < 300 && map[px][py-step] == -1){
				bfsx.push(px);
				bfsy.push(py-step);
				map[px][py-step] = map[px][py] + 1;
			}
		}
		memset(path, 0, sizeof(path));
		//printf("%d\n", step);
		walk(x, y, step - 1, path);
		printf("Case #%d: %s\n", c++, path);
	}
	return 0;
}