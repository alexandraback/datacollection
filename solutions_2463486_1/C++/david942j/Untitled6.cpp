//by david942j
#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=10000002;
long long list[100];
int top;
bool pali(long long x)
{
	char buf[110];
	int n=sprintf(buf,"%lld",x);
	for(int i=0;i<n/2;i++)
		if(buf[i]!=buf[n-i-1])
			return false;
	return true;
}
bool beauty(long long x)
{
	if(pali(x) && pali(x*x))
		return true;
	return false;
}
void precalc()
{
	for(int i=1;i<=3000000;i++)
		if(i%10<=3&&beauty(i))
			list[top++]=i;
	//fprintf(stderr,"%d\n",top);
	//for(int i=0;i<top;i++)
	//	fprintf(stderr,"%d\n",list[i]);
	//list[top++]=1LL<<8;
}
int qry(long long a)
{
	if(a==0)return 0;
	int low=0,up=top-1;
	while(low<=up){
		int mid=low+up>>1;
		if(list[mid]*list[mid] <= a)low=mid+1;
		else up=mid-1;
	}
	return up+1;
}
int main()
{
	int T,w=1;
	long long a,b;
	precalc();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		printf("Case #%d: ",w++);
		printf("%d\n",qry(b)-qry(a-1));
	}
	scanf(" ");
}

