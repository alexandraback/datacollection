#include <cstdio>
#include <algorithm>
using namespace std;

void solve(int t)
{
	int a,b;
	double p,p2=1,v;
	scanf("%d%d",&a,&b);
	v = b+2;
	for (int i=0;i<a;++i)
	{
		v = min(v,1+(a-i)+p2*(b-i)+(1-p2)*(b-i+1+b));
		scanf("%lf",&p);
		p2 *= p;
	}
	v = min(v,1+p2*(b-a)+(1-p2)*(b-a+b+1));
	printf("Case #%d: %0.8lf\n",t,v);
}

int main(int argc, char* argv[])
{
	if (argc>1)
		freopen(argv[1],"r",stdin);
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;++t)
		solve(t+1);
	return 0;
}
