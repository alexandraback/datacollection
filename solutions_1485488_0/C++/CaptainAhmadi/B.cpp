
//Written by Alex H Ahmadi (alex@hamedahmadi.com)

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
using namespace std;

#define FOR(i,n) for (int i=0;i<(n);i++)
#define FORIT(it,s) for (__typeof(s.begin()) it=s.begin(); it!=s.end(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define P(x) cerr<<#x<<" = "<<x<<endl
#define pb push_back

#define zer(x) memset(x,0,sizeof(x));
#define isin(x,s) (s.find(x)!=s.end())

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;

const int inf=1000000000;
const int maxh=11000;
const int maxn=110;

int d[maxh][maxn][maxn];
int m,n;
int c[maxn][maxn];
int f[maxn][maxn];

int mark[maxn][maxn];

int n4[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

int zdis[maxn][maxn];

/*
int findfszero(int i, int j) {
  int h=0;
  int best=inf;
  mark[i][j]=1;
  if (i==m-1 && j==n-1) {//at exit
	return 0;
  }
 
  for (int k=0;k<4;k++) {
	int i2=i+n4[k][0], j2=j+n4[k][1];
	if (i2<0 || i2>=m || j2<0 || j2>=n) continue;
	
	if (h>c[i2][j2]-50 || f[i][j]>c[i2][j2]-50 || f[i2][j2]>c[i2][j2]-50) continue;
	if (f[i2][j2]>c[i][j]-50) continue;

	best=min(best, 100+findfszero(i,j));
  }  
  return best;
}
*/
void bfs() {
  static int q[maxn*maxn][2];
  const int h=0;
  int e=0;
  q[e][0]=m-1; q[e][1]=n-1;
  e++;
  FOR (i,m) FOR (j,n) zdis[i][j]=inf;
  zdis[m-1][n-1]=0;
  for (int s=0;s<e;s++) {
	int i=q[s][0], j=q[s][1];
	for (int k=0;k<4;k++) {
	  int i2=i+n4[k][0], j2=j+n4[k][1];
	  if (i2<0 || i2>=m || j2<0 || j2>=n) continue;
	
	  if (zdis[i2][j2]!=inf) continue;

	  //cerr<<"i2 j2 "<<i2<<" "<<j2<<endl;

	  if (h>c[i2][j2]-50 || f[i][j]>c[i2][j2]-50 || f[i2][j2]>c[i2][j2]-50) continue;
	  if (f[i2][j2]>c[i][j]-50) continue;

	  zdis[i2][j2]=zdis[i][j]+100;

	  q[e][0]=i2;
	  q[e][1]=j2;
	  e++;
	}
  }
}

int find(int h, int i, int j) {
  if (h<=0) {
	return zdis[i][j];
  }

  if (d[h][i][j]>=0) return d[h][i][j];

  //cerr<<"find "<<h<<" "<<i<<" "<<j<<endl;

  int best=1+find(h-1,i,j);//could try waiting

  if (i==m-1 && j==n-1) {//at exit
	return d[h][i][j]=0;
  }

  for (int k=0;k<4;k++) {
	int i2=i+n4[k][0], j2=j+n4[k][1];
	if (i2<0 || i2>=m || j2<0 || j2>=n) continue;
	
	if (h>c[i2][j2]-50 || f[i][j]>c[i2][j2]-50 || f[i2][j2]>c[i2][j2]-50) continue;
	if (f[i2][j2]>c[i][j]-50) continue;

	//note: waiting.
	if (h-f[i][j]>=20) { //fast move
	  best=min(best,10+find(h-10,i2,j2));
	} else {	  
	  best=min(best,100+find(h-100,i2,j2));
	}
  }  

  return d[h][i][j]=best;
}

int findfs(int h, int i, int j) {
  //cerr<<"findfs "<<h<<" "<<i<<" "<<j<<endl;

  if (i==m-1 && j==n-1) {//at exit
	return 0;
  }

  int best=find(h,i,j);
  mark[i][j]=1;
 
  for (int k=0;k<4;k++) {
	int i2=i+n4[k][0], j2=j+n4[k][1];
	if (i2<0 || i2>=m || j2<0 || j2>=n) continue;
	
	if (mark[i2][j2]) continue;

	if (h>c[i2][j2]-50 || f[i][j]>c[i2][j2]-50 || f[i2][j2]>c[i2][j2]-50) continue;
	if (f[i2][j2]>c[i][j]-50) continue;

	best=min(best, findfs(h,i2,j2));
  }  
  return best;
}


void clear() {
  memset(d,-1, sizeof d);
  memset(mark,0,sizeof mark);
}

void solve(int cnum) {
  cout<<"Case #"<<cnum<<": ";

  int h;
  cin>>h>>m>>n;
  FOR (i,m) FOR (j,n) cin>>c[i][j];
  FOR (i,m) FOR (j,n) cin>>f[i][j];

  //cerr<<"albaoe"<<endl;
  bfs();
  //cerr<<"oooalbaoe"<<endl;
  /*cerr<<endl;
  FOR (i,m) {
	FOR (j,n) cerr<<zdis[i][j]<<" ";
	cerr<<endl;
	}*/

  for (int e=1;e<=h;e++)
	for (int i=0;i<m;i++)
	  for (int j=0;j<n;j++)
	  find(e,i,j);


  int ans=inf;
  //FOR (i,m) FOR (j,n) ans=min(ans, find(h,i,j));
  ans=findfs(h,0,0);
  cout<<ans/10<<"."<<ans%10<<endl;

}

int main() {
  int nt;
  cin>>nt;
  for (int cnum=1; cnum<=nt; cnum++) {
	clear();
	solve(cnum);
  }
  return 0;
}
