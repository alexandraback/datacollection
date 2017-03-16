#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:16777216")
#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include <stack>
#include <time.h>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define mp make_pair
#define pb push_back
#define INF (1e9)

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const double pi = acos(-1.0);
const int inf =(int) 1e9;

const double eps = 1e-4;
const int ss=(int)1e6+3;
const int base=inf;

bool pred (const pair<PII,int>& i, const pair<PII,int>& j) 
{
	if (i.first.first == j.first.first) {
		return j.first.second<i.first.second;
	} else {
		return i.first.first<j.first.first;
	}
}

int n = 205;
int pl = 100;

vector<VB> used(n,VB(n,false));
vector< vector<char> > p(n,vector<char>(n));
VVI d(n,VI(n));

char c[4] = {'N','E','S','W'};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool check(int x, int y) {
	if (x>=0 && x<=n-1 && y>=0 && y<=n-1)
		return true;
	return false;
}


void bfs() {
	queue<PII> q;
	q.push(mp(pl,pl));
	queue<int> step;
	step.push(1);
	used[pl][pl] = true;
	p[pl][pl] = 'z';
	d[pl][pl] = 0;
	while(!q.empty()) {
		PII v = q.front();
		int st = step.front();
		step.pop();
		q.pop();
		int x = v.first;
		int y = v.second;
		FOR(i,4) {
			if (check(x+dx[i]*st,y+dy[i]*st) && used[x+dx[i]*st][y+dy[i]*st] == false) {
				q.push(mp(x+dx[i]*st,y+dy[i]*st));
				used[x+dx[i]*st][y+dy[i]*st] = true;
				p[x+dx[i]*st][y+dy[i]*st] = c[i];
				step.push(st+1);
				d[x+dx[i]*st][y+dy[i]*st] = st;
			}
		}
	}
}


int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	bfs();
	FOR(tt,t) {
		printf("Case #%d: ",tt+1);
		int x,y;
		scanf("%d%d",&x,&y);
		vector<char> path;
		x+=pl;
		y+=pl;
		bool t = false;
		if (p[x][y] == 0) {
			//printf("0");
			t = true;
			--x;
		}
		for(char v = p[x][y]; v!='z';) {
			path.push_back(v);
			FOR(i,4) {
				if (v == c[i]) {
					int z = d[x][y];
					x -= dx[i]*d[x][y];
					y -= dy[i]*d[x][y];
					v = p[x][y];
					break;
				}
			}
		}
		reverse(path.begin(),path.end());
		FOR(i,(int)path.size()) {
			printf("%c",path[i]);
		}
		if (t) {
			printf("WE");
		}
		printf("\n");
	}
#ifdef _DEBUG
    fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#else
	//fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif

    return 0;
}

