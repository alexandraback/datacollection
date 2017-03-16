#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <map>

#define REP(a,b) for (int a=0; a<b; a++)
#define FOR(a,b,c) for (int a=b; a<=c; a++)
#define FORD(a,b,c) for (int a=b; a>=c; a--)
#define RESET(a,b) memset(a, b, sizeof a)

#define INF 1023123123
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PII pair<int,int> 
#define PDD pair<double,double>

#define OF 103
#define __ puts("")
using namespace std;

int nkasus;
int dist[230][230];
PII par[230][230];
int ke[230][230];
queue<int> q;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bt(int r, int c){
	if (par[r][c].F == -1) return;
	
	bt(par[r][c].F, par[r][c].S);
	printf("%c", "SENW"[ke[r][c]]);
}

int main(){
	RESET(dist,-1);
	par[OF][OF] = MP(-1,-1);
	dist[OF][OF] = 0;
	q.push((OF << 10) | OF);
	while (!q.empty()){
		int ui = q.front() >> 10;
		int uj = q.front() & 1023;
		q.pop();
		
//		printf("%d %d\n", ui - OF, uj - OF);
		
		REP(i,4){
			int ni = ui + dr[i]*(1+dist[ui][uj]);
			int nj = uj + dc[i]*(1+dist[ui][uj]);
			
			if ((0 <= ni) && (ni < 230) && (0 <= nj) && (nj < 230) && (dist[ni][nj] == -1)){
				dist[ni][nj] = 1 + dist[ui][uj];
				par[ni][nj] = MP(ui,uj);
				ke[ni][nj] = i;
				q.push((ni << 10) | nj);
			}
		}
	}

	
	scanf("%d", &nkasus);
	REP(jt,nkasus){
		int a,b;
		scanf("%d%d", &a, &b);	
	
		printf("Case #%d: ", jt+1);
		bt(b+OF, a+OF);
		printf("\n");
	}

	return 0;
}
