#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstdio>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <cassert>
#include <sstream>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef stringstream SS;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a) MAX(a,-(a))

#define SS(a) scanf("%d",&a)
#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007
#define INF 2147483647

#define x first
#define y second

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

char dir[] = "NEWS";

int visited[1222][1222];

struct node {
	pii p;
	string s;
};



int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
    int t;
    cin>>t;
    FOR(tt,1,t){
		int x,y;
		cin>>x>>y;
		x += 600;
		y += 600;
		memset(visited,0,sizeof(visited));
		queue <node> Q;
		node s;
		s.p = mp(600,600);
		s.s = "";
		Q.push(s);
		visited[600][600] = 1;
		string ans;
		int nx,ny;
		bool flag = false;
		while(!Q.empty()){
			node c = Q.front();
			pii cur = c.p;
			Q.pop();
			REP(i,4){
				nx = cur.x + dx[i] * visited[cur.x][cur.y];
				ny = cur.y + dy[i] * visited[cur.x][cur.y];

				if (nx<0 || nx>1200 || ny<0 || ny>1200) continue;
				if (visited[nx][ny]) continue;
				if (nx == x && ny==y){
					flag = true;
					ans = c.s + dir[i];
					break;
				}
				node neigh;
				neigh.s = c.s + dir[i];
				neigh.p = mp(nx,ny);
				visited[nx][ny] = visited[cur.x][cur.y] + 1;
				Q.push(neigh);
			}
			if (flag) break;
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
