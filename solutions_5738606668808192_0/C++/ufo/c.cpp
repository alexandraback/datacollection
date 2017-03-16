#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,ans[20],e;
class bn
{
	public:
	int w[10],len;
	int base;
	bn(const bn &src)=default;
	bn(int x,long long k):base(x)
	{
		len=0;
		bool s[40];
		while(k)
		{
			s[++len]=(k&1);
			k>>=1;
		}
		len=0;
		memset(w,0,sizeof(w));
		for(int i=n;i;--i)
		{
			*this=(*this)*base+s[i];
		}
	}
	bn operator = (const bn& src)
	{
		base=src.base;
		memcpy(w,src.w,sizeof(w));
		len=src.len;
		return *this;
	}
	bool operator >= (int k)
	{
		if(len>=2)
			return 1;
		return w[1]*10000+w[0]>=k;
	}
	int operator % (int y)
	{
		int ret=0;
		for(int i=len;~i;--i)
			ret=(ret*10000+w[i])%y;
		return ret;
	}
	bn operator * (const int y)
	{
		for(int i=0;i<=len;++i)
			w[i]*=y;
		for(int i=0;i<=len;++i)
		{
			w[i+1]+=w[i]/10000;
			w[i]%=10000;
		}
		if(w[len+1])
			++len;
		return *this;
	}
	bn operator + (int y)
	{
		w[0]+=y;
		for(int i=0;i<=len;++i)
		{
			w[i+1]+=w[i]/10000;
			w[i]%=10000;
		}
		if(w[len+1])
			++len;
		return *this;
	}
	void print()
	{
		for(int i=len;~i;--i)
		{
			if(len!=i&&w[i]<1000)
				printf("0");
			if(len!=i&&w[i]<100)
				printf("0");
			if(len!=i&&w[i]<10)
				printf("0");
			printf("%d",w[i]);
		} 
	}
};
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int t,tt;
	long long i;
	int j,k;
	scanf("%d",&tt);
	for(t=1;t<=tt;++t)
	{
		scanf("%d%d",&n,&e);
		printf("Case #1:\n");
		for(i=1LL<<(n-1)|1;i<=(1LL<<n)&&e;i+=2)
		{
			for(j=2;j<=10;++j)
			{
				bn r=bn(j,i);
				for(k=2;k<=1000&&r>=k*k;++k)
					if(r%k==0)
					{
						ans[j]=k;
						break;
					}
				if(k>=1000||!(r>=k*k))
					break;
			}
			//printf("%lld %d\n",i,j);
			//bn r=bn(j,i);
			//r.print();puts("");
			//printf("%d\n",r.base); 
			//printf("%d\n",r%13);
			if(j==11)
			{
				--e;
				for(j=n-1;~j;--j)
					if((1LL<<j)&i)
						printf("1");
					else
						printf("0");
				for(j=2;j<=10;++j)
					printf(" %d",ans[j]);
				puts("");
			}
		}
	}
	return 0;
}

