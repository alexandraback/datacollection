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
#define SIZE 20

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
	if(a/b==c/d)
	{
		a%=b;
		c%=d;
		return a*d<=c*b;
	}
	return a/b<c/d;
}
bool ok[SIZE][SIZE];
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
		int sz=vec.size();
		for(int i=0;i<sz;i++)
		{
			for(int j=i+1;j<sz;j++)
			{
				P p=vec[i],q=vec[j];//‘¬‚¢A’x‚¢
				if(p.first==q.first) ok[i][j]=true;
				else
				{
					ll dist=q.second+(360-p.second);
					ll mt=q.first-p.first,ch=p.first*q.first;
					if(wh(ch,(360-q.second),q.first*mt,dist)) ok[i][j]=false;
					else ok[i][j]=true;
				}
				ok[j][i]=ok[i][j];
			}
		}
		int ret=sz;
		for(int S=0;S<1<<sz;S++)
		{
			bool up=true;
			int cnt=0;
			for(int i=0;i<sz;i++)
			{
				if(S>>i&1)
				{
					for(int j=i+1;j<sz;j++)
					{
						if(S>>j&1)
						{
							if(!ok[i][j])
							{
								up=false;
								break;
							}
						}
					}
				}
				else cnt++;
			}
			if(up) ret=min(ret,cnt);
		}
		print(t,ret);
	}
	return 0;
}
