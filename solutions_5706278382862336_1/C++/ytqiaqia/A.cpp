#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <queue>
using namespace std;

struct node{
	long long x, y;
	node(){}
	node(long long xx, long long yy){x=xx,y=yy;}
	const bool operator < (const node &b) const
	{
		if (x==b.x) return y<b.y;
		return x<b.x;
	}
};

queue<node> Q;

void init()
{
	Q.push(node(1,1));
	Q.push(node(0,0));
	for (int i = 0; i < 40; ++i)
	{
		int len = Q.size();
	}
}

long long gcd(long long x, long long y)
{
	return (!y)?x:gcd(y, x%y);
}

bool jd(long long x)
{
	return (x&(x-1)) ==0;
}

int main()
{
	int T;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	long long p, q;
	scanf("%d\n",&T);
	for(int cas = 1; cas <= T; ++cas)
	{
		int ans =0;
		scanf("%lld/%lld\n",&p,&q);
		//cout<<p<<" "<<q<<endl;
		long long pq = gcd(p,q);
		p/=pq;
		q/=pq;
		if (q>1099511627776L||!jd(q)){printf("Case #%d: impossible\n", cas);continue;}
		while(q>p)
		{//cout<<"test: "<<q<<endl;
			q>>=1;
		ans++;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}