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
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define PB push_back
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
vector<pair<int,int> > v;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("sol.out","w",stdout);
	int t,T,i,j,n,k,sp,fp;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    //memset(dp,-1,sizeof(dp));
	    scanf("%d",&n);
	    v.clear();
	    v.resize(n);
	    rep(i,n)
	    {
	        scanf("%d%d",&v[i].first,&v[i].second);
	    }
	    set<pair<int,int> > s1,s2,s3;
	    rep(i,n)
	    {
	        s1.insert(pair<int,int>(v[i].first,i));
	        s2.insert(pair<int,int>(v[i].second,i));
	    }
	    int pts=0,stps=0,pos;
	    while(pts<2*n)
	    {
	        //cout<<pts<<" "<<s1.size()<<" "<<s2.size()<<" "<<s3.size()<<endl;
	        if(!s2.empty()&&s2.begin()->first<=pts)
                {
                    pos=s2.begin()->second;
                    pts+=2;
                    s1.erase(pair<int,int>(v[pos].first,pos));
                    s2.erase(s2.begin());
                    stps++;
                }
            else if(!s3.empty()&&s3.begin()->first<=pts)
            {
                pts++;
                s3.erase(s3.begin());
                stps++;
            }
            else if(!s1.empty()&&s1.begin()->first<=pts)
            {
                pos=s1.begin()->second;
                pts++;
                s1.erase(s1.begin());
                s2.erase(pair<int,int>(v[pos].second,pos));
                s3.insert(pair<int,int>(v[pos].second,pos));
                stps++;
            }
            else break;
	    }
		printf("Case #%d: ",t);
		if(pts<2*n)
            printf("Too Bad\n");
        else
            printf("%d\n",stps);
	}
	return 0;
}


