#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 30
#define INF
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)

using namespace std;

typedef long long LL;  

int testy;
int n,m,k;
int zajete[MAXN][MAXN], father[MAXN][MAXN];
int ruchi[4] = {-1,0,1,0};
int ruchj[4] = {0,1,0,-1};

int find(int i, int j) {
	if (father[i][j] == i*m + j || father[i][j] == -1) return father[i][j];
	father[i][j] = find(father[i][j]/m,father[i][j]%m);
	return father[i][j];
}

int main(){
	scanf("%d",&testy);
	FOR(g,1,testy) {
		printf("Case #%d: ",g);
		scanf("%d%d%d",&n,&m,&k);
		
		REP(i,n) father[i][0] = father[i][m-1] = -1;
		REP(i,m) father[0][i] = father[n-1][i] = -1;
		
		int ilosc = 1<<(n*m);
		int res = k;
		REP(h,ilosc) if (__builtin_popcount(h) < res) {
			int pom = h;
			int pomres = __builtin_popcount(h);
			REP(i,n) REP(j,m) {
				zajete[i][j] = pom&1;
				pom /= 2; 
			}
			
			FOR(i,1,n-2) FOR(j,1,m-2) father[i][j] = i*m+j;
			FOR(i,1,n-2) FOR(j,1,m-2) 
				if (!zajete[i][j]) REP(kier,4) {
					int ni = i+ruchi[kier];
					int nj = j+ruchj[kier];
					if (!zajete[ni][nj]) {
						int f1 = find(i,j);
						int f2 = find(ni,nj);
						if (f1 != f2) {
							if (f2 == -1) father[f1/m][f1%m] = -1;
								else father[f2/m][f2%m] = f1;
						}
					}
					//REP(i,n) {REP(j,m) printf("%d ",father[i][j]); puts("");}
				}
			FOR(i,1,n-2) FOR(j,1,m-2) 
				if (!zajete[i][j] && find(i,j) != -1) ++pomres;
			
			if (pomres >= k) {
				res = __builtin_popcount(h);
				//REP(i,n) {REP(j,m) printf("%d ",zajete[i][j]); puts("");}
				//REP(i,n) {REP(j,m) printf("%d ",father[i][j]); puts("");}
				//puts(""); 
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
