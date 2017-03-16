#include <cstdio>
#include <cstring>

using namespace std;

long long xx=4223372036854775806;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	long long l,r,mid,rd,m;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ++ii)
	{
		scanf("%I64d%I64d", &rd, &m);
		l=1;
		r=xx;
		while (l+1<r)
		{
			//printf("%I64d %I64d\n",l,r);
			//char ch;
			//scanf("%c",&ch);
			mid=(l+r)/2;
			long long tt=xx/mid;
			if(((2*mid+2*rd-1)>=tt)||(2*mid+2*rd-1)*mid>m)
				r=mid;
			else
				l=mid;
		}
		printf("Case #%d: ", ii);
		printf("%I64d\n", l);
	}
	return 0;
}