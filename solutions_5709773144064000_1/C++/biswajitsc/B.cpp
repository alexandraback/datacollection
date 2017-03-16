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
	//#ifndef ONLINE_JUDGE
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    //#endif
    int t;
    double c,f,x;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
    	scanf("%lf%lf%lf",&c,&f,&x);
    	double mi=1e8;
    	double curr=2.0;
    	double curc=0.0;
    	double curt=0.0;
    	// cerr<<"Done "<<tt<<endl;
    	while(1)
    	{
    		if(curt+x/curr<mi)
    			{
    				mi=curt+x/curr;
    				//printf("%lf %lf %lf\n",curt,curr,curt+x/curr);
    			}
    		else if(curt+x/curr>mi) break;
    		curt+=c/curr;
    		curr+=f;
    	}
    	printf("Case #%d: %.7lf\n",tt,mi);
    }
    return 0;
    
}