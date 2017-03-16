#include<cstdio>
#include<cstring>
#include<vector>
#include<deque>
#include<utility>
#include<algorithm>
#define LL long long int
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define F(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int a[30],b[30],c[30],c1,c2,fl,n;
void recurse(int in,int s1,int s2)
{
	if (in==n+1 && s1==s2 && s1!=0)
	{
		fl = 1;
		return;
	}
	if (in==n+1)
		return;
	if (s1==s2 && s1!=0)
	{
		fl = 1;
		return;
	}
	b[c1] = a[in];
	c1++;
	recurse(in+1,s1+a[in],s2);
	if (fl==1)
		return;
	c1--;
	c[c2] = a[in];
	c2++;
	recurse(in+1,s1,s2+a[in]);
	if (fl==1)
		return;
	c2--;
	recurse(in+1,s1,s2);
}
int main()
{
	int i,ca=0,j,k=1,s1,s2,t;
	s(t);
	while(t--)
	{
		fl = 0;
		ca++;
		s(n);
		F(i,1,n)
			s(a[i]);
		c1=0;
		c2=0;
		recurse(1,0,0);
		printf("Case #%d:\n",ca);
		if (fl==0)
			printf("Impossible\n");
		else
		{
			s1 = 0;
			F(i,0,c1-2)
				printf("%d ",b[i]);
			printf("%d\n",b[c1-1]);
			F(i,0,c2-2)
				printf("%d ",c[i]);
			printf("%d\n",c[c2-1]);
		}
	}
	return 0;
}
