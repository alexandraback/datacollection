#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define repl(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define INF (1<<28)
#define PI 3.14159265358979323846264338327950
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pll pair<i64,i64>
#define pmp make_pair


using namespace std;




#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)




typedef unsigned long long i64;
typedef unsigned long long ui64;

#define mx 1002

i64 B,T;
i64 typeB[mx],acheB[mx];
i64 typeT[mx],acheT[mx];

struct node
{
	i64 a,b,c,d;
	node(i64 x,i64 y,i64 z,i64 m)
	{
		a=x;
		b=y;
		c=z;
		d=m;
	}
	bool operator < ( const node& p ) const {      
		if(a==p.a)
		{
			if(b==p.b)
			{
				if(c==p.c)
				{
					return d<p.d;
				}
				return c<p.c;
			}
			return b<p.b;
		}
		return a<p.a;
	}
};
map<node,i64>mp;
i64 call(i64 ib,i64 leftB,i64 it,i64 leftT)
{
	if(ib>B) return 0;
	if(it>T) return 0;
	node temp=node(ib,leftB,it,leftT);
	
	//if(mp.find(temp)!=mp.end())	{		return mp[temp];	}
	if(leftB==0)return call(ib+1,acheB[ib+1],it,leftT);
	if(leftT==0)return call(ib,leftB,it+1,acheT[it+1]);
	if(typeB[ib]==typeT[it])
	{
		
		i64 ex=min(leftB,leftT);
		i64 ret1=ex+call(ib,leftB-ex,it,leftT-ex);
		//mp[temp]=ret1;
		return ret1;
	}
	else
	{
		i64 ret1= call(ib+1,acheB[ib+1],it,leftT);
		i64 ret2= call(ib,leftB,it+1,acheT[it+1]);
		//mp[temp]=max(ret1,ret2);
		return max(ret1,ret2);
	}
	
}
int main()
{	
	READ("in");
	WRITE("BB2.txt");
	
	int kas=0;
	int t;
	cin>>t;
	while(t--)
	{
		//mp.clear();
		cin>>B>>T;
		for(int i=1;i<=(int)B;i++)
		cin>>acheB[i]>>typeB[i];
		
		for(int i=1;i<=(int)T;i++)
		cin>>acheT[i]>>typeT[i];
		
		i64 ret=call(1,acheB[1],1,acheT[1]);
		printf("Case #%d: ",++kas);
		cout<<ret<<endl;
	}
	
}
