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

int T,n,m,k;

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	rep(ii,1,T){
		scanf("%d%d%d",&n,&m,&k);
		int ans=99999999;
		if	(n<=2 || m<=2)	ans=k;
		else	{
		rep(i,1,n-2)	rep(j,1,m-2)
			if	(2*(i+j)+i*j>=k)	ans=min(2*(i+j),ans);
		if	(ans==99999999)	ans=(n-2+m-2)*2+(k-(2*(n-2+m-2)+(n-2)*(m-2)));
		}
		printf("Case #%d: %d\n",ii,ans);
	}
}


