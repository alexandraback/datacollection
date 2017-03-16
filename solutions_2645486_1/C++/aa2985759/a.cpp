#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int c[11000];
int N;

void upd(int n)
{
	while(n<=N)
		c[n]++,n+=n&(-n);
}
int get(int n)
{
	int ans=0;
	while(n)
		ans+=c[n],n-=n&(-n);
	return ans;
}
int BS(int n)
{
	if(get(N)==get(n))
		return N+1;
	int l=n+1,r=N,mid;

	while(l<r)
	{
		mid=(l+r)/2;
		if(get(mid)==get(n))
			l=mid+1;
		else
			r=mid;
	}
	return l;
}
struct NN
{
	int a,ind;
}nn[11000];

int cmp(NN a,NN b)
{
	if(a.a==b.a)
		return a.ind<b.ind;
	return a.a<b.a;
}
int rht[11000];
int a[11000];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("b.out","w",stdout);
	int t,ii=0;
	int n,i,j,k;
	long long R,E;

	cin>>t;
	while(t--)
	{
		memset(c,0,sizeof(c));
		cin>>E>>R>>n;
		N=n;

		for(i=1;i<=n;i++)
			scanf("%d",&nn[i].a),nn[i].ind=i,a[i]=nn[i].a;
		sort(nn+1,nn+1+n,cmp);

		for(i=n;i>=1;i--)
			rht[nn[i].ind]=BS(nn[i].ind),upd(nn[i].ind);

		long long now=E;

		long long ans=0;
		if(R>E)
			R=E;
		for(i=1;i<=n;i++)
		{
			if(rht[i]>n)
			{
				ans+=(now+0ll)*a[i];
				now=0;
			}
			else
			{
				long long rem=now+R*(rht[i]-i);
				if(rem>E)
				{
					rem-=E;
					if(rem>now)
						rem=now;
					ans+=rem*a[i];
					now-=rem;
				}
			}
			now+=R;
		}
		printf("Case #%d: ",++ii);
		cout<<ans<<endl;
	}
}