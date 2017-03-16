#include<algorithm>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<complex>
using namespace std;

typedef long long LL;
typedef long double LD;

//#define dprintf(...) fprintf(stderr, __VA_ARGS__)
 #define dprintf(...)

int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}

#define hshift (1<<20)
#define shift (hshift<<1)

//#define hshift 0
//#define shift 16
#define treesize (shift<<1)
#define INF 1000000000

int tree[treesize];

int _find_min(int node, int aleft, int aright, int left, int right)
{
	if(left <= aleft && right >= aright) return tree[node];
	if(aleft >= right || left >= aright) return INF;
	int q =_find_min(node*2, aleft, (aleft+aright)/2, left, right);
	int r =_find_min(node*2+1, (aleft+aright)/2, aright, left, right);
	return max(tree[node], min(q,r));
}

void _set_min(int node, int aleft, int aright, int left, int right, int val)
{
	if(left <= aleft && right >= aright)
	{
		tree[node] = val;
		if(node*2+1 < treesize){
	tree[node] = max(tree[node], min(tree[node*2], tree[node*2+1]));
		};
		return;
	};
	if(aleft >= right || left >= aright) return;
	_set_min(node*2, aleft, (aleft+aright)/2, left, right, val);
	_set_min(node*2 + 1, (aleft + aright)/2, aright, left, right, val);
	tree[node] = max(tree[node], min(tree[node*2], tree[node*2+1]));
};

int find_min(int left, int right){
	return _find_min(1, 0, shift, left+hshift, right+hshift);
};

void set_min(int left, int right, int min){
	_set_min(1, 0, shift, left+hshift, right+hshift, min);
};

struct event{
	int time;
	int cnt;
	int x, y;
	int s;
	int dt, dp, ds;
	bool operator<(const event &t) const{
		return time > t.time;
	};
};

priority_queue<event> pq;

event te[1024];
int tc;

int n;
void go(int C) {
	while(!pq.empty()) pq.pop();
	tc=0;
	memset(tree, 0, sizeof(tree));
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		event e;
		scanf("%d %d %d %d %d %d %d %d", &e.time, &e.cnt, &e.x, &e.y, &e.s,
				&e.dt, &e.dp, &e.ds);
		pq.push(e);
	};
	int succesfull = 0;
	tc=0;
	while(!pq.empty()){
		int tm;
		tc=1;
		te[0] = pq.top();
		tm = te[0].time;
		pq.pop();
		dprintf("\n\nDay %d\n", tm);
		while(!pq.empty()){
			te[tc] = pq.top();
			if(te[tc].time == tm){
				tc++;
				pq.pop();
			}else{
				break;
			};
		};
		for(int i=0; i<tc; ++i){
			int m=find_min(te[i].x, te[i].y);
			if(m < te[i].s) succesfull++;
			dprintf("Attack, x: %d, y: %d, strenght: %d, prevmin: %d\n",
					te[i].x, te[i].y, te[i].s, m);
			if(m < te[i].s) dprintf("SUCCESSFULL!\n");
		};
		for(int i=0; i<tc; ++i){
			set_min(te[i].x, te[i].y, te[i].s);
			if(te[i].cnt > 1){
				te[i].cnt--;
				te[i].x+=te[i].dp;
				te[i].y+=te[i].dp;
				te[i].s+=te[i].ds;
				te[i].time+=te[i].dt;
				pq.push(te[i]);
			};
		};
		
	};
	printf("Case #%d: %d\n",C, succesfull);
};

int main() {
	int T;
	scanf("%d", &T);
	for(int C=1; C<=T; ++C) go(C);
	return 0;
}

