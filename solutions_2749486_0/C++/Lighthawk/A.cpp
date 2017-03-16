#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <ctime>
using namespace std;
typedef long long LL;

#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x?

const int dirx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const char dirn[5] = {'W', 'E', 'S', 'N'};
const int NN = 4;
const int MAXS = 1000007;

struct node{
	int x, y;
	int stp;
	int preidx;
	char pre;
}que[MAXS];
int r, c, hd, ed;

struct node2{
	int x, y;
};
struct cmp{
	bool operator()(const struct node2 &a, const struct node2 &b) const{
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
};
set<struct node2, cmp>setx;

bool set_insert(int x, int y){
	node2 a;
	a.x = x;
	a.y = y;
	if(setx.find(a) == setx.end()){
		setx.insert(a);
		return true;
	}else{
		return false;
	}
}

bool que_insert(int x, int y, int stp, char pre, int preidx){
	bool isok = set_insert(x, y);
	if(isok){
		node cur;
		cur.x = x;
		cur.y = y;
		cur.stp = stp;
		cur.pre = pre;
		cur.preidx = preidx;
		que[ed++] = cur;
		return true;
	}else{
		return false;
	}
}

void init(){
	setx.clear();
	hd = ed = 0;
	que_insert(0, 0, 0, 0, -1);
}

bool is_same_tar(int x, int y){
	if(x==r && y==c) return true;
	return false;
}

int bfs(){
	int nx, ny, stp, preidx;
	bool inp;
	node cur;
	while(hd < ed){
		preidx = hd;
		cur = que[hd++];
		stp = cur.stp + 1;
		for(int i=0; i<4; ++i){
			nx = cur.x + dirx[i][0]*stp;
			ny = cur.y + dirx[i][1]*stp;
			inp = que_insert(nx, ny, stp, dirn[i], preidx);
			if(is_same_tar(nx, ny)){
				if(inp) return ed-1;
				else return preidx;
			}
		}
	}
}

string solve(int tarx){
	int idxp = tarx;
	string res = "";
	node cur;
	while(idxp >= 0){
		cur = que[idxp];
		res += (char)cur.pre;
		idxp = cur.preidx;
	}
	return res;
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	FILE *fp = fopen("B-small-attempt1.out", "w+");
	//freopen("B-small-attempt0.out", "w", stdout);
	int T, cases, tarx, len;
	string res;
	scanf("%d", &T);
	for(cases=1; cases<=T; ++cases){
		scanf("%d%d", &r, &c);
		init();
		tarx = bfs();
		res = solve(tarx);

		len = res.size();

		fprintf(fp, "Case #%d: ", cases);
		printf("Case #%d: ", cases);
		for(int i=len-2; i>=0; --i){
			//fputchar(fp, res[i]);
			fprintf(fp, "%c", res[i]);
			printf("%c", res[i]);
		}
		fprintf(fp, "\n");
		printf("\n");
	}

    //system("pause");
    return 0;
}

