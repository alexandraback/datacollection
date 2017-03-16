#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

//MRËæ»úËØÊý²âÊÔ
const int REPEAT=40; 
const int L=16;
inline unsigned long long mym(unsigned long long a,unsigned long long b,const unsigned long long& mod)
{
	unsigned long long ret=0;
	a%=mod;
	b%=mod;
	while(b)
	{
		if(b&1)
		{
			ret+=a;
			ret%=mod;
		}
		a<<=1;
		a%=mod;
		b>>=1;
	}
	return ret;
}
inline bool mr(unsigned long long n)
{
	if(n==2)
	{
		return true;
	}
	if(!(n&1))
	{
		return false;
	}
	unsigned long long nt=n-1,ntt,ret,lret,it;
	int z=0,zt,repeat;
	srand(time(NULL));
	while(!(nt&1))
	{
		++z;
		nt>>=1;
	}
	repeat=REPEAT;
	while(repeat--)
	{
		it=((((unsigned long long)rand())<<32)+(((unsigned long long)rand())<<16)+rand())%(n-1)+1;
		ntt=nt;
		zt=z;
		ret=1;
		while(ntt)
		{
			if(ntt&1)
			{
				ret=mym(ret,it,n);
			}
			it=mym(it,it,n);
			ntt>>=1;
		}
		while(zt--)
		{
			lret=ret;
			ret=mym(ret,ret,n);
			if(ret==1&&lret!=1&&lret!=n-1)
			{
				
				return false;
			}
		}
		if(ret!=1)
		{
			return false;
		}
	}
	return true;
}

long long po[11][17];
inline void init(void)
{
	int i,j;
	for(i=2;i<=10;++i)
	{
		po[i][0]=1;
	}
	for(i=2;i<=10;++i)
	{
		for(j=1;j<=16;++j)
		{
			po[i][j]=po[i][j-1]*i;
		}
	}
}

inline long long conv(int bits,int p)
{
	long long ans=0;
	int i;
	for(i=0;i<16;++i)
	{
		if(bits&(1<<i))
		{
			ans+=po[p][i];
		}
	}
	return ans;
}

vector<int> ans;

inline int finddiv(long long n)
{
	if(!(n&1))
	{
		return 2;
	}
	int i;
	long long lim=max(n-1,2LL+(int)sqrt(n*1.1));
	for(i=3;i<=lim;i+=2)
	{
		if(!(n%i))
		{
			return i;
		}
	}
}
int main()
{
	init();
	freopen("large.out","w",stdout);
	srand((unsigned int)time(NULL));
	int i,j,t;
	for(i=(1<<(L-2))-1;i>=0;--i)
	{
		t=(1<<(L-1))+(i<<1)+1;
//		for(j=15;j>=0;--j)
//		{
//			putchar(t&(1<<j)?'1':'0');
//		}
//		putchar('\n');
		for(j=2;j<=10;++j)
		{
			if(mr(conv(t,j)))
			{
				break;
			}
		}
		if(j>10)
		{
			ans.push_back(t);
		}
		if(ans.size()>=500)
		{
			break;
		}
	}
	puts("Case #1:");
	for(i=0;i<500;++i)
	{
		t=ans[i];
		printf("%lld%lld",conv(t,10),conv(t,10));
		for(j=2;j<=10;++j)
		{
			printf(" %d",finddiv(conv(t,j)));
		}
		putchar('\n');
	}
	return 0;
}
