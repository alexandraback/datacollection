#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct{
	int x,y;
	char direction;
	int from;
	int ind;
	int step;
}node;

node tmp,cur,end,nodes[1000000];

void print_r(int i){
	if(!i)
		return;

	if(nodes[i].direction == 'O')
		return;
	print_r(nodes[i].from);
	printf("%c",nodes[i].direction);
}

void process(){
	queue<node>q;
	map<string,int>used;
	char ind_s[20];

	int step = 0;
	int n_node = 0;
	cur.x = 0;
	cur.y = 0;
	cur.step = 0;
	cur.direction = 'O';
	cur.ind = 0;
	sprintf(ind_s,"%d_%d",tmp.x,tmp.y);
	used[ind_s] = 1;
	q.push(cur);
	nodes[0] = cur;

	while(!q.empty()){
		cur = q.front();
		q.pop();
		if(cur.x == end.x && cur.y == end.y) {
			//printf("%d\n",cur.step);
			print_r(cur.ind);
			printf("\n");
			break;
		}
		step = cur.step + 1;

		tmp = cur;
		tmp.x += step;
		sprintf(ind_s,"%d_%d",tmp.x,tmp.y);
		if(used.find(ind_s) == used.end()){
			used[ind_s] = 1;
			n_node++;
			nodes[n_node] = tmp;
			nodes[n_node].ind = n_node;
			nodes[n_node].from = cur.ind;
			nodes[n_node].direction = 'E';
			nodes[n_node].step = step;
			q.push(nodes[n_node]);

		}

		tmp = cur;
		tmp.x -= step;
		sprintf(ind_s,"%d_%d",tmp.x,tmp.y);
		if(used.find(ind_s) == used.end()){
			used[ind_s] = 1;
			n_node++;
			nodes[n_node] = tmp;
			nodes[n_node].ind = n_node;
			nodes[n_node].from = cur.ind;
			nodes[n_node].direction = 'W';
			nodes[n_node].step = step;
			q.push(nodes[n_node]);

		}

		tmp = cur;
		tmp.y += step;
		sprintf(ind_s,"%d_%d",tmp.x,tmp.y);
		if(used.find(ind_s) == used.end()){
			used[ind_s] = 1;
			n_node++;
			nodes[n_node] = tmp;
			nodes[n_node].ind = n_node;
			nodes[n_node].from = cur.ind;
			nodes[n_node].direction = 'N';
			nodes[n_node].step = step;
			q.push(nodes[n_node]);

		}

		tmp = cur;
		tmp.y -= step;
		sprintf(ind_s,"%d_%d",tmp.x,tmp.y);
		if(used.find(ind_s) == used.end()){
			used[ind_s] = 1;
			n_node++;
			nodes[n_node] = tmp;
			nodes[n_node].ind = n_node;
			nodes[n_node].from = cur.ind;
			nodes[n_node].direction = 'S';
			nodes[n_node].step = step;
			q.push(nodes[n_node]);

		}


	}
}



int main(){

	freopen("ii.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	int t,i,j,k,l,cas=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&end.x,&end.y);
		printf("Case #%d: ",cas++);
		process();
	}

	return 0;
}