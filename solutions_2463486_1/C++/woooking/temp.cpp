#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

int cases;
std::vector<long long> vec;
std::vector<long long> veci;


bool IsHuiWen(long long a)
{
	char c[15]={0};
	int i=0;
	while(a!=0)
	{
		c[i++]=a%10+'0';
		a/=10;
	}
	int l=strlen(c);
	bool ok=true;
	for(i=0;i<l;++i)
	{
		if(c[i]!=c[l-i-1])
		{
			ok=false;
			break;
		}
	}
	return ok;
}

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	for(long long i=1;i<=10000000;++i)
	{
		if(IsHuiWen(i))
		{
			long long h=i*i;
			if(IsHuiWen(h))vec.push_back(h),veci.push_back(i);
		}
	}
	scanf("%d",&cases);
	for(int i=1;i<=cases;++i)
	{
		long long a,b;
		scanf("%I64d%I64d",&a,&b);	
		printf("Case #%d: %d\n",i,std::upper_bound(vec.begin(),vec.end(),b)-std::lower_bound(vec.begin(),vec.end(),a));
	}
	return 0;
}