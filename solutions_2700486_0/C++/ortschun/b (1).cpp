#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
const int INF = 1000000000;
int g[100][100] ;

int X,Y ;
double solve(int k){
	if(k == 0){
		if(Y >= 100) return 0 ;
		if(X <= -50 || X >= 50) return 0 ;
		return g[50 + X][Y] ;
	}

	double ret = 0 ;
	int x = 50,y = 0 ;
	while(g[x][y] != 0) y += 2 ;
	if(y == 0){
		g[x][y] = 1 ; 
		ret += solve(k - 1) ;
		g[x][y] = 0 ;
	}
	else{
		if(g[x - 1][y - 1] == 1)  {
			while(y > 0 && g[x + 1][y - 1] == 0) { x++ ; y-- ; }
			g[x][y] = 1 ;
			ret += solve(k - 1) ;
			g[x][y] = 0 ;
		}
		else if(g[x + 1][y - 1] == 1){
			while(y > 0 && g[x - 1][y - 1] == 0) { x-- ; y-- ; }
			g[x][y] = 1 ;
			ret += solve(k - 1) ;
			g[x][y] = 0 ;   
		}
		else{
			int tx = x,ty = y ;
			while(y > 0 && g[x + 1][y - 1] == 0) { x++ ; y-- ; }
			g[x][y] = 1 ;
			ret += solve(k - 1) ;
			g[x][y] = 0 ;

			x = tx,y = ty ;
			while(y > 0 && g[x - 1][y - 1] == 0) { x-- ; y-- ; }
			g[x][y] = 1 ;
			ret += solve(k - 1) ;
			g[x][y] = 0 ;   

			ret /= 2 ;
		}
	}
	return ret ;
}


int main(){
	//freopen("b.in", "r", stdin); 
	//freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	//freopen("B-small-attempt2.in", "r", stdin); freopen("B-small-attempt2.out", "w", stdout);
	//freopen("B-small-attempt3.in", "r", stdin); freopen("B-small-attempt3.out", "w", stdout);

	//freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout)
	int nT;
	cin>>nT;
	for (int t=1; t<=nT; t++) {
		int n ;
		cin >> n >> X >> Y ;
		memset(g,0,sizeof g) ;
		double ret = solve(n) ;
		printf("Case #%d: %.9lf\n",t,ret) ;
	}

	return 0 ;
}
