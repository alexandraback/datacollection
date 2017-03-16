#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstdlib>
#include<sstream>
#include<string.h>
#include<set>
#include<map>
#include<assert.h>
#include<fstream>
#include<ctime>
#include<queue>
#include<vector>
#include<stack>
#include<list>
#include<math.h>

using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long int lli;
typedef unsigned long long ull;

#define MAXN 1000005
#define INF 2147483647
#define MOD 1000000007
#define pb push_back 
#define sz(a) int((a).size())
#define var(a,b)  __typeof(b) a = b
#define FOR(x,a,b) for(int (x) = (a);(x)<=(b);(x)++)
#define rep(x,n)   for(int (x)=0;(x)<(n);(x)++)
#define tr(c,it)  for(var(it,(c).begin());it!=(c).end();++it)
#define all(c) c.begin(),c.end()
#define mset(a,b) memset(a,b,sizeof(a)) 
#define MAX(a, b) (a) > (b) ? (a) : (b)


int main()
{
	int t,a,b,k;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&t);
    rep(q,t)
    {
    	scanf("%d%d%d",&a,&b,&k);
    	int ans = 0;
    	FOR(i,0,a-1)
    	FOR(j,0,b-1)
    	{
    		if((i&j) < k)
    			ans++;
    	}
    	printf("Case #%d: %d\n",q+1,ans);
    }
	

	return 0;
}
