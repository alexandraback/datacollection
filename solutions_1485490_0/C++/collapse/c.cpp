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
int n,m,A[110],B[110];
LL a[110],b[110];
LL query(int in1,int in2)
{
	if (in1==n+1 || in2==m+1)
		return 0;
	int i;
	LL tmp,ans,tmp1,tmp2,tmp3;
	ans = 0;
	tmp1 = 0;
	if (A[in1]==B[in2])
	{
		tmp = min(a[in1],b[in2]);
		a[in1] -= tmp;
		b[in2] -= tmp;
		if (b[in2]==0)
			tmp1 = tmp + query(in1,in2+1);
		else
			tmp1 = tmp + query(in1+1,in2);
		a[in1] += tmp;
		b[in2] += tmp;
		return tmp1;
	}
	else
	{
		F(i,in2+1,m)
			if (B[i]==A[in1])
				break;
		if (i==m+1)
			tmp2 = 0;
		else
			tmp2 = query(in1,i);
		tmp3 = query(in1+1,in2);
		ans  = (tmp2 > tmp3)?tmp2:tmp3;
		return ans;
	}
}
int main()
{
	int t,ca=0,i,j;
	LL ans;
	s(t);
	while(t--)
	{
		ca++;
		s(n);
		s(m);
		F(i,1,n)
		{
			sl(a[i]);
			s(A[i]);
		}
		F(i,1,m)
		{
			sl(b[i]);
			s(B[i]);
		}
		ans = query(1,1);
		printf("Case #%d: %lld\n",ca,ans);
	}
	return 0;
}
