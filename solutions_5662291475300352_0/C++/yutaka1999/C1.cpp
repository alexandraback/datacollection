#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <stack>
#include <deque>
#include <cmath>
#define EPS 1e-10

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
typedef long double ld;

void print(int t,int ans)
{
	printf("Case #%d: %d\n",t,ans);
}
bool wh(ll a,ll b,ll c,ll d)//a/b <=? c/d
{
	//			printf("%lld %lld %lld %lld\n",a,b,c,d);
	if(a/b==c/d)
	{
		a%=b;
		c%=d;
		return a*d<=c*b;
	}
	return a/b<c/d;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int n;
		scanf("%d",&n);
		vector <P> vec;
		for(int i=0;i<n;i++)
		{
			int d,h,m;
			scanf("%d %d %d",&d,&h,&m);
			for(int j=0;j<h;j++) vec.push_back(P(m+j,d));
		}
		sort(vec.begin(),vec.end());
		if(vec.size()==1) print(t,0);
		else if(vec.size()==2)
		{
			P p=vec[0],q=vec[1];//‘¬‚¢A’x‚¢
			if(p.first==q.first) print(t,0);
			else
			{
				ll dist=q.second+(360-p.second);
				ll mt=q.first-p.first,ch=p.first*q.first;
				if(wh(ch,(360-q.second),q.first*mt,dist)) print(t,1);
				else print(t,0);
			}
		}
	}
	return 0;
}
