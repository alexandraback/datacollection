#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <limits>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <map>
#include <set>
#define PI (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=((n)-1);i>=0;i--)
#define rrep(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
vector<int> lg[1005],rg[1005];
bool vis[1005];
int rmatch[1005];
bool bpm(int node)
{
	Rep(i,lg[node].size())
	{
		int cur=lg[node][i];
		if(vis[cur])
			continue;
		vis[cur]=true;
		if(rmatch[cur]<0||bpm(rmatch[cur]))
		{
			rmatch[cur]=node;
			return true;
		}
	}
	return false;
}
int main()
{
	//ios_base::sync_with_stdio(false);
	char a[25],b[25];
    freopen("C-large.in","r",stdin);
    freopen("Cout.txt","w",stdout);
    int t,T;
    cin>>T;
    //cout<<T<<endl;
    for(t=1;t<=T;t++)
    {
    	int n;
    	cin>>n;
    	//cout<<n<<endl;
    	map<string,int> lm,rm;
    	vector<string> l,r;
    	Rep(i,n)
    	{
    		scanf("%s%s",a,b);
    		l.push_back(a);
    		r.push_back(b);
    		lm[a]=0;
    		rm[b]=0;
    	}
    	map<string,int>::iterator it1=lm.begin(),it2=rm.begin();
    	for(int i=0;i<lm.size();i++)
    	{
    		it1->second=i;
    		lg[i].clear();
    		it1++;
    	}
    	for(int i=0;i<rm.size();i++)
    	{
    		it2->second=i;
    		rg[i].clear();
    		it2++;
    	}
    	Rep(i,l.size())
    	{
    		int ll=lm[l[i]],rr=rm[r[i]];
    		lg[ll].push_back(rr);
    		rg[rr].push_back(ll);
    	}
    	//cout<<"oria"<<endl;
    	int mt=0;
    	memset(rmatch,-1,sizeof(int)*rm.size());
    	for(int i=0;i<lm.size();i++)
    	{
    		memset(vis,0,sizeof(bool)*rm.size());
    		if(bpm(i))
    		{
    			mt++;
    		}
    	}
    	//cout<<mt<<endl;
    	int ans=n-(lm.size()+rm.size()-mt);
    	printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}