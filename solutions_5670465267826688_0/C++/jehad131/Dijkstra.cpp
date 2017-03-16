#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cctype>

#define SZ 10005
#define INF (1<<29)
using namespace std;

typedef long long Long;


char LS[SZ];
char str1[SZ];

int d[10][10];

int Neg(int x)
{
	if(x<4) return x+4;
	return x-4;
}
/// 1,i,j,k ,-1,-i,-j,-k
void Init()
{
	for(int i=0;i<8;i++) d[0][i] = i , d[i][0] = i;
	for(int i=0;i<8;i++) d[4][i] = Neg(i) , d[i][4] = Neg(i);
	for(int i=1;i<=3;i++) d[i][i] = 4 , d[i][Neg(i)] = 0 , d[Neg(i)][i] = 0 , d[Neg(i)][Neg(i)] = 4;

	d[1][2] = 3 , d[2][3] = 1 , d[3][1] = 2;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++) {
			if(i!=j && d[i][j] == 0 && d[j][i] !=0) {
				d[i][j] = Neg(d[j][i]);
			}

		}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++) {
			d[Neg(i)][j] = Neg(d[i][j]);
			d[i][Neg(j)] = Neg(d[i][j]);
			d[Neg(i)][Neg(j)] = d[i][j];
		}
}
int L,X;
int n;

int dp[SZ][10][4];
int vis[SZ][10][4] , True;

int back(int pos,int v,int st)
{
	if(vis[pos][v][st] == True) return dp[pos][v][st];
	dp[pos][v][st] = 0; vis[pos][v][st] = True;
	if(pos==n) {
		if(st==2 && v == 3) dp[pos][v][st] = 1;
		return dp[pos][v][st];
	}
	dp[pos][v][st] = back( pos+1 , d[v][str1[pos]] , st);
	if(v==1 && st == 0) dp[pos][v][st] = max(dp[pos][v][st] , back(pos,0,st+1));
	if(v==2 && st == 1) dp[pos][v][st] = max(dp[pos][v][st] , back(pos,0,st+1));


	return dp[pos][v][st];

}


int Mult(int x,int y)
{
	int res = 0;
	for(int i=x;i<=y;i++) {
		res = d[res][str1[i]];
		///cout<<res;
	}
	return res;
}

int main()
{

	freopen("Dijkstra.in.txt","rt",stdin);
	freopen("Dijktsra.out","wt",stdout);
	Init();
	int tst,cas;
	scanf("%d",&tst);
	for(cas=1;cas<=tst;cas++) {
		scanf("%d%d",&L,&X);
		n = L*X;
		scanf("%s",str1);
		for(int i=L;i<n;i++) str1[i] = str1[i%L];
		str1[n] = 0;
		for(int i=0;i<n;i++) {
			str1[i] =  str1[i] - 'i' + 1;
			
		}
		
		True++;
		

		if(back(0,0,0)) printf("Case #%d: YES\n",cas);
		else printf("Case #%d: NO\n",cas);


	}


	return 0;
}