#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>
 
#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define RFOR(i,x,y) for(int i=(x);i>=(y);i--)
#define ABS(x) ((x)>0?(x):-(x))
#define SQ(x) ((x)*(x))
#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
 
using namespace std;
 
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<double> vd;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("B-small-attempt0.in","r",stdin);
    #endif

    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
    	unsigned int a, b, k;
    	scanf("%u%u%u",&a,&b,&k);
    	int cnt=0;
    	for(unsigned int i=0;i<a;i++)
    		for(unsigned int j=0;j<b;j++)
    			if((i&j)<k)
    				cnt++;
    	printf("Case #%d: %d\n",tt,cnt);

    }

    return 0;
}