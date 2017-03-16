#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cctype>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<map>
#include<set>
#define pi (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("Cout.txt","w",stdout);
	int t,T,n,tot[50],w[50],e[50],s[50],dd[50],dp[50],ds[50],d[50],i,j,k;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    scanf("%d",&n);
	    map<int,vector<int> > days;
	    int val;
	    rep(i,n)
	    {
	        cin>>d[i]>>tot[i]>>w[i]>>e[i]>>s[i]>>dd[i]>>dp[i]>>ds[i];
	        rep(j,tot[i])
	        {
	            if(days.find(d[i]+j*dd[i])==days.end())
	            {
	                val=d[i]+j*dd[i];
                    days[val]=vector<int>(0);
	            }
	            val=d[i]+j*dd[i];
	            days[val].PB(s[i]+j*ds[i]);
	            days[val].PB(w[i]+j*dp[i]);
	            days[val].PB(e[i]+j*dp[i]);
	        }
	    }
	    map<int,int> strn;
	    map<int,vector<int> > ::iterator it;
	    int succ=0,k;
	    for(it=days.begin();it!=days.end();it++)
	    {
	        vector<int> v=it->second;
	        vector<Pii > nws;
            for(j=0;j<v.size();j+=3)
	        {
	            bool ok=false;
	            for(k=v[j+1];k<v[j+2];k++)
	            {
	                if(strn.find(k)==strn.end()||strn[k]<v[j])
	                {
	                    nws.PB(Pii(v[j],k));
	                    if(strn.find(k)==strn.end())
                            strn[k]=0;
	                    ok=true;
	                }
	            }
	            if(ok)
                    succ++;
	        }
	        for(i=0;i<nws.size();i++)
	        {
	            strn[nws[i].second]=max(strn[nws[i].second],nws[i].first);
	        }
	    }
		printf("Case #%d: %d\n",t,succ);
	}
	return 0;
}

