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
	#ifndef ONLINE_JUDGE
    freopen("D-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    
    double temp;
    for(int tt=1;tt<=t;tt++)
    {
    	int n;
    	vector<double> a1,a2,a3;
    	scanf("%d",&n);
    	for(int i=0;i<n;i++)
		{
			scanf("%lf",&temp);
			a1.pb(temp);
		}

    	for(int i=0;i<n;i++)
    	{
			scanf("%lf",&temp);
			a2.pb(temp);
		}
		

    	sort(a1.begin(),a1.end());
    	sort(a2.begin(),a2.end());
    	a3=a2;

    	int p1,p2;
    	p1=0;
    	for(int i=0;i<n;i++)
    	{
    		int mi=-1;
    		for(int j=a2.size()-1;j>=0&&a2[j]>a1[i];j--) mi=j;
    		if(mi!=-1)
    		{
    			//cerr<<a2.size()<<" "<<mi<<endl;
    			a2.erase(a2.begin()+mi);
    		}
    		else
    		{
    			p1+=n-i;
    			break;
    		}
    	}

    	a2=a3;
    	p2=0;
    	for(int i=0;i<n;i++)
    	{
    		if(a1[i]<*a2.begin()) a2.pop_back();
    		else
    		{
    			p2++;
    			a2.erase(a2.begin());
    		}
    	}

    	printf("Case #%d: %d %d\n",tt,p2,p1);
    }
    return 0;
    
}