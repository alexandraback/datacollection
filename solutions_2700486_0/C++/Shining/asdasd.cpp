#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define ps system("pause")
#define message printf("*\n")
#define pb push_back
#define X first
#define Y second
#define PII pair<int,int>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)

typedef long long ll;

using namespace std;

double a[110][110];
int T,n,x,y,st;

int main(){
	freopen("K.in","r",stdin);
	freopen("K.out","w",stdout);
	scanf("%d",&T);
	rep(vv,1,T){
		scanf("%d%d%d",&n,&x,&y);
		st=-2;
		for	(int i=1;n>=i*2-1;i+=2)	n-=i*2-1,st+=2;
		if	(x+y<=st){
			printf("Case #%d: %.10lf\n",vv,1.0);
			continue;
		}
		if	(x+y>st+2){
			printf("Case #%d: %.10lf\n",vv,0.0);
			continue;
		}
		st++;
		memset(a,0,sizeof a);
		a[0][0]=1;
		rep(i,1,n){
			a[i][0]=1;
			rep(j,1,i)  ,
				a[i][j]=(a[i-1][j]+a[i-1][j-1])/2;
		}
		printf("Case #%d: %.10lf\n",vv,a[n][y+1]);
	}
}


