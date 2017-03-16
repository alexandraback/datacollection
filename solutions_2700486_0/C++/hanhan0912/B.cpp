/* hanhanw v1.2 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=y; x<=z; x++)
#define FORD(x,y,z) for(int x=y; x>=z; x--)
#define FLST(x,y,z) for(int x=y; x; x=z[x])
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define SZ size
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

const int H = 131;

int nT,n,x,y,d[500];
double ans,cnt;
map<int, int> app;

int turnRight(int cc){
	while (d[cc-1]>d[cc] && d[cc+1]<=d[cc])
		cc++;
	return cc;
}
int turnLeft(int cc){
	while (d[cc+1]>d[cc] && d[cc-1]<=d[cc])
		cc--;
	return cc;
}

void dfs(int cur, int cen){
	if (cur >= n){
		/*
		int st=0; REP(i,0,499) if (d[i]){ st=i; break; }
		int ed=0; FORD(i,499,0) if (d[i]){ ed=i; break; }
		int h=0,h2=0;
		puts("===");
		REP(i,st,ed){
			h=h*H+d[i];
			h2=h2*H+i;
			printf("%d %d\n", i, d[i]);
		}
		h = h*H+h2;
		//if (app[h]) return ;
		//else app[h] = 1;
		*/
		if (d[x]>=y+1) ans+=1;
		cnt+=1;
		
		return ;
	}
	/*
	if (cur >= 2){
		puts("==test");
		int st=0; REP(i,0,499) if (d[i]){ st=i; break; }
		int ed=0; REP(i,0,499) if (d[i]) ed=i;
		REP(i,st,ed){
			printf("#%d: %d\n", i, d[i]);
		}
		puts("");
	}
	*/
	if (cur==0){
		d[cen] = 1;
		dfs(cur+1,cen);
		d[cen] = 0;
		return ;
	}
	if (d[cen-1] > d[cen] && d[cen+1] > d[cen]){
	//	printf("%d stop\n", cur);
		d[cen] += 2;
		dfs(cur+1,cen);
		d[cen] -= 2;
		return ;
	}
	if (d[cen-1] > d[cen]){
		int cc=turnRight(cen+1);
		if (!(d[cc-1] && d[cc+1])){
			d[cc] = 1;
			dfs(cur+1,cen);
			d[cc] = 0;
		} else {
			d[cc] += 2;
			dfs(cur+1,cen);
			d[cc] -= 2;
		}
		return ;
	}
	if (d[cen+1] > d[cen]){
		int cc=turnLeft(cen-1);
	//	printf("== %d ==\n", cur);
	//	printf("%d\n", cc);
		if (!(d[cc-1] && d[cc+1])){
			d[cc] = 1;
			dfs(cur+1,cen);
			d[cc] = 0;
		} else {
			d[cc] += 2;
			dfs(cur+1,cen);
			d[cc] -= 2;
		}
		return ;
	}
//	puts("==two==");
	int cc = turnRight(cen+1);
//	printf("== %d ==\n", cur);
//	printf("%d \n", cc);
	if (!(d[cc-1] && d[cc+1])){
		d[cc] = 1;
		dfs(cur+1,cen);
		d[cc] = 0;
	} else {
		d[cc] += 2;
		dfs(cur+1,cen);
		d[cc] -= 2;
	}

	cc=turnLeft(cen-1);
//	printf("== %d ==\n", cur);
//	printf("%d \n", cc);
	if (!(d[cc-1] && d[cc+1])){
		d[cc] = 1;
		dfs(cur+1,cen);
		d[cc] = 0;
	} else {
		d[cc] += 2;
		dfs(cur+1,cen);
		d[cc] -= 2;
	}
}

void solve(int T){
	app.clear();
	MSET(d,0);
	scanf("%d %d %d", &n, &x, &y);
	x += 250; 
	ans=cnt=0;
	dfs(0,250);
	printf("Case #%d: %.8f\n", T, ans/cnt);
}
int main(){
	scanf("%d", &nT);
	REP(i,1,nT)
		solve(i);

	return 0;
}
