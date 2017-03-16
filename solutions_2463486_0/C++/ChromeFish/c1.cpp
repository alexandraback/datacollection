#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
ifstream in("c.in");
ofstream out("c.out");
#define fo(i,j,k) for (i=j; i<=k; i++)
struct xy
{
	int x, y;
};
xy q[20010];
long long ans[10010];
int cmp(xy a, xy b)
{
	return (a.x<b.x)?1:0;
}
int check(long long n)
{
	int bit[20], m=1, i;
	while (n>0)
	{
		bit[m++]=n % 10;
		n/=10;
	}
	fo(i,1,m/2)
		if (bit[i]!=bit[m-i])
			return 0;
	return 1;
}
int main()
{
	int t, i, j;
	in>>t;
	fo(i, 0, t-1)
	{
		int a, b;
		in>>a>>b;
		q[i*2].x=a-1;q[i*2].y=i*2;
		q[i*2+1].x=b;q[i*2+1].y=i*2+1;
	}
	sort(q,q+2*t,cmp);
	int st=0, lim;
	long long sum=0;
	fo(i, 0, 2*t-1)
	{
		lim=int(sqrt(q[i].x+1e-6));
		fo(j, st+1, lim)
			if (check(j))
			{
				long long sq=(long long)j*j;
				if (check(sq))
					sum++;
			}
		st=lim;
		int v;
		if (q[i].y & 1)
			v=1;
		else
			v=-1;
		ans[q[i].y/2]+=sum*v;
	}
	fo(i, 0, t-1)
		out<<"Case #"<<i+1<<": "<<ans[i]<<endl;
}