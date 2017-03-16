#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<iomanip>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define uii unsigned long long int
#define pi 2*acos(0.0)
#define eps 1e-9
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(a) (int)a.size()
#define inf 2147483640

#define mx 1414213560

using namespace std;

const int debug= 0;
ii r,tt;

int call(ii x,ii y);
bool calc(ii st,ii end);

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int x,t;
	scanf("%d",&t);
	
	for (x=1;x<=t;++x)
	{
		scanf("%lld %lld",&r,&tt);
		ii hi= (ii)(mx-1)*2+r;
		
		int ans= call(r,hi);
		//puts("--");
		//cout<<calc(r,r)<<endl;
		
		printf("Case #%d: %d\n",x,ans);
	}
	
	return 0;	
}

int call(ii x,ii y)
{
	ii st= x,end= y,mid;
	int loop= 0;
	
	while (st<end)
	{
		loop++;
		
		mid= (st+end)/2;
		if ((mid&1)!=(r&1)) mid--;
		
		if (debug) cout<<st<<" "<<end<<" "<<mid<<endl;
		
		if (calc(x,mid)) st= mid+2;
		else end= mid-2;
		if (debug) cout<<st<<" "<<end<<endl;
		
		//if (loop==100) break;
	}
	
	if (!calc(x,st)) st-= 2;
	
	if (debug) cout<<x<<" -- "<<st<<endl;
	if (debug) cout<<calc(x,st)<<endl;
	
	if (st<x) return 0;
	return (st-x)/2+1;
}

bool calc(ii st,ii end)
{
	uii n= (end-st)/2+1;
	uii sum= n*(st+end)/2;
	if (debug) cout<<n*(st+end)<<endl;
	uii a= 2*sum+n;
	if (debug) cout<<a<<endl;
	
	ii c= (uii)tt-a;
	if (c<0) return 0;
	return 1;
}
