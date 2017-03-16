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

string arr[10];

int adm[10][10];
int vis[10];

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("C-small-attempt0.in","r",stdin);
    #endif
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
    	int n,m;
    	int a,b;
    	scanf("%d%d",&n,&m);
    	for(int i=0;i<n;i++) cin>>arr[i];

    	mset(adm,0);
    	for(int i=0;i<m;i++)
    	{
    		scanf("%d%d",&a,&b);
    		adm[a-1][b-1]=adm[b-1][a-1]=1;
    	}

    	vector<int> perm;
    	string ma="";
    	string temp;

    	for(int i=0;i<n;i++) perm.pb(i);
    	do
    	{
    		temp=arr[perm[0]];
    		bool f1=true;
    		stack<int> a;
    		a.push(perm[0]);
    		for(int i=1;i<perm.size();i++)
    		{
    			while(!adm[a.top()][perm[i]])
    			{
    				a.pop();
    				if(a.size()==0) break;
    			}
    			if(a.size()==0)
    			{
    				f1=false;
    				break;
    			}
    			else
    			{
    				temp+=arr[perm[i]];
    				a.push(perm[i]);
    			}
    		}
    		if(f1)
    		{
    			if(ma==""||ma>temp) ma=temp;
    		}
    	} while(next_permutation(perm.begin(),perm.end()));

    	cout<<"Case #"<<tt<<": "<<ma<<endl;
    }

    return 0;
}