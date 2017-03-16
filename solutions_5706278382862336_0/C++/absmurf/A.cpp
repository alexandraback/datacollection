#include<iostream>
#include<stdio.h> 
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<stack>
#include<assert.h>
#include<limits.h>
#define tr(i) for(typeof(i.begin()) it=i.begin(); it!=i.end();it++)
#define pb push_back
#define mp make_pair
#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,s,n) for(int i=s;i<n;i++)
#define s(n) scanf("%d",&n)
#define XX first
#define X first
#define Y second
#define all(a) a.begin(),a.end()
#define YY second.first
#define ZZ second.second
#define fill(a,b) memset(a,b,sizeof(a))
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define SZ(x) (int)(x.size())
#define lin(val,j) (DP[j]-val*D[j])
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MN 100000

LL gcd(LL a, LL b)
{
	if(a<b) swap(a,b);
	if(a%b==0) return b;
	return gcd(b,a-b);
}

int main()
{	
	int T; s(T);
	char x;
	REP(c,T)
	{
		LL a,b,g;
		cin>>a; cin>>x; cin>>b;
		int pa=0,pb=0;
		g=gcd(a,b);
		a/=g; b/=g;
		//cout<<a<<" "<<b<<endl;
		while(b%2==0) b/=2,pb++;
		while(a!=0) a/=2,pa++;
		//cout<<pa<<" "<<pb<<endl;
		//cout<<a<<" "<<b<<endl;
		if(b!=1) printf("Case #%d: impossible\n",c+1);
		else printf("Case #%d: %d\n",c+1,pb-pa+1);
	}
	return 0;
}
