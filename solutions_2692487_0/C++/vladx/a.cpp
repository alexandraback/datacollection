#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdio.h>
#define ZERO(X) memset(X,0,sizeof(X))
#define FOR(I,N) for (I=0;I<(N);++I)
#define REV(I,N) for (I=(N)-1;I>=0;--I)
#define FORK(I,K,N) for (I=(K);I<(N);++I)
#define REVK(I,K,N) for (I=(K);I>=0;--I)
#define pb push_back
#define sci(d) scanf("%d",&d)
#define scll(l) scanf("%lld",&l)
#define scull(l) scanf("%llu",&l)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int m[1000],n;

int dfs (int a, int i)
{
	if (i>=n) return 0;
	if (a>m[i]) return dfs(a+m[i],i+1);
	return min(n-i,1+dfs(2*a-1,i));
}

int main ()
{
	cin.sync_with_stdio(false);
	int j,t;
	cin>>t;
	FOR(j,t)
	{
		int a,i,ans;
		cin>>a>>n;
		FOR(i,n) cin>>m[i];
		sort(m,m+n);
		if (a==1) ans=n;
		else ans=dfs(a,0);
		cout<<"Case #"<<j+1<<": "<<ans<<endl;
	}
	return 0;
}