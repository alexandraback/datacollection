#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define N 100004
#define M 1003
#define ll long long
#define inf 1e30
#define mod 20100501
#define lson (id<<1)
#define rson (id<<1|1)

#define eps 1e-8
#define pii pair<int,int>
#define pdd pair<double,double>
#define It map<unsigned,string>::iterator
#define MP(i,j) make_pair(i,j)

int n,m;
double p[N],sump[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	int cas,pcas=1;
	double pp;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&m);
		sump[0]=1;
		for(int i=1;i<=n;i++){
			scanf("%lf",&p[i]);
			sump[i]=sump[i-1]*p[i];
		}
		double ans=inf;
		//Keystrokes if I keep typing
		pp=sump[n];

		ans=min(ans,pp*(m-n+1)+(1.0-pp)*(m-n+1+m+1));
		//Keystrokes if I press enter right away
		ans=min(ans,(double)m+2);
		//Keystrokes if I press backspace X times
		for(int i=1;i<n;i++){
			pp=sump[n-i];
			ans=min(ans,pp*(i+m-(n-i)+1)+(1.0-pp)*(i+m-(n-i)+1+m+1));
		}
		ans=min(ans,(double)n+m+1);
		printf("Case #%d: %.6lf\n",pcas++,ans);
	}
	return 0;
}

