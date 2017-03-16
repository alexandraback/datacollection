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
vector<int> v;
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("Aout.txt","w",stdout);
	int t,T,a,n,i,val,mncost;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    v.clear();
	    scanf("%d%d",&a,&n);
	    //cout<<a<<endl;
	    rep(i,n)
	    {
	        scanf("%d",&val);
	        //cout<<val<<endl;
	        v.PB(val);
	    }
	    sort(v.begin(),v.end());
	    int cost=0;
	    mncost=v.size();
	    rep(i,n)
	    {
	        if(a==1)
                break;
	        if(v[i]<a)
	        {
                a+=v[i];
                mncost=min(mncost,cost+(int)v.size()-i-1);
	        }
            else
            {
                mncost=min(mncost,cost+(int)v.size()-i);
                while(a<=v[i])
                {
                    a=2*a-1;
                    cost++;
                }
                a+=v[i];
                mncost=min(mncost,cost+(int)v.size()-i-1);
            }
	    }
	    //cout<<a<<endl;
	    cost+=(v.size()-i);
		printf("Case #%d: %d\n",t,mncost);
	}
	return 0;
}

