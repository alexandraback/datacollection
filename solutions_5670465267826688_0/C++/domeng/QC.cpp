#include <stdio.h>
#include <vector>
using namespace std;
enum 
{
	Q1 = 1,
	Qi,
	Qj,
	Qk
};
int mult[5][5] ={
	{0,0,0,0,0},
	{0,Q1,Qi,Qj,Qk},
	{0,Qi,-Q1,Qk,-Qj},
	{0,Qj,-Qk,-Q1,Qi},
	{0,Qk,Qj,-Qi,-Q1}
};
char buf[10005];
int abs(int x) {return x<0?-x:x;}
int sgn(int x) {return x<0?-1:1;}
using LL = long long;

int mul(int a,int b)
{
	int c = mult[abs(a)][abs(b)];
	return c * sgn(a) * sgn(b);
}
int pow(int x,LL k)
{
	if (k==0) return Q1;
	if (k==1) return x;
	int h = pow(x,k/2);
	h = mul(h,h);
	if (k%2 == 1) h=mul(h,x);
	return h;
}

int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		LL L,X;
		scanf("%lld %lld",&L,&X);
		scanf("%s",buf);
		vector<int> Qs;
		for (int q=0;q<L;++q)
		{
			if (buf[q]=='i') Qs.push_back(Qi);
			else if (buf[q]=='j') Qs.push_back(Qj);
			else if (buf[q]=='k') Qs.push_back(Qk);
		}
		int sum = Q1;
		for (int q=0;q<L;++q) sum = mul(sum, Qs[q]);
		sum = pow(sum, X);
		bool pos = false;
		//printf("sum =%d\n",sum);
		if ( sum == -Q1 )
		{
			//printf("looks good\n");
			//find real solution
			int len[2]={-1,-1};
			int M = 100*L;
			for (int left=0,ls=Q1;left<M;left++)
			{
				ls = mul(ls, Qs[left%L]);
				if (ls == Qi)
				{
					len[0]= left+1;
					break;
				}
			}
			for (int right=0,rs=Q1;right<M;right++)
			{
				rs = mul(Qs[(M-1-right)%L], rs);
				if (rs == Qk)
				{
					len[1] = right+1;
					break;
				}
			}
			if (len[0]>=0 && len[1]>=0 && len[0]+len[1] < L*X) 
			{
				pos = true;
			}
		}
		printf("Case #%d: %s\n", kase, pos?"YES":"NO");
	}
	return 0;
}